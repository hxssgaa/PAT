//
//  main.cpp
//  PATA1054
//
// A strictly dominant color takes more than half of the total area.
//  Created by Xin Huang on 5/26/14.
//  Copyright (c) 2014 David Huang. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>

using namespace std;

int main(int argc, const char * argv[])
{
    int N, M;
    scanf("%d%d", &N, &M);
    map<int, int> countMap;
    int num;
    int dominantColor = -1;
    int highestCount = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &num);
            countMap[num] += 1;
            if (countMap[num] > highestCount) {
                dominantColor = num;
                highestCount = countMap[num];
            }
        }
    }
    printf("%d", dominantColor);
    return 0;
}

