//
//  main.cpp
//  PATA1057InvertedSequenceNumber
//
//  Created by Xin Huang on 6/2/14.
//  Copyright (c) 2014 David Huang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

#define MAX_N 100001

typedef struct btn{
    int numData[MAX_N];
    
    int lowbit(int x) {
        return x&(-x);
    }
    
    void edit(int k, int offset) {
        for (int i = k; i < MAX_N; i+=lowbit(i)) {
            numData[i] += offset;
        }
    }
    
    int sum(int k) {
        int count = 0;
        for (int i = k; i > 0; i-=lowbit(i)) {
            count += numData[i];
        }
        return count;
    }
}btn;

int main(int argc, const char * argv[])
{
    btn btn;
    int N, num;
    cin >> N;
    vector<int> nums;
    for (int i = 0; i < N; i++) {
        cin >> num;
        nums.push_back(num);
    }
    for (int i = 0; i < nums.size(); i++) {
        int num = nums[i];
        for (int j = 0; j < i; j++) {
            if (nums[j] > num) {
                btn.edit(i, 1);
            }
        }
    }
    cout << btn.sum(N);
    return 0;
}

