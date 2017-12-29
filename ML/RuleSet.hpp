//
//  RuleSet.hpp
//  ML
//
//  Created by Payton Henson on 12/6/17.
//  Copyright © 2017 Payton Henson. All rights reserved.
//

#ifndef RuleSet_hpp
#define RuleSet_hpp

#include "Rule.hpp"
#include "Performance.hpp"
#include "DataSet.hpp"

#include <stdio.h>
#include <vector>

using std::vector;

class RuleSet {
    
private:
    vector<Rule> rules;
    
public:
    void addRule(Rule r) { rules.push_back(r); };
    vector<Rule> getRules() { return rules; };
    Performance evaluate(DataSet);
    bool match(Example);
};

#endif /* RuleSet_hpp */
