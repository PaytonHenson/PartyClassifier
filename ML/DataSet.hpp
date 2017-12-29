//
//  DataSet.hpp
//  ML
//
//  Created by Payton Henson on 12/6/17.
//  Copyright © 2017 Payton Henson. All rights reserved.
//

#ifndef DataSet_hpp
#define DataSet_hpp

#include "Example.hpp"

#include <stdio.h>
#include <vector>
#include <string>

using std::vector;
using std::string;

class DataSet {

private:
    vector<Example> pos;
    vector<Example> neg;
public:
    void addPos(Example p) { pos.push_back(p); };
    void addNeg(Example n) { neg.push_back(n); };
    vector<Example> getPos() { return pos; };
    vector<Example> getNeg() { return neg; };
    void load(string);
    vector<DataSet> split(double);
};

#endif /* DataSet_hpp */
