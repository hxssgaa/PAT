//
//  main.cpp
//  PATA1048
//
//  此题注意几点：
//  1.10^5 是100000喔，别写成10000了
//  2.注意二分法可用binary_search来查找，注意binary_search的用法
//  Created by Xin Huang on 5/22/14.
//  Copyright (c) 2014 David Huang. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int N, M;//N (<=10^5, the total number of coins) and M(<=10^3, the amount of money Eva has to pay).
int faceValue[100000];

void findTwoCoins() {
    int i;
    int temp = 0;
    for (i = 0; i < N; i++) {
        temp = faceValue[i];
        //this is how we use binary search in STL to return the iterator equal to the find value.
        //relavant methods are: lower_bound, upper_bound, binary_search(which only return true when found or false not found)
        pair<int *, int *> p = equal_range(faceValue + i + 1, faceValue + N, M - temp);
        if (p.first != p.second) {
            printf("%d %d", temp, p.first[0]);
            return;
        }
    }
    printf("No Solution");
}

bool cmpFaceValue(int a, int b) {
    return a < b;
}

int main(int argc, const char * argv[])
{
    scanf("%d%d", &N, &M);
    for (int i = 0;i < N; i++) {
        scanf("%d", &faceValue[i]);
    }
    sort(faceValue, faceValue + N, cmpFaceValue);
    findTwoCoins();
    return 0;
}

