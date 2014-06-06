//
//  main.cpp
//  PATA1015
//
/*
 Reversible Primes
 此题注意几点：
 1.当判断负数退出时，需要之前break而不是输出之后break
 2.对于涉及D进制的转换，一定要先将数转换为D进制数，作相反变化后，然后再转化为10进制数，注意输入的数据是10进制数
 */
//  Created by Xin Huang on 4/29/14.
//  Copyright (c) 2014 David Huang. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <cstdio>
#include <cstring>
#include <sstream>

using namespace std;

bool isPrime(int N) {
    if (N <= 1) return false;
    if (N == 2) return true;
    for (int i = 2; i <= sqrt(N); i++) {
        if (N % i == 0) {
            return false;
        }
    }
    return true;
}

int realNumber(string N, int D) {
    int value = 0;
    for (int i = (int)N.size() - 1; i >= 0; i--) {
        int num = N[i] - '0';
        value += num * pow(D, (int)N.size() - i - 1);
    }
    return value;
}

string toDFormatNumber(int N, int D) {
    string s = "";
    while (true) {
        char ch = N % D + '0';
        s = ch + s;
        N /= D;
        if (N == 0) {
            return s;
        }
    }
}

bool isReversiblePrime(int N, int D) {
    string Dformat = toDFormatNumber(N, D);
    string reverseStr = "";
    for (char ch : Dformat) {
        reverseStr = ch + reverseStr;
    }
    //切记这里是Dformat而非N
    return isPrime(N) && isPrime(realNumber(reverseStr, D));
}

int main(int argc, const char * argv[])
{
    //two positive integers N (< 105) and D (1 < D <= 10)
    int N, D;
    while (cin >> N) {
        if (N < 0) {//注意这点小细节，需要在之前break
            break;
        }
        cin >> D;
        isReversiblePrime(N, D) ? printf("Yes\n") : printf("No\n");
    }
    return 0;
}

