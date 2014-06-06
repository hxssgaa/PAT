//
//  main.cpp
//  PATA1014
//
//  Created by Xin Huang on 6/6/14.
//  Copyright (c) 2014 David Huang. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

#define MAX_NUM 1001

typedef struct customerT
{
	int start, end, transactionTime;
}customerT;

customerT c[MAX_NUM];

int main()
{
	int N, M, K, Q, q;
	scanf("%d%d%d%d", &N, &M, &K, &Q);
	queue<int> line[20];
    
	for (int i = 1; i <= K; i++) {
		scanf("%d", &c[i].transactionTime);
		c[i].start = -1;
		c[i].end = -1;
	}
	int count = 1;
	for (int i = 0; i < N && count <= K; i++) {//push first row of customer.
		line[i].push(count);
		c[count].start = 0;
		c[count].end = c[count].transactionTime;
		count++;
	}
	for (int j = 0; j < M - 1 && count <= K; j++) {
		for (int i = 0; count <= K && i < N; i++) {//push next M - 1 rows of customers to the line.
			c[count].start = c[line[i].back()].end;
			c[count].end = c[count].start + c[count].transactionTime;
			line[i].push(count);
			count++;
		}
	}
	int now = 0;
	int shut_time_offset = (17 - 8) * 60;
	while (count <= K)//the remaining customers waiting outside the yellow line.
	{
		int si = 0;
		int st = c[line[0].front()].end;
		for (int i = 1; i < N; i++) {
			if (c[line[i].front()].end < st) {
				si = i;
				st = c[line[i].front()].end;
			}
		}
		now = c[line[si].front()].end;
		line[si].pop();
		c[count].start = c[line[si].back()].end;
		c[count].end = c[count].start + c[count].transactionTime;
		line[si].push(count);
		count++;
	}
	for (int i = 0; i < Q; i++) {
		scanf("%d", &q);
		int offset = c[q].end;
		if (offset == -1 || c[q].start >= shut_time_offset) {
			printf("Sorry\n");
		}
		else
		{
			printf("%.2d:%.2d\n", 8 + offset / 60, offset % 60);
		}
	}
	return 0;
}