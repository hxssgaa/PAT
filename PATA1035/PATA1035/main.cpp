//
//  main.cpp
//  PATA1035
//
//  Created by Xin Huang on 5/11/14.
//  Copyright (c) 2014 David Huang. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct userT{
    string name;
    string psd;
}userT;

int N;

userT users[1000];

string modifyPsd(string psd) {
    string result = "";
    for (char ch : psd) {
        switch (ch) {
            case '1':
                ch = '@';
                break;
            case '0':
                ch = '%';
                break;
            case 'l':
                ch = 'L';
                break;
            case 'O':
                ch = 'o';
                break;
            default:
                break;
        }
        result += ch;
    }
    return result;
}

int main(int argc, const char * argv[])
{
    cin >> N;
    vector<userT> vec;
    int i;
    for (i = 0;i < N;i++) {
        cin >> users[i].name >> users[i].psd;
    }
    for (i = 0;i < N;i++) {
        userT user = users[i];
        string modified = modifyPsd(user.psd);
        if (modified != user.psd) {
            user.psd = modified;
            vec.push_back(user);
        }
    }
    if (vec.size() == 0) {
        printf("There %s %d %s and no account is modified", N == 1 ? "is" : "are", N, N == 1 ? "account" : "accounts");
    } else {
        cout << vec.size() << endl;
        for (userT eachUser : vec) {
            cout << eachUser.name << " " << eachUser.psd << endl;
        }
    }
    return 0;
}

