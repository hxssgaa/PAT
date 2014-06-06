//
//  main.cpp
//  PATA1053
//
/*
此题没什么可多说的，DFS算法即可
但是需要注意的是，最后的答案排序是根据每个非叶子节点的children的权值来排序的
*/
//  Created by Xin Huang on 5/26/14.
//  Copyright (c) 2014 David Huang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

// 0 < N <= 100, the number of nodes in a tree, M (< N), the number of non-leaf nodes, and 0 < S < 230, the given weight number.
// fix the root ID to be 00.
int N, M, S;

typedef struct nodeT{
    int id;
    int weight;
    vector<int> children;
}nodeT;

nodeT nodes[100];
int minumumWeight = 1000000;

void DFS(int id, int weight, vector<int> &weightPath) {
    if (weight > S) return;
    if (weight == S && nodes[id].children.size() == 0) {
        //found the S
        string resultStr;
        for (int eachWeight : weightPath) {
            stringstream ss;
            ss << eachWeight;
            resultStr += (ss.str() + " ");
        }
        resultStr = resultStr.substr(0, resultStr.length() - 1);
        cout << resultStr << endl;
        return;
    }
    for (int eachChild : nodes[id].children) {
        weightPath.push_back(nodes[eachChild].weight);
        DFS(eachChild, nodes[eachChild].weight + weight, weightPath);
        weightPath.pop_back();
    }
}

bool cmp(int a, int b) {
    return nodes[a].weight > nodes[b].weight;
}

int main(int argc, const char * argv[])
{
    cin >> N >> M >> S;
    int i, j, id, K, childID;
    for (i = 0; i < N; i++) {
        cin >> nodes[i].weight;
        nodes[i].id = i;
    }
    for (i = 0; i < M; i++) {
        cin >> id >> K;
        for (j = 0; j < K; j++) {
            cin >> childID;
            nodes[id].children.push_back(childID);
        }
        sort(nodes[id].children.begin(), nodes[id].children.end(), cmp);
    }
    vector<int> weightPath;
    nodeT root = nodes[0];
    weightPath.push_back(root.weight);
    DFS(0, root.weight, weightPath);
    return 0;
}

