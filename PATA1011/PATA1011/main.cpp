//
//  main.cpp
//  PATA1011
//
//  Created by Xin Huang on 4/24/14.
//  Copyright (c) 2014 David Huang. All rights reserved.
//

#include <iostream>

using namespace std;

int foundBest(float *game, int N) {
    int max = game[0];
    int maxIndex = 0;
    for (int i = 0; i < N; i++) {
        if (game[i] > max) {
            max = game[i];
            maxIndex = i;
        }
    }
    return maxIndex;
}

int main(int argc, const char * argv[])
{
    char dict[3];
    dict[0] = 'W';
    dict[1] = 'T';
    dict[2] = 'L';
    float game[3];
    float bestOdds[3];
    int bestOddsIndex[3];
    for (int i = 0; i < 3; i++) {
        cin >> game[0] >> game[1] >> game[2];
        bestOddsIndex[i] = foundBest(game, 3);
        bestOdds[i] = game[bestOddsIndex[i]];
    }
    double profit = (bestOdds[0] * bestOdds[1] * bestOdds[2] * 0.65 - 1) * 2;
    for (int i = 0; i < 3;i++) {
        cout << dict[bestOddsIndex[i]] << " ";
    }
    printf("%.2f",profit);
    return 0;
}

