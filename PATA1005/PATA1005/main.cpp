//
//  main.cpp
//  PATA1005
//
//  Created by Xin Huang on 4/21/14.
//  Copyright (c) 2014 David Huang. All rights reserved.
//

#include <iostream>
#include <map>
#include <sstream>

using namespace std;

static map<int, string> dict;

string sumAllDigits(string digit) {
    long sum = 0;
    for (char ch : digit) {
        sum += (int)(ch - '0');
    }
    stringstream ss;
    ss << sum;
    string resultNum = ss.str();
    string resultStr = "";
    for (char ch : resultNum) {
        resultStr += dict[ch - '0'] + " ";
    }
    return resultStr.substr(0,resultStr.length() - 1);
}

int main(int argc, const char * argv[])
{
    dict.insert(pair<int, string>(0,"zero"));
    dict.insert(pair<int, string>(1,"one"));
    dict.insert(pair<int, string>(2,"two"));
    dict.insert(pair<int, string>(3,"three"));
    dict.insert(pair<int, string>(4,"four"));
    dict.insert(pair<int, string>(5,"five"));
    dict.insert(pair<int, string>(6,"six"));
    dict.insert(pair<int, string>(7,"seven"));
    dict.insert(pair<int, string>(8,"eight"));
    dict.insert(pair<int, string>(9,"nine"));
    string s;
    cin >> s;
    string result = sumAllDigits(s);
    cout << result;
    return 0;
}

