//
//  main.cpp
//  PATA1060
//
//  此题对于特殊情况的处理要求极高，需高度注意如何快速相处各种特殊情况，并作出处理
//  特殊情况 0 ,0.0，0.0123，05.032，00.020
//  解决方法时对特殊情况进行分类处理，并利用过滤器过滤掉前面的多余的0，和后面的多余的0
//  快速高效的调试方法也是该题目需要大幅度研究的问题之一

//  Created by Xin Huang on 6/7/14.
//  Copyright (c) 2014 David Huang. All rights reserved.
//

#include <iostream>
#include <sstream>

using namespace std;

string formatNum(string num, int N, string exp) {
    string appendZero = "";
    int offset = N - (int)num.size();
    while (offset > 0) {
        appendZero += "0";
        offset--;
    }
    return "0." + num.substr(0, N) + appendZero + "*10^" + exp;
}

string formatFloatNum(string num, int N) {
    size_t dotPos = num.find('.');
    if (dotPos == string::npos) {
        stringstream ss;
        ss << (num == "0" ? 0 : num.size());
        return formatNum(num, N, ss.str());
    }
    if (num[0] != '0') {
        stringstream ss;
        ss << dotPos;
        num.erase(num.begin() + dotPos);
        return formatNum(num, N, ss.str());
    } else {
        for (int i = 0; i < num.size(); i++) {
            if (num[i] != '0' && num[i] != '.') {
                stringstream ss;
                ss << "-" << i - 2;
                return formatNum(num.substr(i, num.size() - i), N, ss.str());
            }
        }
    }
    return "";
}

string filterIntegerPart(string num) {
    for (int i = 0; i < num.size(); i++) {
        if (num[i] != '0') {
            return num.substr(i, num.size() - i);
        }
    }
    return "0";
}

string filterFloatNum(string num) {
    size_t dotPos = num.find('.');
    string intPart = filterIntegerPart(num.substr(0, dotPos));
    if (dotPos != string::npos) {
        for (int i = (int)num.size() - 1; i > dotPos; i--) {
            if (num[i] != '0') {
                return intPart + "." + num.substr(dotPos + 1, i - dotPos);
            }
        }
        return intPart;
    }
    return intPart;
}

void areTheyEqual(int N, string &a, string &b) {
    string s1 = formatFloatNum(filterFloatNum(a), N);
    string s2 = formatFloatNum(filterFloatNum(b), N);
    s1 == s2 ? cout << "YES " << s1 : cout << "NO " << s1 << " " << s2;
}

int main(int argc, const char * argv[])
{
    int N;
//    string s = "000000000.00012898980090901920391200000";
//    cout << formatFloatNum(filterFloatNum(s),8);
    string a, b;
    cin >> N >> a >> b;
    areTheyEqual(N, a, b);
    return 0;
}

