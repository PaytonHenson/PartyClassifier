//
//  Performance.hpp
//  ML
//
//  Created by Payton Henson on 12/6/17.
//  Copyright © 2017 Payton Henson. All rights reserved.
//

#ifndef Performance_hpp
#define Performance_hpp

#include <stdio.h>

class Performance {

private:
    double overall;
    double truePositive;
    double trueNegative;
    
public:
    Performance(double, double, double);
    void print();
    double getOverall() { return overall; };
};

#endif /* Performance_hpp */
