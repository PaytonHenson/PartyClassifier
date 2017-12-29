//
//  RuleSet.cpp
//  ML
//
//  Created by Payton Henson on 12/6/17.
//  Copyright © 2017 Payton Henson. All rights reserved.
//

#include "RuleSet.hpp"

Performance RuleSet::evaluate(DataSet t) {
    
    vector<Example> pos = t.getPos();
    vector<Example> neg = t.getNeg();
    
    int correctPos = 0;
    int correctNeg = 0;
    
    for (int i = 0; i < pos.size(); i++) {
        if (match(pos[i])) {
            correctPos++;
        }
    }
    
    for (int i = 0; i < neg.size(); i++) {
        if (!match(neg[i])) {
            correctNeg++;
        }
    }
    
    double accuracy = (correctPos + correctNeg) / (double)(pos.size() + neg.size());
    
    double truePos = correctPos / (double)(pos.size());
    
    double trueNeg = correctNeg / (double)(neg.size());
    
    Performance p = Performance(accuracy, truePos, trueNeg);
    
    return p;
    
}

bool RuleSet::match(Example e) {
    
    for (int i = 0; i < rules.size(); i++) {
        if (rules[i].match(e)) {
            return true;
        }
    }
    return false;
}
