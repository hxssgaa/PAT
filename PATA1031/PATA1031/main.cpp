//
//  main.cpp
//  PATA1031
//
//  此题关键点在于求出n1, 确实看了半天没读懂公式，实质上n1 <= n2 才是最关键的公式
//  Created by Xin Huang on 5/10/14.
//  Copyright (c) 2014 David Huang. All rights reserved.
//

#include <iostream>

using namespace std;

void printUShape(string str) {
    int i, j;
    int N = (int)str.size();
    int n1 = (N + 2) / 3;
    int n2 = N + 2 - 2 * n1;
    for (i = 0; i < n1 - 1; i++) {
        cout << str[i];
        for (j = 0; j < n2 -2; j++) {
            cout << " ";
        }
        cout << str[N - 1 - i] << endl;
    }
    for (i = 0; i < n2; i++) {
        cout << str[n1 - 1 + i];
    }
}

int main(int argc, const char * argv[])
{
    string formString;
    cin >> formString;
    printUShape(formString);
    return 0;
}

