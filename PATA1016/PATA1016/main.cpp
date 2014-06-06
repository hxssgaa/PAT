//
//  main.cpp
//  PATA1016
//
//  属于输入数据很不好弄得题目
//  Created by Xin Huang on 4/29/14.
//  Copyright (c) 2014 David Huang. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <sstream>

#define N_MAX 1000

using namespace std;

unsigned int rate[24];

typedef struct billT{
    string onlineDate;
    string offlineDate;
    int duration;
}billT;

//mm:dd:hh:mm -> minute
int getTime(string date) {
    int time = 0;
    stringstream ss(date);
    string cur;
    int i = 0;
    while (getline(ss, cur, ':')) {
        int tokenTime = atoi(cur.c_str());
        switch (i) {
            case 1:
                time += 24 * 60 * tokenTime;
                break;
            case 2:
                time += 60 * tokenTime;
                break;
            case 3:
                time += tokenTime;
                break;
            default:
                break;
        }
        i++;
    }
    return time;
}

float getCharge(string onlineDate, int duration) {
    float cents = 0;
    
    int onlineDateHour = atoi(onlineDate.substr(6, 2).c_str());
    int onlineDateMinute = atoi(onlineDate.substr(9, 2).c_str());
    
    if (duration + onlineDateMinute < 60) {
        cents += duration * rate[onlineDateHour];
    } else {
        cents += (60 - onlineDateMinute) * rate[onlineDateHour];
        onlineDateHour ++;
        duration -= (60 - onlineDateMinute);
        while (duration > 0) {
            if (onlineDateHour >= 24) onlineDateHour = 0;
            if (duration < 60) {
                cents += duration * rate[onlineDateHour];
                duration = 0;
            } else {
                onlineDateHour++;
                cents += 60 * rate[onlineDateHour];
                duration -= 60;
            }
        }
    }
    return cents / 100;
}

//mm:dd:hh:mm
int durationMinute(string date1, string date2) {
    return getTime(date2) - getTime(date1);
}

int main(int argc, const char * argv[])
{
    for (int i = 0; i < 24; i++) {
        scanf("%d", &rate[i]);
    }
    int N;
    cin >> N;
    map<string, vector<billT> > billMap;
    map<string, vector<string> > onlineRecords;
    map<string, vector<string> > offlineRecords;
    string name, date, lineInfo;
    for (int i = 0; i < N; i++) {
        cin >> name >> date >> lineInfo;
        if (lineInfo == "on-line") {
            if (onlineRecords.find(name) == onlineRecords.end()) {
                vector<string> start;
                start.push_back(date);
                onlineRecords.insert(pair<string, vector<string> >(name, start));
            } else {
                onlineRecords[name].push_back(date);
            }
        } else if (lineInfo == "off-line") {
            if (offlineRecords.find(name) == offlineRecords.end()) {
                vector<string> start;
                start.push_back(date);
                offlineRecords.insert(pair<string, vector<string> >(name, start));
            } else {
                offlineRecords[name].push_back(date);
            }
        }
    }
    
    for (map<string, vector<string> >::iterator it = onlineRecords.begin(); it != onlineRecords.end(); ++it) {
        vector<string> online = it->second;
        if (offlineRecords.find(it->first)==offlineRecords.end()) continue;//couldn't find the pair
        vector<string> offline = offlineRecords[it->first];
        vector<billT> vec;
        if (online.size() <= offline.size()) {
            for (string eachOnlineRecord : online) {
                int time = INT32_MAX;
                int foundi = -1;
                billT bill;
                bill.onlineDate = eachOnlineRecord;
                for (int i = 0; i < offline.size(); i++) {
                    string eachOfflineRecord = offline[i];
                    int duration = durationMinute(eachOnlineRecord, eachOfflineRecord);
                    if (duration > 0 && duration < time) {
                        time = duration;
                        foundi = i;
                    }
                }
                if (time != INT32_MAX || foundi == 1) {
                    bill.offlineDate = offline[foundi];
                    bill.duration = time;
                    offline.erase(offline.begin() + foundi);
                    vec.push_back(bill);
                }
            }
        }
        else {
            for (string eachOfflineRecord : offline) {
                int time = INT32_MAX;
                int foundi = -1;
                billT bill;
                bill.offlineDate = eachOfflineRecord;
                for (int i = 0; i < online.size(); i++) {
                    string eachOnlineRecord = online[i];
                    int duration = durationMinute(eachOnlineRecord, eachOfflineRecord);
                    if (duration > 0 && duration < time) {
                        time = duration;
                        foundi = i;
                    }
                }
                if (time != INT32_MAX || foundi == 1) {
                    bill.onlineDate = online[foundi];
                    bill.duration = time;
                    online.erase(online.begin() + foundi);
                    vec.push_back(bill);
                }
            }
        }
        billMap.insert(pair<string, vector<billT> >(it->first, vec));
    }
    for (map<string, vector<billT> >::iterator it = billMap.begin(); it != billMap.end(); ++it) {
        cout << it->first << " " << it->second[0].onlineDate.substr(0, 2) << endl;
        float total = 0;
        for (billT eachBill : it->second) {
            float charge = getCharge(eachBill.onlineDate, eachBill.duration);
            total += charge;
            cout << eachBill.onlineDate.substr(3,eachBill.onlineDate.size() - 3) << " " << eachBill.offlineDate.substr(3,eachBill.offlineDate.size() - 3) << " " << eachBill.duration << " $";
            printf("%.2f\n", charge);
        }
        printf("Total amount: $%.2f\n", total);
    }
    
    return 0;
}

