//
//  main.cpp
//  ML
//
//  Created by Payton Henson on 12/6/17.
//  Copyright © 2017 Payton Henson. All rights reserved.
//

#include "Example.hpp"
#include "DataSet.hpp"
#include "RuleSet.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <time.h>

using std::vector;
using std::string;
using std::ifstream;
using std::cout;
using std::endl;

RuleSet irep(DataSet);

int main(int argc, const char * argv[]) {
    
    //seed random number generator
    srand(time(0));
    
    const string filePath = "./votes-comments.txt";
    
    //load data from file
    DataSet data;
    data.load(filePath);
    
    vector<Performance> stats;
    
    for (int i = 0; i < 5; i++) {
        
        //split our data using holdout method
        vector<DataSet> splitData = data.split(0.75);
        DataSet train = splitData[0];
        DataSet test = splitData[1];
        
        //run IREP on training data
        RuleSet rules = irep(train);
        
        //evaluate the rules on test data
        Performance p = rules.evaluate(test);
        
        //print the stats for that RuleSet
        cout << "Round: " << i + 1 << endl;
        p.print();
        cout << endl;
        
        stats.push_back(p);
    }
    
    //calculate final overall accuracy below
    double sum = 0.0;
    
    for (int i = 0; i < stats.size(); i++) {
        sum += stats[i].getOverall();
    }
    
    double averageAccuracy = sum / stats.size();
    
    cout << "{\"Average Accuracy\": " << averageAccuracy << "}" << endl;
    
    cout << endl;
    
    return 0;
}

RuleSet irep(DataSet t) {
    
    vector<Example> growPos = t.getPos();
    vector<Example> growNeg = t.getNeg();
    
    RuleSet rules;
    
    while(!growPos.empty()) {
        
        Rule r;
        r.grow(growPos, growNeg);
        
        int correctPredictions = growNeg.size();
        
        for (int i = 0; i < growPos.size(); i++) {
            if (r.match(growPos[i])) {
                correctPredictions++;
            }
        }
        
        double accuracy = correctPredictions / (double)(growPos.size() + growNeg.size());
        
        if (accuracy <= 0.5) {
            return rules;
        }
        
        else {
            //add rule to rule set
            rules.addRule(r);
            //remove examples from GrowPos that are covered by this rule
            for (int i = 0; i < growPos.size(); i++) {
                if (r.match(growPos[i])) {
                    growPos.erase(growPos.begin() + i);
                }
            }
        }
    }
    
    return rules;
    
}


