//
//  main.cpp
//  PATA1006
//
//  Created by Xin Huang on 4/21/14.
//  Copyright (c) 2014 David Huang. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

typedef struct personT{
    string id;
    string signIn;
    string signOut;
}personT;

int compareTokenTime(string token1, string token2) {
    if (atoi(token1.c_str()) < atoi(token2.c_str())) {
        return -1;
    } else if (atoi(token1.c_str()) > atoi(token2.c_str())) {
        return 1;
    }
    return 0;
}

int compareTime(string time1, string time2) {
    stringstream ss1(time1);
    stringstream ss2(time2);
    string s1,s2;
    vector<string> vec1, vec2;
    while (getline(ss1, s1, ':')) {
        vec1.push_back(s1);
    }
    while (getline(ss2, s2, ':')) {
        vec2.push_back(s2);
    }
    if (vec1.size() != vec2.size()) {
        return false;
    }
    for (int i = 0; i < vec1.size(); i++) {
        string token1 = vec1[i];
        string token2 = vec2[i];
        int compareResult = compareTokenTime(token1, token2);
        switch (compareResult) {
            case -1:
                return -1;
            case 1:
                return 1;
            default:
                break;
        }
    }
    return 0;
}

int main(int argc, const char * argv[])
{
    int N;
    cin >> N;
    string id, signIn, signOut;
    personT *firstSignIn = NULL, *lastSignOut = NULL;
    personT *person;
    for (int i = 0; i < N; i++) {
        cin >> id >> signIn >> signOut;
        person = new personT;
        person->id = id;
        person->signIn = signIn;
        person->signOut = signOut;
        if (i == 0) {
            firstSignIn = lastSignOut = person;
            continue;
        }
        int r1 = compareTime(signIn, firstSignIn->signIn);
        int r2 = compareTime(signOut, firstSignIn->signOut);
        if (r1 == -1) {
            firstSignIn = person;
        }
        if (r2 == 1) {
            lastSignOut = person;
        }
    }
    cout << firstSignIn->id << " " << lastSignOut->id;
    return 0;
}

