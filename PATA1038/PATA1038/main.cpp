//
//  main.cpp
//  PATA1038
//
//  此题考查编程的细节，比如全为0的情况，或者怎么去除前面的0的方法
//  对于编程难度是很低的
//
//  Created by Xin Huang on 5/13/14.
//  Copyright (c) 2014 David Huang. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

int N;

string numbers[10000];

bool cmp(string s1, string s2) {
    int offset = (int)(s1.length() - s2.length());
    if (offset == 0) {
        return s1 < s2;
    } else {
        return (s1 + s2) < (s2 + s1);
    }
    
}

string trimStr(string s) {
    string result = "";
    for (char ch : s) {
        if (ch == '0') continue;
        result += ch;
    }
    return result;
}

int main(int argc, const char * argv[])
{
    cin >> N;
    for (int i = 0;i < N; i++) {
        cin >> numbers[i];
    }
    sort(numbers, numbers + N, cmp);
    string result = "";
    for (int i = 0; i < N; i++) {
        string s = numbers[i];
        result += s;
    }
    int pos = 0;
    for (char ch : result) {
        if (ch != '0') break;
        pos ++;
    }
    result = result.substr(pos, result.size() - pos);
    if (result.size() == 0) cout << "0";
    else cout << result;
    return 0;
}

