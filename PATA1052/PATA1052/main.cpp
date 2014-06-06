//
//  main.cpp
//  PATA1052
//
/*
此题属于比较考细节的题目: 但是基本来说，学会利用nodeMap可以事半功倍
细节：
1.开始地址很可能是-1，需要特殊处理
2.一定注意，地址的输出都是5位数处理,(%.5d)
3.注意nodeMap很可能会next到未知的区域，所以在nodeT里面加上isDefined可以判断该节点是否是定义的有效节点，push_back的必须是有效节点
 
 */
//  Created by Xin Huang on 5/25/14.
//  Copyright (c) 2014 David Huang. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct nodeT{
    int key;
    int addr;
    int nextAddr;
    bool isDefined;
    nodeT(){isDefined = false;}
}nodeT;

int N, startAddr;
nodeT nodeMap[100000];

void printNodes(vector<nodeT> &vec) {
    printf("%ld %.5d\n", vec.size(), vec[0].addr);
    int i;
    for (i = 0; i < vec.size() - 1; i++) {
         printf("%05d %d %05d\n",vec[i].addr,vec[i].key,vec[i].nextAddr);
    }
    printf("%05d %d -1\n",vec[i].addr,vec[i].key);
}

void getVec(nodeT head, vector<nodeT> &vec) {
    while (head.nextAddr != -1 && head.isDefined) {
        vec.push_back(head);
        head = nodeMap[head.nextAddr];
    }
    if (head.isDefined)
        vec.push_back(head);
}

bool cmp(nodeT n1, nodeT n2) {
    return n1.key < n2.key;
}

int main(int argc, const char * argv[])
{
    scanf("%d%d", &N, &startAddr);
    int addr, key, nextAddr;
    for (int i = 0; i < N; i++) {
        scanf("%d%d%d", &addr, &key, &nextAddr);
        nodeMap[addr].key = key;
        nodeMap[addr].addr = addr;
        nodeMap[addr].nextAddr = nextAddr;
        nodeMap[addr].isDefined = true;
    }
    if (startAddr == -1) {
        printf("0 -1\n");
        return 0;
    }
    vector<nodeT> vec;
    
    int curAddress = startAddr;
    while(curAddress > 0 && nodeMap[curAddress].isDefined)
    {
        vec.push_back(nodeMap[curAddress]);
        if(nodeMap[curAddress].nextAddr == -1) break;
        else
            curAddress = nodeMap[curAddress].nextAddr;
    }
    sort(vec.begin(), vec.end(), cmp);
    for(int i=0; i < vec.size()-1 ; i++)
        vec[i].nextAddr = vec[i+1].addr;
    printNodes(vec);
    return 0;
}

