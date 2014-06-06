//
//  main.cpp
//  PATA1010
//
//  二分查找
//
//  Created by Xin Huang on 4/24/14.
//  Copyright (c) 2014 David Huang. All rights reserved.
//

#include <iostream>
#include <math.h>

using namespace std;

double getRealValue(string N, int radix) {
    double realValue = 0;
    for (int i = (int)N.length() - 1; i >= 0; i--) {
        char ch = N[i];
        realValue += (double)(ch >= 'a' ? ch - 'a' + 10 : ch - '0') * pow(radix, N.length() - 1 - i);
    }
    return realValue;
}

int tryRadix(string N, double compare) {
    for (int i = 2; i < 100000; i++) {
        double value = getRealValue(N, i);
        if (value == compare) {
            return i;
        } else if (value > compare) {
            return -1;
        }
    }
    return -1;
}

int main(int argc, const char * argv[])
{
    string N1, N2;
    int tag, radix;
    cin >> N1 >> N2 >> tag >> radix;
    string realStr = tag == 1 ? N1 : N2;
    string other = tag == 1 ? N2 : N1;
    double realValue = getRealValue(realStr, radix);
    int solveRadix = tryRadix(other, realValue);
    solveRadix == -1 ? cout << "Impossible" : cout << solveRadix;
    return 0;
}

