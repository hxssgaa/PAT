//
//  main.cpp
//  PATA1044
//
//  此题采用优化算法，即算过的不用再算，是一个子集问题，这题做的还不错，^_^
//  Created by Xin Huang on 5/19/14.
//  Copyright (c) 2014 David Huang. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

//#define REP(i,n) for(int i=0;i<(n);++i)  //不错的宏

//#define FOREACH(i, s, N)  for(int i=s;i<(N);i++) //不错的宏

using namespace std;

int N;
long M;

int values[100001];

void search() {
    int i = 0, j = -1;
    long sum = 0, minimisedSum = 100000000;
    vector<pair<int, int> >vec;
    bool flag = 0;
    for (i = 1; i <= N; i++) {
        if (j < i) {
            sum = 0;
            j = i;
        } else {
            sum -= values[i - 1];
            j++;
        }
        for (; j <= N; j++) {
            sum += values[j];
            if (sum == M) {
                printf("%d-%d\n", i,j);
                flag = 1;
                break;
            }
            if (sum > M && !flag) {
                if (sum < minimisedSum) {
                    vec.clear();
                    vec.push_back(pair<int, int>(i,j));
                    minimisedSum = sum;
                } else if (sum == minimisedSum) {
                    vec.push_back(pair<int, int>(i,j));
                }
                sum -= values[j];
                j--;
                break;
            }
            if (sum > M) {
                sum -= values[j];
                j--;
                break;
            }
        }
    }
    if (!flag) {
        for (pair<int, int> p : vec) {
            printf("%d-%d\n",p.first,p.second);
        }
    }
}

int main(int argc, const char * argv[])
{
    scanf("%d %ld", &N, &M);
    int i;
    for (i = 1; i <= N; i++) {
        scanf("%d", &values[i]);
    }
    search();
    return 0;
}

