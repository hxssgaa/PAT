//
//  main.cpp
//  PATA1001
//
//  Created by Xin Huang on 2/28/14.
//  Copyright (c) 2014 David Huang. All rights reserved.
//

#include <iostream>
#include <sstream>
using namespace std;

string formatNum(long long n) {
    bool isNegetive = n < 0;
    n = n < 0 ? -n : n;
    stringstream ss;
    ss << n;
    string s = ss.str();
    int cur = 3;
    while (cur < s.length()) {
        s = s.substr(0,s.length() - cur) + "," + s.substr(s.length() - cur,cur);
        cur += 4;
    }
    s = isNegetive ? "-" + s : s;
    return s;
}

int main(int argc, const char * argv[])
{
    long long a,b,result;
    cin >> a >> b;
    result = a + b;
    cout << formatNum(result);
    return 0;
}

