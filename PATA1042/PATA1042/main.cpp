//
//  main.cpp
//  PATA1042
//
/*
 2
 36 52 37 38 3 39 40 53 54 41 11 12 13 42 43 44 2 4 23 24 25 26 27 6 7 8 48 49 50 51 9 10 14 15 16 5 17 18 19 1 20 21 22 28 29 30 31 32 33 34 35 45 46 47
 */
//  Created by Xin Huang on 5/17/14.
//  Copyright (c) 2014 David Huang. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
using namespace std;

string cards[55];
string shuffledCards[55];
int shuffleOrder[55];

void initCards() {
    for (int i = 1; i <= 52; i++) {
        stringstream ss;
        ss << (i % 13 == 0 ? 13 : i % 13);
        switch ((i - 1) / 13) {
            case 0:
                cards[i] = ("S" + ss.str());
                break;
            case 1:
                cards[i] = ("H" + ss.str());
                break;
            case 2:
                cards[i] = ("C" + ss.str());
                break;
            case 3:
                cards[i] = ("D" + ss.str());
                break;
            default:
                break;
        }
    }
    cards[53] = "J1";
    cards[54] = "J2";
}

int main(int argc, const char * argv[])
{
    initCards();
    int repeated, i;
    cin >> repeated;
    for (i = 1; i <= 54; i++) {
        cin >> shuffleOrder[i];
    }
    int count = 0;
    while (count < repeated) {
        for (i = 1; i <= 54; i++) {
            shuffledCards[shuffleOrder[i]] = cards[i];
        }
        memcpy(cards, shuffledCards, sizeof(shuffledCards));
        count ++;
    }
    for (i = 1; i <= 54; i++) {
        if (i == 54) {
            cout << (repeated == 0 ? cards[i] : shuffledCards[i]);
            break;
        }
        cout << (repeated == 0 ? cards[i] : shuffledCards[i]) << " ";
    }
    return 0;
}

