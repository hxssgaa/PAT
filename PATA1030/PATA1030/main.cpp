//
//  main.cpp
//  PATA1030
//
//  Created by Xin Huang on 5/9/14.
//  Copyright (c) 2014 David Huang. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <vector>

int N, M, S, D;

using namespace std;

#define MAX 500

int graph[MAX][MAX];
int cost[MAX][MAX];

bool visited[MAX];

int minimumCost = 99999999;
int minimumDistance = 99999999;
vector<int> minimumRoute;

void init() {
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            graph[i][j] = -1;
            cost[i][j] = -1;
        }
    }
}

void dfs(int start, int end, int distance, int c, vector<int> &route) {
    if (start == end) {
        if (distance < minimumDistance) {
            minimumDistance = distance;
            minimumCost = c;
            minimumRoute = route;
        } else if (distance == minimumDistance) {
            if (c < minimumCost) {
                minimumCost = c;
                minimumRoute = route;
            }
        }
        return;
    }
    for (int i = 0; i < N; i++) {
        if (visited[i]) continue;
        int dis = graph[i][start];
        int cos = cost[i][start];
        if (dis > 0) {
            visited[i] = true;
            route.push_back(i);
            dfs(i, end, distance + dis, c + cos, route);
            route.pop_back();
            visited[i] = false;
        }
    }
}

int main(int argc, const char * argv[])
{
    init();
    //N, M, S, and D, where N (<=500) is the number of cities (and hence the cities are numbered from 0 to N-1); M is the number of highways; S and D are the starting and the destination cities
    cin >> N >> M >> S >> D;
    //M lines follow: City1 City2 Distance Cost
    int x, y, distance, c;
    for (int i = 0; i < M; i++) {
        scanf("%d%d%d%d", &x, &y, &distance, &c);
        graph[x][y] = graph[y][x] = distance;
        cost[x][y] = cost[y][x] = c;
    }
    visited[S] = true;
    vector<int> route;
    route.push_back(S);
    dfs(S, D, 0, 0, route);
    for (int eachR : minimumRoute) {
        cout << eachR << " ";
    }
    cout << minimumDistance << " " << minimumCost;
    return 0;
}

