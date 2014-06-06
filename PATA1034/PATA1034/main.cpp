//
//  main.cpp
//  PATA1034
//
//  1.此题需要非常的注意，特别是string的邻接表可用map<string, vector<>>来表示，其余的参数也可以用map表示，这样简单得多
//  2.而且特别注意map的使用，这里没用insert貌似也可以
//  3.此题其实属于简单题目，但须掌握透彻
//  4.而且map可以自动sort,对于需要排序的题目，真的要考虑map，但是也不能滥用
//  5.这里的weight其实是这个人所有weight的总和，因此再dfs时 totalWeight / 2 就是这个帮会的weight.
//
//  Created by Xin Huang on 5/10/14.
//  Copyright (c) 2014 David Huang. All rights reserved.
//

#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>

using namespace std;

map<string, vector<string>> adj; //邻接表
map<string, int> weight; //各个person的权重
map<string, bool> visit;
map<string, int> result; //结果
int cnt, totalWeight;
string head;


void dfs(string str) {
    visit[str] = 1;
    cnt ++;
    totalWeight += weight[str];
    if (weight[str] > weight[head])
        head = str;
    for (vector<string>::iterator it=adj[str].begin();it != adj[str].end(); ++it) {
        if (visit[*it] == 0)
            dfs(*it);
    }
}

int main() {
    int n, k, time, i;
    string name1, name2;
    cin >> n >> k;
    for (i = 0;i < n;i++) {
        cin >> name1 >> name2 >> time;
        weight[name1] += time;
        weight[name2] += time;
        adj[name1].push_back(name2);
        adj[name2].push_back(name1);
        visit[name1] = 0;
        visit[name2] = 0;
    }
    for (map<string, bool>::iterator it = visit.begin(); it != visit.end(); ++it) {
        if (it->second == 0) {
            cnt = 0;
            totalWeight = 0;
            head = it->first;
            dfs(head);
            if (cnt > 2 && totalWeight / 2 > k) {
                result[head] = cnt;
            }
        }
    }
    cout << result.size() << endl;
    for (map<string, int>::iterator it = result.begin(); it != result.end(); ++it) {
        cout << it->first << " " << it->second << endl;
    }
}

