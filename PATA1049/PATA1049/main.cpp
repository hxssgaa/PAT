//
//  main.cpp
//  PATA1049
//
//  做完这道题才发现，自己对找数的规律是那么不敏感
//  此题亦需要高度注意，注意相关的算法
//  其实最关键的问题就是找数学规律，得到的是一个递归式子
//
/*
 例如100
 
 个位1的个数：它左边只能取0-9，所以有10个
 
 十位1的个数：它左边只能取0，右边能取0-9，所以有10个
 
 百位1的个数：1个
 
 */
//  Created by Xin Huang on 5/23/14.
//  Copyright (c) 2014 David Huang. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

long CountOne3(long n)
{
    long i = 0,j = 1;
    long count = 0;
    for (i = 0; i <= n; i++)
    {
        j = i;
        while (j != 0)
        {
            if (j % 10 == 1)
                count++;
            j = j / 10;
        }
    }
    return count;
}

long CountOne(long n)
{
    long count = 0;
    if (n == 0)
        count = 0;
    else if (n > 1 && n < 10)
        count =  1;
    else
    {
        long highest = n;//表示最高位的数字
        int bit = 0;
        while (highest >= 10)
        {
            highest = highest / 10;
            bit++;
        }
        
        int weight = (int)pow(10, bit);//代表最高位的权重，即最高位一个1代表的大小
        if (highest == 1)
        {
            count = CountOne(weight - 1)
            + CountOne(n - weight)
            + n - weight + 1;
        }
        else
        {
            count = highest * CountOne(weight - 1)
            + CountOne(n - highest * weight)
            + weight;
        }
    }
    return count;
}

long CountOne2(long n)
{
    long count = 0;
    long i = 1;
    long current = 0,after = 0,before = 0;
    while((n / i) != 0)
    {
        current = (n / i) % 10;
        before = n / (i * 10);
        after = n - (n / i) * i;
        
        if (current > 1)
            count = count + (before + 1) * i;
        else if (current == 0)
            count = count + before * i;
        else if(current == 1)
            count = count + before * i + after + 1;
        
        i = i * 10;
    }
    return count;
    
}

int main(int argc, const char * argv[])
{
    int d;
    scanf("%d",&d);
    cout << (CountOne(d));
    return 0;
}

