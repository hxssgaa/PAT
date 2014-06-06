//
//  main.cpp
//  PATA1047
//
//  此题注意，当课程数为0的时候也需要显示喔~~~，注意下最后一个case真的好险....差点超时...
//  Hash算法可以大大减少内存使用喔...，主要是因为利用数组代替了map
//  Created by Xin Huang on 5/21/14.
//  Copyright (c) 2014 David Huang. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

int N, K;

#define FOREACH(i,N)  for (i = 0; i < (N); i++)

int hashName(char *name) {
    return (name[0] << 24) + (name[1] << 16) + (name[2] << 8) + name[3];
}


bool compareStr(int s1, int s2) {
    return s1 < s2;
}

int main(int argc, const char * argv[])
{
    scanf("%d%d", &N, &K);
    int i, j;
    char *name;
    int C, courseIndex;
    vector<int> courseMap[2501];
    FOREACH(i, N) {
        name = new char[5];
        scanf("%s", name);
        scanf("%d", &C);
        FOREACH(j, C) {
            scanf("%d", &courseIndex);
            courseMap[courseIndex].push_back(hashName(name));
        }
    }
    FOREACH(i, K) {
        vector<int> vec = courseMap[i + 1];
        sort(vec.begin(), vec.end(), compareStr);
        printf("%d %ld\n", i + 1, vec.size());
        for (int eachHash : vec) {
            printf("%c%c%c%c\n",
                                (eachHash & (0xff000000)) >> 24,
                                (eachHash & (0x00ff0000)) >> 16,
                                (eachHash & (0x0000ff00)) >> 8,
                                (eachHash & (0x000000ff)));
        }
    }
    return 0;
}

