//
//  main.cpp
//  PATA1063
//
//  求两集合的交集和并集
//    !!!!!!!!!  sets[set1]地方令我及其惊讶，竟然不去寻址set而直接用数组代替寻址快了N倍!!!!!!!!!!!!!!
//  以后对于大数据的set提取不要取出来，直接数组寻址就可以了
//  Created by Xin Huang on 6/8/14.
//  Copyright (c) 2014 David Huang. All rights reserved.
//

#include <iostream>
#include <set>
#include <map>
#include <algorithm> //set_union函数（在求交集和并集的时候别忘了include 这两个包）
#include <iterator> //inserter函数
using namespace std;

int N;
set<long> *sets;

void querySet(int set1, int set2) {
    set<long> intersectionSet;
    //注意这里不用求并集，并集可以直接计算得出
    //!!!!!!!!!这个地方令我及其惊讶，竟然不去寻址set而直接用数组代替寻址快了N倍!!!!!!!!!!!!!!
    set_intersection(sets[set1].begin(), sets[set1].end(), sets[set2].begin(), sets[set2].end(), inserter(intersectionSet, intersectionSet.begin()));
    printf("%.1f%%\n", (float)intersectionSet.size() * 100 / (sets[set1].size() + sets[set2].size() - intersectionSet.size()));
    
    //直接求交集也不错
//    int total = (int)(sets[set1].size() + sets[set2].size());
//    int intersectionNum = 0;
//    for (long eachNum : sets[set2]) {
//        if (sets[set1].find(eachNum) != sets[set1].end()) {
//            intersectionNum++;
//        }
//    }
//    printf("%.1f%%\n", (float)intersectionNum * 100 / (total - intersectionNum));
}

int main(int argc, const char * argv[])
{
//    freopen("/Users/hxssg1124/Documents/August13Programming/PAT/PATA1063/PATA1063/in.txt", "r", stdin);
    scanf("%d", &N);
    sets = new set<long>[N + 1];
    int M, K;
    long num;
    for (int i = 1; i <= N; i++) {
        scanf("%d", &M);
        for (int j = 0; j < M; j++) {
            scanf("%ld", &num);
            sets[i].insert(num);
        }
    }
    scanf("%d", &K);
    int set1, set2;
    for (int i = 0; i < K; i++) {
        scanf("%d%d",&set1, &set2);
        querySet(set1, set2);
    }
//    fclose(stdin);
    return 0;
}

