//
//  main.cpp
//  PATA1003
//
//  Created by Xin Huang on 4/13/14.
//  Copyright (c) 2014 David Huang. All rights reserved.
//

#include <iostream>
#include <vector>
#define MAX_N 501
using namespace std;

typedef struct mapT{
    int map[MAX_N][MAX_N];
    int weight[MAX_N];
    bool visited[MAX_N];
}mapT;

mapT map;
int numberOfCities,minimumL = INT32_MAX,sPathN = 0,maxW = 0;

void initMap() {
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j < MAX_N; j++) {
            map.map[i][j] = INT32_MAX;
        }
    }
    for (int i = 0; i < MAX_N; i++) {
        map.weight[i] = INT32_MAX;
        map.visited[i] = false;
    }
}

// This is ugly implmentation, but effective approcah to solve this problem.
void searchWithDFS(int start, int end, int distance, int numRescueTeams)
{
    if (start == end) {
        if (distance < minimumL) {
            minimumL = distance;
            maxW = numRescueTeams;
            sPathN = 1;
        } else if (distance == minimumL) {
            if (numRescueTeams > maxW) {
                maxW = numRescueTeams;
            }
            sPathN ++;
        }
        return;
    }
    map.visited[start] = true;
    
    for (int i = 0;i < numberOfCities; i++) {
        int d = map.map[start][i];
        if (map.visited[i] == true || d == INT32_MAX) continue;
        map.visited[i] = true;
        searchWithDFS(i, end, distance + d, numRescueTeams + map.weight[i]);
        map.visited[i] = false;
    }
}

int main(int argc, const char * argv[])
{
    //C1 the cities that currently in
    //C2 the cities that must save,
    int numberOfRoads, C1, C2;
    cin >> numberOfCities >> numberOfRoads >> C1 >> C2;
    
    initMap();
    
    //where the i-th integer is the number of rescue teams in the i-th city
    for (int i = 0; i < numberOfCities; i++) {
        cin >> map.weight[i];
    }
    
    int x,y,distance;
    for (int i = 0; i < numberOfRoads; i++) {
        scanf("%d%d%d",&x,&y,&distance);
        map.map[x][y] = map.map[y][x] = distance;
    }
    searchWithDFS(C1,C2,0,map.weight[C1]);
    cout << sPathN << " " << maxW;
    return 0;
}

