//
//  main.cpp
//  PATA1023
//
//  Created by Xin Huang on 5/6/14.
//  Copyright (c) 2014 David Huang. All rights reserved.
//

#include <iostream>

bool digitMap[10];
bool digitMapCmp[10];

using namespace std;

string doubledNumber(string num, int up) {
    if (num.size() == 0) {
        string s = "";
        if (up > 0) s += (char)(up + '0');
        return s;
    }
    string result = "";
    int last = num[num.size() - 1] - '0';
    last *= 2;
    last += up;
    result = (char)(last % 10 + '0') + result;
    result = doubledNumber(num.substr(0,num.size() - 1), last / 10) + result;
    return result;
}

string doubledNumber(string num) {
    return doubledNumber(num, 0);
}

int main(int argc, const char * argv[])
{
    for (int i = 0; i < 9; i++) {
        digitMap[i] = digitMapCmp[i] = false;
    }
    string num;
    cin >> num;
    string s = doubledNumber(num);
    for (char ch : num) {
        digitMap[ch - '0'] = true;
    }
    for (char ch : s) {
        digitMapCmp[ch - '0'] = true;
    }
    bool flag = true;
    for (int i = 0; i < 9; i++) {
        if (digitMap[i] != digitMapCmp[i]) {
            flag = false;
            break;
        }
    }
    flag ? cout << "Yes" << endl : cout << "No" << endl;
    cout << s << endl;
    return 0;
}

