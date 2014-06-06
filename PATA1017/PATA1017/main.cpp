//
//  main.cpp
//  PATA 1017
//
//  Created by Xin Huang on 6/6/14.
//  Copyright (c) 2014 David Huang. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

typedef struct customerT
{
	int arrHour;
	int arrMinute;
	int arrSecond;
	int arrTotal;
	int leaveTotal;
	int processingTime;
	int waitingTime;
}customerT;

#define N_MAX 10000

bool compare(customerT a, customerT b) {
	return a.arrTotal < b.arrTotal;
}

struct cmp{
	bool operator() (pair<int, int> a, pair<int, int> b){
		return a.first > b.first;
	}
};

int main()
{
	//N (<=10000) - the total number of customers, and K (<=100) - the number of windows
	int N, K;
	scanf("%d%d", &N, &K);
	vector<customerT> cVec;
	customerT c;
	for (int i = 0; i < N; i++) {
		scanf("%d:%d:%d %d", &c.arrHour, &c.arrMinute, &c.arrSecond, &c.processingTime);
		c.processingTime *= 60;
		c.arrTotal = c.arrHour * 3600 + c.arrMinute * 60 + c.arrSecond - 8 * 3600;
		c.leaveTotal = -1;
		c.waitingTime = 0;
		cVec.push_back(c);
	}
	sort(cVec.begin(), cVec.end(), compare);
	priority_queue<pair<int, int>, vector<pair<int, int> >, cmp > window;
	int waitTotal = 0;
	// Anyone arrives early will have to wait in line till 08:00, but time flows
	for (int i = 0; i < cVec.size(); i++) {
		customerT eachCustomer = cVec[i];
		if (eachCustomer.arrTotal < 0) {
			waitTotal += (-cVec[i].arrTotal);
			cVec[i].arrTotal = 0;
		}
	}
	int count = 0;
	for (int i = 0; i < K && count < cVec.size(); i++) {
		cVec[count].leaveTotal = cVec[count].arrTotal + cVec[count].processingTime;
		window.push(pair<int, int>(cVec[count].leaveTotal, count));
		count++;
	}
	while (count < cVec.size())
	{
		int ft = cVec[window.top().second].leaveTotal;
		int begin = max(cVec[count].arrTotal, ft);
		cVec[count].leaveTotal = begin + cVec[count].processingTime;
		cVec[count].waitingTime = begin - cVec[count].arrTotal;
		window.pop();
		window.push(pair<int, int>(cVec[count].leaveTotal, count));
		count++;
	}
	int validCount = 0;
	for (customerT eachCustomer : cVec) {
		if (eachCustomer.arrTotal >= 9 * 3600) continue;
		validCount++;
		waitTotal += eachCustomer.waitingTime;
	}
	printf("%.1f", validCount == 0 ? 0 : 1.0 * waitTotal / 60 / validCount);
    
	return 0;
}

