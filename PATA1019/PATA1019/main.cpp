//
//  main.cpp
//  PATA1019
//
//  Created by Xin Huang on 6/6/14.
//  Copyright (c) 2014 David Huang. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

bool isPalindromic(vector<int> vec) {
	for (int i = 0; i < vec.size() / 2; i++) {
		if (vec[i] != vec[vec.size() - 1 - i]) {
			return false;
		}
	}
	return true;
}

vector<int> toBase(long long decimal, long long base) {
	vector<int> result;
	do
	{
		int num = (int)(decimal % base);
		result.push_back(num);
		decimal /= base;
	} while (decimal > 0);
	return result;
}

int main()
{
	long long N;
	long long b;
	cin >> N >> b;
	vector<int> result = toBase(N, b);
	cout << (isPalindromic(result) ? "Yes" : "No") << endl;
	for (int i = 0; i < result.size(); i++) {
		i != result.size() - 1 ?
        cout << result[result.size() - 1 - i] << " " :
        cout << result[result.size() - 1 - i];
	}
	return 0;
}
