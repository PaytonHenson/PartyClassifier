//
//  DataSet.cpp
//  ML
//
//  Created by Payton Henson on 12/6/17.
//  Copyright © 2017 Payton Henson. All rights reserved.
//

#include "DataSet.hpp"
#include "Example.hpp"

#include <vector>
#include <fstream>
#include <iostream>
#include <stdlib.h>

using std::vector;
using std::ifstream;
using std::cout;
using std::endl;

void DataSet::load(string filePath) {
    
    ifstream dataFile (filePath.c_str());
    vector<string> issues;
    string line;
    
    if (dataFile.is_open()) {
        
        //first get issues
        while (getline(dataFile, line)) {
            if (line.empty()) {
                break;
            }
            else {
                issues.push_back(line);
            }
        }
        
        //next get Dem examples
        while (getline(dataFile, line)) {
            if (line.empty()) {
                break;
            }
            else {
                Example negExample;
                for (int i = 0; i < line.length(); i += 2) {
                    negExample.addVote(line[i]);
                }
                addNeg(negExample);
            }
        }
        
        //next get Rep examples
        while (getline(dataFile, line)) {
            Example posExample;
            for (int i = 0; i < line.length(); i+= 2) {
                posExample.addVote(line[i]);
            }
            addPos(posExample);
        }
        dataFile.close();
    }
    else {
        cout << "unable to open file..." << endl;
    }
}


vector<DataSet> DataSet::split(double trainingPerc) {
    
    DataSet train, test;
    
    for (int i = 0; i < pos.size(); i++) {
        double r = ((double) rand() / (RAND_MAX));
        if (r < trainingPerc) {
            train.addPos(pos[i]);
        }
        else {
            test.addPos(pos[i]);
        }
    }
    
    for (int i = 0; i < neg.size(); i++) {
        double r = ((double) rand() / (RAND_MAX));
        if (r < trainingPerc) {
            train.addNeg(neg[i]);
        }
        else {
            test.addNeg(neg[i]);
        }
    }
    
    vector<DataSet> answer;
    answer.push_back(train);
    answer.push_back(test);
    return answer;
}












