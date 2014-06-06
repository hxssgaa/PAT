//
//  main.cpp
//  PATA1025
//
//  此题实质考查归并排序，在有时间的时候，将此题implement成merge sort form，并比较之前的运行时间
//  此题需注意compareStuScore的参数不能按地址寻址&,直接比较即可
//  Created by Xin Huang on 5/8/14.
//  Copyright (c) 2014 David Huang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm> //再次注意，用sort,首先include <algorithm>

int N;

using namespace std;

typedef struct stuT{
    string registrationNumber;
    int score;
    int finalRank;
    int locationNumber;
    int localRank;
}stuT;

void getLocalRank(vector<stuT> &vec, int start, int flag) {
    if (vec.size() == 0) return;
    int score = vec[start].score;
    if (flag == 0) vec[start].localRank = 1;
    else vec[start].finalRank = 1;
    int count = 2;
    int rank = 1;
    for (int i = start + 1; i < vec.size(); i++) {
        if (vec[i].score != score)
            rank = count;
        if (flag == 0) vec[i].localRank = rank;
        else vec[i].finalRank = rank;
        count++;
        score = vec[i].score;
    }
}

bool compareStuScore(stuT stu1, stuT stu2) {
    if (stu1.score == stu2.score) {
        return stu1.registrationNumber < stu2.registrationNumber;
    }
    return stu1.score > stu2.score;
}

void printStus(vector<stuT> &stu) {
    cout << stu.size() << endl;
    for (stuT eachStu : stu) {
        cout << eachStu.registrationNumber << " " << eachStu.finalRank << " " << eachStu.locationNumber << " " << eachStu.localRank << endl;
    }
}

int main(int argc, const char * argv[])
{
    cin >> N;
    int K;
    string registrationNumber;
    int score;
    vector<stuT> vec;
    stuT stu;
    int pos = 0;
    for (int i = 1; i <= N; i++) {
        cin >> K;
        for (int j = 0; j < K; j++) {
            cin >> registrationNumber >> score;
            stu.registrationNumber = registrationNumber;
            stu.score = score;
            stu.locationNumber = i;
            vec.push_back(stu);
        }
        sort(vec.begin() + pos, vec.end(), compareStuScore);
        getLocalRank(vec, pos, 0);
        pos += K;
    }
    sort(vec.begin(), vec.end(), compareStuScore);
    getLocalRank(vec, 0, 1);
    printStus(vec);
    return 0;
}

