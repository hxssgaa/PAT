//
//  main.cpp
//  PATA1037
//
//  注意，看来以后说N < 10^5的话别信，如果有错就把N取大点
//
//  Created by Xin Huang on 5/12/14.
//  Copyright (c) 2014 David Huang. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int NC, NP;
int coupons[100000];
int products[100000];

bool cmp(int a, int b) {
    return a > b;
}

int payBack() {
    int sum = 0;
    for (int i = 0, j = 0; i < NC && j < NP; i++, j++) {
        int coupon = coupons[i];
        int product = products[j];
        if (coupon > 0 && product > 0)
            sum += coupon * product;
    }
    for (int i = NC - 1, j = NP - 1; i >= 0 && j >= 0; i--, j--) {
        int coupon = coupons[i];
        int product = products[j];
        if (coupon < 0 && product < 0)
            sum += coupon * product;
    }
    return sum;
}

int main(int argc, const char * argv[])
{
    scanf("%d", &NC);
    for (int i = 0; i < NC; i++) {
        scanf("%d", &coupons[i]);
    }
    scanf("%d", &NP);
    for (int i = 0; i < NP; i++) {
        scanf("%d", &products[i]);
    }
    sort(coupons, coupons + NC, cmp);
    sort(products, products + NP, cmp);
    cout << payBack();
    return 0;
}

