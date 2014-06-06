//
//  main.cpp
//  PATA1041
//
//  Created by Xin Huang on 5/16/14.
//  Copyright (c) 2014 David Huang. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int N;
int uniqueMap[100000];
int lottery[100000];

int main(int argc, const char * argv[])
{
    scanf("%d",&N);
    memset(uniqueMap, 0, sizeof(uniqueMap));
    for (int i = 0; i < N; i++) {
        scanf("%d", &lottery[i]);
        uniqueMap[lottery[i]]++;
    }
    bool flag = 0;
    for (int i = 0; i < N; i++) {
        if (uniqueMap[lottery[i]] == 1) {
            flag = 1;
            printf("%d", lottery[i]);
            break;
        }
    }
    if (!flag) printf("None");
    return 0;
}

