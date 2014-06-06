//
//  main.cpp
//  PATA1018
//
//  Created by Xin Huang on 6/6/14.
//  Copyright (c) 2014 David Huang. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>

using namespace std;

//Cmax (<= 100), always an even number, is the maximum capacity of each station;
//N (<= 500), the total number of stations;
//Sp, the index of the problem station
//(the stations are numbered from 1 to N, and PBMC is represented by the vertex 0);
//and M, the number of roads
int Cmax, N, sp, M;

int numberOfBikes[501];

int map[501][501];

bool visited[501];

#define INFINITY 1000000000

int minDistance = INFINITY;
int minSend = INFINITY;
int minBringBackBike = INFINITY;
vector<int> shortestPath;

void initMap() {
	for (int i = 0; i < 501; i++) {
		for (int j = 0; j < 501; j++) {
			map[i][j] = -1;
		}
		visited[i] = false;
	}
}

void searchWithDFS(int start, int end, int distance, int collectBikes, int needSend, vector<int> &path) {
	if (start == end) {
		int bring = start == 0 ? 0 : numberOfBikes[start] - Cmax / 2;
		collectBikes = collectBikes + bring;
		if (collectBikes < 0) {
			needSend += (-collectBikes);
			collectBikes = 0;
		}
		if (distance < minDistance) {
			minDistance = distance;
			minSend = needSend;
			minBringBackBike = collectBikes;
			shortestPath = path;
		}
		else if (distance == minDistance) {
			if (needSend < minSend) {
				minSend = needSend;
				minBringBackBike = collectBikes;
				shortestPath = path;
			}
			else if (needSend == minSend && collectBikes < minBringBackBike) {
				minBringBackBike = collectBikes;
				shortestPath = path;
			}
		}
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (visited[i]) continue;
		int costDistance = map[i][start];
		if (costDistance >= 0) {
			int bring = start == 0 ? 0 : numberOfBikes[start] - Cmax / 2;
			int remainingBikes = collectBikes + bring;
			if (remainingBikes < 0) {
				needSend += (-remainingBikes);
				remainingBikes = 0;
			}
			visited[i] = true;
			path.push_back(i);
			searchWithDFS(i, end, distance + costDistance, remainingBikes, needSend, path);
			path.pop_back();
			visited[i] = false;
		}
	}
}

int main()
{
	initMap();
	cin >> Cmax >> N >> sp >> M;
	for (int i = 1; i <= N; i++) {
		cin >> numberOfBikes[i];
	}
	int si, sj, tij;
	for (int i = 0; i < M; i++) {
		cin >> si >> sj >> tij;
		map[si][sj] = map[sj][si] = tij;
	}
	vector<int> path;
	searchWithDFS(0, sp, 0, 0, 0, path);
	cout << minSend;
	cout << " 0";
	for (int eachPath : shortestPath) {
		cout << "->" << eachPath;
	}
	cout << " " << minBringBackBike;
	return 0;
}