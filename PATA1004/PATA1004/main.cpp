//
//  main.cpp
//  PATA1004
//
/*
 A family hierarchy is usually presented by a pedigree tree. Your job is to count those family members who have no child.
 
 --------------------Input--------------------
 Each input file contains one test case. Each case starts with a line containing 0 < N < 100, the number of nodes in a tree, and M (< N), the number of non-leaf nodes. Then M lines follow, each in the format:
 
 ID K ID[1] ID[2] ... ID[K]
 where ID is a two-digit number representing a given non-leaf node, K is the number of its children, followed by a sequence of two-digit ID's of its children. For the sake of simplicity, let us fix the root ID to be 01.
 
 --------------------Output--------------------
 For each test case, you are supposed to count those family members who have no child for every seniority level starting from the root. The numbers must be printed in a line, separated by a space, and there must be no extra space at the end of each line.
 
 The sample case represents a tree with only 2 nodes, where 01 is the root and 02 is its only child. Hence on the root 01 level, there is 0 leaf node; and on the next level, there is 1 leaf node. Then we should output "0 1" in a line.
 
 --------------------Sample Input--------------------
2 1
01 1 02
 
7 3
01 2 02 03
02 2 04 05
03 2 06 07
 
 --------------------Sample Output--------------------
0 1
 */
//  Created by Xin Huang on 4/18/14.
//  Copyright (c) 2014 David Huang. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>

#define NODE_MAX 101

using namespace std;

typedef struct nodeT{
    int id;
    vector<nodeT *> children;
}nodeT;

//count the leaf node from the L layer of the tree. store each layer's leaf node count into a vector.
void countLeafNode(nodeT *root, int L, vector<int> &count) {
    int leafNodeCount = 0;
    for (nodeT *child : root->children) {
        if (child->children.size() != 0) {
            continue;
        } else {
            leafNodeCount ++;
        }
    }
    if (count.size() > L) {
        count[L] += leafNodeCount;
    } else {
        count.push_back(leafNodeCount);
    }
    for (nodeT *child : root->children) {
        if (child->children.size() != 0) {
            countLeafNode(child, L + 1, count);
        }
    }
}

int main(int argc, const char * argv[])
{
    int N, M;
    cin >> N >> M;
    int nonLeafID, childID, K;
    map<int, vector<int> >childrenMap;
    
    // The simple method to map the id of the node to the actual node.
    // This is rather useful when you don't know all the info about the node, while you can use it afterwards.
    map<int, nodeT *> nodeMap;
    for (int i = 0;i < M;i++) {
        cin >> nonLeafID >> K;
        vector<int> children;
        if (nodeMap.find(nonLeafID) == nodeMap.end()) {
            nodeT *newNode = new nodeT;
            newNode->id = nonLeafID;
            nodeMap.insert(pair<int, nodeT *>(nonLeafID, newNode));
        }
        for (int j = 0; j < K; j++) {
            cin >> childID;
            children.push_back(childID);
            if (nodeMap.find(childID) == nodeMap.end()) {
                nodeT *newNode = new nodeT;
                newNode->id = childID;
                nodeMap.insert(pair<int, nodeT *>(childID, newNode));
            }
        }
        childrenMap.insert(pair<int, vector<int> >(nonLeafID, children));
    }
    
    nodeT *rootNode = NULL;
    
    // iterate each node and its' children, build the tree.
    for (map<int, vector<int> > :: iterator it = childrenMap.begin(); it != childrenMap.end(); ++it) {
        nodeT *node = nodeMap[it->first];
        if (node->id == 1) rootNode = node;
        for (int eachChildrenID : it->second) {
            nodeT *childNode = nodeMap[eachChildrenID];
            node->children.push_back(childNode);
        }
    }
    
    // check if N == 1, if there is 1 node, then we don't need to count the children code.
    if (N == 1) {
        cout << 1;
        return 0;
    }
    
    vector<int> count;
    countLeafNode(rootNode, 0, count);
    cout << 0;
    for (int i = 0; i < count.size(); i++) {
        cout << " " << count[i];
    }
    return 0;
}


