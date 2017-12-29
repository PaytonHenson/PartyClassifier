//
//  Example.hpp
//  ML
//
//  Created by Payton Henson on 12/6/17.
//  Copyright © 2017 Payton Henson. All rights reserved.
//

#ifndef Example_hpp
#define Example_hpp

#include <stdio.h>
#include <vector>

using std::vector;

class Example {

private:
    vector<char> votes;
    
public:
    void addVote(char c) { votes.push_back(c); };
    vector<char> getVotes() { return votes; };
};

#endif /* Example_hpp */
