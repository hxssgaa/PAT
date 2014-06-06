//
//  main.cpp
//  PATA1008
//
//  Created by Xin Huang on 4/22/14.
//  Copyright (c) 2014 David Huang. All rights reserved.
//

#include <iostream>

using namespace std;

int timeCostOfFloor(int *floor, int N) {
    int cost = 0;
    int cur = 0;
    for (int i = 0; i < N; i++) {
        int move = floor[i] - cur;
        cost += move >= 0 ? move * 6 + 5 : -move * 4 + 5;
        cur = floor[i];
    }
    return cost;
}

int main(int argc, const char * argv[])
{
    int N;
    cin >> N;
    int floor[N];
    for (int i = 0; i < N; i++) {
        cin >> floor[i];
    }
    cout << timeCostOfFloor(floor, N);
    return 0;
}

