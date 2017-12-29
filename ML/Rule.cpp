//
//  Rule.cpp
//  ML
//
//  Created by Payton Henson on 12/6/17.
//  Copyright © 2017 Payton Henson. All rights reserved.
//

#include "Rule.hpp"

#include <math.h>
#include <iostream>
#include <limits>

void Rule::grow(vector<Example> pos, vector<Example> neg) {
    
    int p0 = pos.size();
    int n0 = neg.size();
    
    vector<char> waysToVote;
    waysToVote.push_back('y');
    waysToVote.push_back('n');
    waysToVote.push_back('u');
    
    double bestScoreYet = - std::numeric_limits<double>::infinity();
    Cond bestCondYet = Cond(-1, 'x');

    //the rule starts off empty, which explains the do..while construct
    do {
        
        //figure out which is the best condition to add
        for (int i = 0; i < 16; i++) {
            
            for (int j = 0; j < 3; j++) {
                
                Cond c = Cond(i, waysToVote[j]);
                
                addCond(c);
                
                int p1 = countMatches(pos);
                int n1 = countMatches(neg);
                
                double score = gain(p0, n0, p1, n1);
                
                if (score > bestScoreYet) {
                    bestScoreYet = score;
                    bestCondYet = c;
                }
                
                deleteLastCond();
            }
        }
        
        addCond(bestCondYet);
        
        p0 = countMatches(pos);
        n0 = countMatches(neg);
        
        bestScoreYet = - std::numeric_limits<double>::infinity();
        
    } while (countMatches(neg) > 0);
}

double Rule::gain(int p0, int n0, int p1, int n1) {
    double a = ((p1 + 1) / (double)(p1 + n1 + 1));
    double b = ((p0 + 1) / (double)(p0 + n0 + 1));
    return p1 * (log2(a) - log2(b));
}

bool Rule::match(Example e) {
    for (int i = 0; i < conditions.size(); i++) {
        int issue = conditions[i].getIssue();
        if (e.getVotes()[issue] != conditions[i].getVote()) {
            return false;
        }
    }
    return true;
}

int Rule::countMatches(vector<Example> exs) {
    int count = 0;
    for (int i = 0; i < exs.size(); i++) {
        if (match(exs[i])) {
            count++;
        }
    }
    return count;
}




