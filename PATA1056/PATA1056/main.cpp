//
//  main.cpp
//  PATA1056
//
/*
刚开始读不懂题，搞了半天不知道playingOrder的含义，以及怎么分组，说白了就是按顺序分组，剩下不足组数的自成一组，然后按组排序即可
 
 
 */
//  Created by Xin Huang on 5/28/14.
//  Copyright (c) 2014 David Huang. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

//NP and NG (<= 1000), the number of programmers and the maximum number of mice in a group
int Np, Ng;
//each Wi is the weight of the i-th mouse respectively
int W[1000];
//The third line gives the initial playing order which is a permutation of 0,...NP-1 (assume that the programmers are numbered from 0 to NP-1)
int playingOrder[1000];
int sortedW[1000];
int rankNum[1000];

vector<vector<int>> group;

int findFattest(vector<int> indexVec) {
    int best = sortedW[indexVec[0]];
    int bestI = indexVec[0];
    for (int i = 1; i < indexVec.size(); i++) {
        if (sortedW[indexVec[i]] > best) {
            best = sortedW[indexVec[i]];
            bestI = indexVec[i];
        }
    }
    return bestI;
}

void rankGroup(vector<vector<int>> &groupVec) {
    if (groupVec.size() == 1) {
        if (groupVec[0].size() == 1) {
            rankNum[playingOrder[groupVec[0][0]]] = 1;
            return;
        }
    }
    vector<vector<int>> nextGroup;
    vector<int> nextG;
    int count = 0;
    for (vector<int> eachGroup : groupVec) {
        if (count % Ng == 0) nextG.clear();
        int fattest = findFattest(eachGroup);
        for (int eachIndex : eachGroup) {
            if (fattest != eachIndex) {
                rankNum[playingOrder[eachIndex]] = (int)groupVec.size() + 1;
            }
        }
        nextG.push_back(fattest);
        if ((count + 1) % Ng == 0 || count == groupVec.size() - 1) nextGroup.push_back(nextG);
        count ++;
    }
    rankGroup(nextGroup);
}

int main(int argc, const char * argv[])
{
    scanf("%d%d", &Np, &Ng);
    int i;
    for (i = 0; i < Np; i++) {
        scanf("%d", &W[i]);
    }
    for (i = 0; i < Np; i++) {
        scanf("%d", &playingOrder[i]);
    }
    for (i = 0; i < Np; i++) {
        sortedW[i] = W[playingOrder[i]];
    }
    vector<int> g;
    for (i = 0; i < Np; i++) {
        if (i % Ng == 0) g.clear();
        g.push_back(i);
        if ((i + 1) % Ng == 0 || i == Np - 1) group.push_back(g);
    }
    rankGroup(group);
    for (i = 0; i < Np; i++) {
        i == Np - 1 ? printf("%d",rankNum[i]) : printf("%d ", rankNum[i]);
    }
    return 0;
}

