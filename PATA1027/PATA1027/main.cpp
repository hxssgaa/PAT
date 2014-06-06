//
//  main.cpp
//  PATA1027
//
//  Created by Xin Huang on 5/9/14.
//  Copyright (c) 2014 David Huang. All rights reserved.
//

#include <iostream>

using namespace std;

string toRadix13(int decimal) {
    string result = "";
    if (decimal == 0) return "00";
    while (decimal > 0) {
        int num = decimal % 13;
        result = (char)(num <= 9 ? num + '0' : num - 10 + 'A') + result;
        decimal /= 13;
    }
    if (result.size() == 1) result = "0" + result;
    return result;
}

string getRGB(int decimal) {
    return "";
}

int main(int argc, const char * argv[])
{
    int decimal[3];
    for (int i = 0; i < 3; i++) {
        cin >> decimal[i];
    }
    cout << "#";
    for (int i = 0; i < 3; i++) {
        cout << toRadix13(decimal[i]);
    }
    return 0;
}

