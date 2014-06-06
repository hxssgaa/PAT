//
//  main.cpp
//  PATA1033
//
//  此题使用贪心算法，而且是比较难的那种，整个算法可以用递归来解决，
//  但是需要判断很多种情况，到达终点的情况，如何使花费最小等
//  对于一些变量的安排可以放在局部变量中便于输出

//  Created by Xin Huang on 5/10/14.
//  Copyright (c) 2014 David Huang. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <algorithm>
#include <fstream>
#include <iomanip>

using namespace std;

int Cmax, D, Davg, N;

typedef struct nodeT{
    double price;
    double distance;
}nodeT;

bool finished = false;
double cost = 0;

nodeT s[500];

bool cmp(nodeT n1, nodeT n2) {
    return n1.distance < n2.distance;
}

double fillOrNotFill(int index, double left) {
    double fastest = s[index].distance + Davg * Cmax;
    if (index + 1 < N && s[index + 1].distance - s[index].distance > Cmax * Davg) {
        // 距离已经拉开太大，不能到达下一个站了，因此只好用光剩下的油，能走多远走多远了（不能完成）
        cost += s[index].price * (Cmax - left);
        return fastest;
    }
    else if (index + 1 == N && (D - s[index].distance > Cmax * Davg)) {
        // 在最后一个站，但距离超出自己所能跑的最大距离了（不能完成）
        cost += s[index].price * (Cmax - left);
        return fastest;
    }
    int smallest = index + 1;//若找不到比当前便宜的，那么找它们之中最便宜的
    //遍历所有可到站范围之内
    for (int i = index + 1; i < N && s[i].distance < fastest; i++) {
        //若找到价格比目前站低的，那么尽量少得用油到达那个站。
        if (s[index].price > s[i].price) {
            cost += ((s[i].distance - s[index].distance)/Davg - left) * s[index].price;
            return fillOrNotFill(i, 0);
        }
        else if (s[smallest].price > s[i].price)
            smallest = i;
    }
    //如果没有比当前便宜的
    if (fastest >= D) {
        //已经可以到达终点
        cost += ((D - s[index].distance)/Davg - left)*s[index].price;
        finished = true;
        return 0.0;
    } else {
        //否则尽量充满油，到达邮费相对最便宜的收费站.
        cost += (Cmax - left) * s[index].price;
        return fillOrNotFill(smallest, Cmax - (s[smallest].distance - s[index].distance)/Davg);
    }
}

int main(int argc, const char * argv[])
{
    cin >> Cmax >> D >> Davg >> N;
    for (int i = 0; i < N; i++) {
        cin >> s[i].price >> s[i].distance;
    }
    sort(s, s + N, cmp);
    double fastest = fillOrNotFill(0, 0.0);
    if (s[0].distance != 0) {
        cout<<"The maximum travel distance = 0.00"<<endl;
        return 0;
    }
    if(finished)
        cout<<fixed<<setprecision(2)<<cost<<endl;
    else
        cout<<"The maximum travel distance = "<<fixed<<setprecision(2)<<fastest<<endl;
    return 0;
}

