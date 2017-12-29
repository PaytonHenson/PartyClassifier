//
//  Performance.cpp
//  ML
//
//  Created by Payton Henson on 12/6/17.
//  Copyright © 2017 Payton Henson. All rights reserved.
//

#include "Performance.hpp"

#include <iostream>

using std::cout;
using std::endl;

Performance::Performance(double ov, double tp, double tn) {
    overall = ov;
    truePositive = tp;
    trueNegative = tn;
}

void Performance::print() {
    cout << "Overall Accuracy: " << overall << endl;
    cout << "True-Positive Rate: " << truePositive << endl;
    cout << "True-Negative Rate: " << trueNegative << endl;
}
