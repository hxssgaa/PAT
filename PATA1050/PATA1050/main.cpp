//
//  main.cpp
//  PATA1050
//
//  Created by Xin Huang on 5/23/14.
//  Copyright (c) 2014 David Huang. All rights reserved.
//

#include <iostream>

using namespace std;

bool eraseMap[1000];

string subtractString(string &s1, string &s2) {
    string result = "";
    for (char ch : s1) {
        if (eraseMap[ch]) continue;
        result += ch;
    }
    return result;
}

int main(int argc, const char * argv[])
{
    string s1;
    string s2;
    getline(cin, s1);
    getline(cin, s2);
    for (char ch : s2) {
        eraseMap[ch] = 1;
    }
    cout << subtractString(s1, s2);
    return 0;
}

