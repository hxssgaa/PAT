//
//  main.cpp
//  PATA1055
//
//  Created by Xin Huang on 5/27/14.
//  Copyright (c) 2014 David Huang. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>

using namespace std;

typedef struct personT{
    char name[9];
    int age;
    int worth;
}personT;

int N, K;// N (<=10^5) - the total number of people, and K (<=10^3) - the number of queries

map<int, vector<int>> ageMap;

personT persons[100000];

bool cmp(personT p1, personT p2) {
    if (p1.worth == p2.worth) {
        if (p1.age != p2.age)
            return p1.age < p2.age;
        else
            return strcmp(p1.name, p2.name) < 0;
    }
    return p1.worth > p2.worth;
}

//这里有两种优化算法，其中第一种是线性查找，适用于年龄跨度比较大的情况
//第二种是从年龄开始遍历到年龄结束这样的查找，适用于年龄跨度比较小的情况
//两种算法融合在一起就顺利AC了，呵呵....
void findRichest(int caseNum, int maximumOutputs, int Amin, int Amax, int version) {
    printf("Case #%d:\n", caseNum);
    int findCount = 0;
    if (version == 0) {
        personT p;
        for (int i = 0; i < N; i++) {
            if (findCount >= maximumOutputs || findCount > 100) break;
            p = persons[i];
            if (p.age >= Amin && p.age <= Amax) {
                printf("%s %d %d\n", p.name, p.age, p.worth);
                findCount++;
            }
        }
    }
    else {
        int cur = Amin;
        vector<personT> result;
        while (cur <= Amax) {
            if (ageMap.find(cur) == ageMap.end()) {
                cur++;
                continue;
            }
            vector<int> vec = ageMap[cur];
            if (vec.size() == 0) {
                cur ++;
                continue;
            }
            for (int pI : vec) {
                personT p = persons[pI];
                if (p.age >= Amin && p.age <= Amax) {
                    result.push_back(p);
                }
            }
            cur++;
        }
        sort(result.begin(), result.end(), cmp);
        for (personT p : result) {
            if (findCount >= maximumOutputs) break;
            printf("%s %d %d\n", p.name, p.age, p.worth);
            findCount ++;
        }
    }
    if (findCount == 0) {
        printf("None\n");
    }
}

int main(int argc, const char * argv[])
{
    scanf("%d%d", &N, &K);
    int i;
    for (i = 0; i < N; i++) {
        scanf("%s%d%d", persons[i].name, &persons[i].age, &persons[i].worth);
    }
    sort(persons, persons + N, cmp);
    
    for (i = 0; i < N; i++) {
        ageMap[persons[i].age].push_back(i);
    }
    
    //M (<= 100) - the maximum number of outputs, and [Amin, Amax] which are the range of ages
    int M, Amin, Amax;
    for (i = 1; i <= K; i++) {
        scanf("%d%d%d", &M, &Amin, &Amax);
        findRichest(i, M, Amin, Amax, (Amax - Amin > 50 ? 0 : 1));
    }
    return 0;
}

