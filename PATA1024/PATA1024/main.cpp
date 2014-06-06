//
//  main.cpp
//  PATA1024
//
//  注意如果N已经是回文数，就直接输出它，采取的步骤是0！！！
//  Created by Xin Huang on 5/7/14.
//  Copyright (c) 2014 David Huang. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int K;

bool isPalindromicNum(string num) {
    if (num.size() == 0) return false;
    if (num.size() == 1) return true;
    for (int i = 0; i < num.size() / 2; i++) {
        if (num[i] != num[num.size() - 1 - i]) return false;
    }
    return true;
}

string reverseNum(string num) {
    string result = "";
    for (int i = (int)num.size() - 1; i >= 0; i--) {
        result += num[i];
    }
    return result;
}

string addNum(string num1, string num2, int up) {
    string result = "";
    if (num1.size() == 0 || num2.size() == 0) {
        if (up > 0) result = (char)(up + '0') + result;
        return result;
    }
    int add = num1[num1.size() - 1] - '0' + num2[num2.size() - 1] - '0';
    add += up;
    result = (char)(add % 10 + '0') + result;
    result = addNum(num1.substr(0, num1.size() - 1), num2.substr(0, num2.size() - 1), add / 10) + result;
    return result;
}

string addNum(string num1, string num2) {
    return addNum(num1, num2, 0);
}

int main(int argc, const char * argv[])
{
    string N;
    cin >> N >> K;
    //注意如果N已经是回文数，就直接输出它，采取的步骤是0
    if (isPalindromicNum(N)) {
        cout << N << endl;
        cout << 0 << endl;
        return 0;
    }
    string reverseN = reverseNum(N);
    int count = 1;
    while (count <= K) {
        string result = addNum(N, reverseN);
        if (isPalindromicNum(result)) {
            cout << result << endl;
            cout << count << endl;
            break;
        } else {
            N = result;
            reverseN = reverseNum(N);
        }
        count ++;
    }
    if (count > K) {
        cout << N << endl;
        cout << K << endl;
    }
    return 0;
}

