//
//  Rule.hpp
//  ML
//
//  Created by Payton Henson on 12/6/17.
//  Copyright © 2017 Payton Henson. All rights reserved.
//

#ifndef Rule_hpp
#define Rule_hpp

#include "Cond.hpp"
#include "Example.hpp"

#include <stdio.h>
#include <vector>

using std::vector;

class Rule {

private:
    vector<Cond> conditions;
    
public:
    void addCond(Cond c) { conditions.push_back(c); };
    void deleteLastCond() { conditions.pop_back(); };
    vector<Cond> getConditions() { return conditions; };
    void grow(vector<Example>, vector<Example>);
    double gain(int, int, int, int);
    bool match(Example);
    int countMatches(vector<Example>);
};

#endif /* Rule_hpp */
