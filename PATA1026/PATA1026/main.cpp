//
//  main.cpp
//  PATA1026
//
//  这道题is too complex for me to compute, when I have time, I will solve this, but not now.
//  Created by Xin Huang on 5/8/14.
//  Copyright (c) 2014 David Huang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <queue>
#include <sstream>
#include <algorithm>

using namespace std;

int N, K, M;
bool isVipTable[101];
int serveTable[101];

typedef struct playerT{
    string arrTimeStr;
    int arrHour;
    int arrMinute;
    int arrSecond;
    int arrTime;
    int playintTime;//in minutes
    int serveTime;//since 8:00
    
    bool isVip;
}playerT;

bool comparePlayer(playerT p1, playerT p2) {
    return p1.arrTime < p2.arrTime;
}

void printInfo(vector<playerT> players) {
    for (playerT p : players) {
        if (p.serveTime >= 13 * 3600) continue;
        int serveTimeAct = p.serveTime;
        int serveTimeHour = serveTimeAct / 3600;
        int serveTimeMinute = (p.serveTime - serveTimeHour * 3600) / 60;
        int serveTimeSecond = serveTimeAct - serveTimeHour * 3600 - serveTimeMinute * 60;
        serveTimeHour += 8;
        int waitingTime = (int)(1.0 * (serveTimeAct - p.arrTime + 30) / 60);
        printf("%s %.2d:%.2d:%.2d %d\n", p.arrTimeStr.c_str(), serveTimeHour, serveTimeMinute, serveTimeSecond, waitingTime);
    }
    for (int i = 1; i <= K; i++) {
        i == K ? cout << serveTable[i] << endl : cout << serveTable[i] << " ";
    }
}

void chooseSmallestTable(queue<int> *table, vector<playerT> &players, int p, bool isVip) {
    int flag = 0;
    if (isVip) {
        for (int i = 1; i <= K; i++) {
            if (isVipTable[i]) {
                if (!table[i].empty()) {
                    if (players[table[i].front()].arrTime + players[table[i].front()].playintTime >= players[p].arrTime) {
                        continue;
                    }
                }
                table[i].push(p);
                serveTable[i] ++;
                flag = 1;
                break;
            }
        }
    }
    if (!flag) {
        for (int i = 1; i <= K; i++) {
            if (table[i].empty()) {
                table[i].push(p);
                serveTable[i] ++;
                break;
            }
        }
    }
}

int main(int argc, const char * argv[])
{
    memset(isVipTable, 0, sizeof(isVipTable));
    memset(serveTable, 0, sizeof(serveTable));
    vector<playerT> players;
    cin >> N;
    playerT player;
    string timeStr;
    int i,p,vip,hour,minute,second;
    for (i = 0; i < N; i++) {
        cin >> timeStr >> p >> vip;
        player.arrTimeStr = timeStr;
        hour = atoi(timeStr.substr(0,2).c_str());
        minute = atoi(timeStr.substr(3,2).c_str());
        second = atoi(timeStr.substr(6,2).c_str());
        player.arrTime = hour * 3600 + minute * 60 + second - 8 * 3600;
        player.playintTime = p;
        if (player.playintTime > 2 * 60) player.playintTime = 2 * 60;
        player.isVip = vip == 1;
        players.push_back(player);
    }
    cin >> K >> M;
    for (int i = 0; i < M; i++) {
        cin >> vip;
        isVipTable[vip] = true;
    }
    sort(players.begin(), players.end(), comparePlayer);
    queue<int> table[101];
    int count = 0;
    for (i = 1; i <= K && count < N; i++) {
        players[count].serveTime = players[count].arrTime;
        chooseSmallestTable(table, players, count, players[count].isVip);
        count++;
    }
    while (count < N) {
        int earliestLeave = 1;
        int earliestFinishTime = players[table[1].front()].serveTime + players[table[1].front()].playintTime * 60;
        for (i = 2; i <= K; i++) {
            player = players[table[i].front()];
            if (player.serveTime + player.playintTime * 60 < earliestFinishTime) {
                earliestLeave = i;
                earliestFinishTime = player.serveTime + player.playintTime * 60;
            }
        }
        int flag = 0;
        if (isVipTable[earliestLeave]) {
            int temp = count;
            while (temp < N) {
                if (players[temp].arrTime >= earliestFinishTime) break;
                if (players[temp].isVip) {
                    flag = 1;
                    players[temp].serveTime = earliestFinishTime;
                    player = players[temp];
                    players.erase(players.begin() + temp);
                    players.insert(players.begin() + count, player);
                    table[earliestLeave].pop();
                    table[earliestLeave].push(count);
                    if (earliestFinishTime < 13 * 3600)
                        serveTable[earliestLeave] ++;
                    count ++;
                    break;
                }
                temp ++;
            }
        }
        if (!flag) {
            if (players[count].arrTime > earliestFinishTime) {
                for (i = 1; i <= K; i++) {
                    if (players[count].isVip && !isVipTable[i]) continue;
                    player = players[table[i].front()];
                    if (player.serveTime + player.playintTime * 60 < players[count].arrTime) {
                        players[count].serveTime = players[count].arrTime;
                        if (players[count].arrTime < 13 * 3600)
                            serveTable[i] ++;
                        table[i].pop();
                        table[i].push(count);
                        count ++;
                        break;
                    }
                }
            } else {
            int serveTime = earliestFinishTime;
            players[count].serveTime = serveTime;
            table[earliestLeave].pop();
            table[earliestLeave].push(count);
            if (serveTime < 13 * 3600)
                serveTable[earliestLeave] ++;
            count ++;
            }
        }
    }
    printInfo(players);
    return 0;
}

