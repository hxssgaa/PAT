//
//  main.cpp
//  PATA1013
//
//  Created by Xin Huang on 6/6/14.
//  Copyright (c) 2014 David Huang. All rights reserved.
//

#include <cstdio>
#include <cstring>

#define N_MAX 1001

int city[N_MAX][N_MAX];
int visited[N_MAX];
int N;

using namespace std;

void search(int startCity, int lostCity) {
	for (int i = 1; i <= N; i++) {
		if (city[startCity][i] && !visited[i] && i != startCity && i != lostCity) {
			visited[i] = 1;
			search(i, lostCity);
		}
	}
}

int main()
{
	int M, K, a, b, k;
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 0; i < M; i++) {
		scanf("%d %d",&a,&b);
		city[a][b] = city[b][a] = 1;
	}
	for (int i = 0; i < K; i++) {
		scanf("%d", &k);
		int count = 0;
		memset(visited, 0, sizeof(visited));
		for (int j = 1; j <= N; j++) {
			if (j != k && !visited[j]) {
				count++;
				search(j, k);
			}
		}
		printf("%d\n", count - 1);
	}
	return 0;
}