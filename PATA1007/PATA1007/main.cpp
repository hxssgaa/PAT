//
//  main.cpp
//  PATA1007
//
/*  
6
-2 11 -4 13 -5 -2
 */
//
//  Created by Xin Huang on 4/22/14.
//  Copyright (c) 2014 David Huang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

#define MAX_NUMBER 10001

void findLargestSumSeq(int *number, int K) {
    int largestSum = -1, tempSum = 0;
    int tseqL = -1, tseqM = -1, seqL = -1, seqM = -1;
    bool flag = false;
    for (int i = 0; i < K; i++) {
        int num = number[i];
        tempSum += num;
        if (!flag) {
            tseqL = num;
            flag = true;
        }
        if (tempSum > largestSum) {
            tseqM = num;
            largestSum = tempSum;
            seqL = tseqL;
            seqM = tseqM;
        }
        if (tempSum < 0) {
            tempSum = 0;
            flag = false;
        }
    }
    largestSum >= 0 ? cout << largestSum << " " << seqL << " " << seqM
                    : cout << 0 << " " << number[0] << " " << number[K - 1];
}

int main(int argc, const char * argv[])
{
    int K;
    cin >> K;
    int num[MAX_NUMBER];
    for (int i = 0; i < K; i++) {
        cin >> num[i];
    }
    findLargestSumSeq(num, K);
    return 0;
}

