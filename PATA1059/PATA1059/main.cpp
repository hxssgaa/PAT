//
//  main.cpp
//  PATA1059
//
//  Created by Xin Huang on 6/6/14.
//  Copyright (c) 2014 David Huang. All rights reserved.
//

#include <iostream>
#include <map>
#include <math.h>

using namespace std;

bool isPrimeNumber(int num) {
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main(int argc, const char * argv[])
{
    long N;
    map<int, int> factor;
    scanf("%ld", &N);
    printf("%ld=", N);
    if (N <= 1) {
        printf("%ld", N);
        return 0;
    }
    while (N != 1) {
        for (int i = 2; i <= N; i++) {
            if (N % i == 0) {
                if (!isPrimeNumber(i)) continue;
                N /= i;
                factor[i] += 1;
                break;
            }
        }
    }
    bool flag = false;
    for (map<int, int>::iterator it = factor.begin(); it != factor.end(); ++it) {
        if (it->second > 1) {
            if (!flag) {
                printf("%d^%d", it->first, it->second);
                flag = true;
            } else {
                printf("*%d^%d", it->first, it->second);
            }
        } else {
            if (!flag) {
                printf("%d", it->first);
                flag = true;
            } else {
                printf("*%d", it->first);
            }
        }
    }
    return 0;
}

