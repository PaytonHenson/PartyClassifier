//
//  Cond.hpp
//  ML
//
//  Created by Payton Henson on 12/6/17.
//  Copyright © 2017 Payton Henson. All rights reserved.
//

#ifndef Cond_hpp
#define Cond_hpp

#include <stdio.h>

class Cond {

private:
    int issue;
    char vote;
    
public:
    Cond(int, char);
    int getIssue() const { return issue; };
    char getVote() const { return vote; };
};

#endif /* Cond_hpp */
