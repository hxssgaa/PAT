//
//  main.cpp
//  PATA1032
//
//  此题说明了，凡是N>=10^5以上，STL的map就不能用，只能用数组当做map
//  宁愿用大数组也不要用map，（我指的是对于N很大的情况下）
//  Created by Xin Huang on 5/10/14.
//  Copyright (c) 2014 David Huang. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main(int argc, const char * argv[])
{
    int s1, s2, N;
    char nodeMap[100000];
    int edgeMap[100000];
    bool visited[100000];
    memset(visited, 0, sizeof(visited));
    scanf("%d%d%d", &s1, &s2, &N);
    int id, nextID;
    char data;
    for (int i = 0; i < N; i++) {
        scanf("%d %c %d", &id, &data, &nextID);
        edgeMap[id] = nextID;
        nodeMap[id] = data;
    }
    int cur = s1;
    while (true) {
        if (cur == -1) break;
        visited[cur] = true;//visited 不要写到后面哦！！！
        cur = edgeMap[cur];
    }
    cur = s2;
    int commonAddr = -1;
    while (true) {
        if (cur == -1) break;
        if (visited[cur]) {
            commonAddr = cur;
            break;
        }
        cur = edgeMap[cur];
    }
    if (commonAddr == -1) printf("-1");
    else printf("%.5d", commonAddr);
    return 0;
}

