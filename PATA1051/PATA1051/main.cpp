//
//  main.cpp
//  PATA1051
//
//  Created by Xin Huang on 5/24/14.
//  Copyright (c) 2014 David Huang. All rights reserved.
/*
5 7 1
5 6 4 3 7 2 1
 
 */
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;

int N, M, K;

int popSequence[10001];
stack<int> original;
int cur = 0;

bool isPossiblePopSeq() {
    for (int i = 1; i <= N; i++) {
        int seqi = popSequence[i];
        if (seqi > N) return false;
        if (seqi >= cur) {
            int j = cur + 1;
            for (;j <= seqi; j++) {
                original.push(j);
            }
            if (original.size() > M || original.empty())
                return false;
            original.pop();
            cur = seqi;
        } else {
            if (original.empty())
                return false;
            int top = original.top();
            if (top != seqi) return false;
            original.pop();
        }
    }
    return true;
}

int main(int argc, const char * argv[])
{
    //M (the maximum capacity of the stack), N (the length of push sequence), and K (the number of pop sequences to be checked).
    scanf("%d%d%d", &M, &N, &K);
    int i, j;
    for (i = 0; i < K; i++) {
        for (j = 1; j <= N; j++) {
            scanf("%d", &popSequence[j]);
        }
        while (!original.empty()) original.pop();
        cur = 0;
        printf("%s\n", isPossiblePopSeq() ? "YES" : "NO");
    }
    return 0;
}

