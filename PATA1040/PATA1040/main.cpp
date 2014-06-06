//
//  main.cpp
//  PATA1040
//
//  此题找回文串的简单方法是，遍历字符串每一个字符，查看以其为中心的回文串的最大长度，可分为奇数和偶数的判断
//  注意，类似的题目，往往可以联系到前一个与后一个的关系，但是同时也注意特殊情况的判断
//  但是往往前一个与后一个的关系不太好比较，但是不这么判断达不到O(N)的速度，所以嘛，need to try this

//  Created by Xin Huang on 5/15/14.
//  Copyright (c) 2014 David Huang. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
int main()
{
    string a;
    getline(cin,a);
    int i,j,max = 0,n=(int)a.size();
    for(i=0;i<n;i++)
    {
        //最长回文串的长度为奇数
        for(j=0;i-j>=0&&i+j<n;j++)
        {
            if(a[i-j]!=a[i+j])
                break;
            if(max<2*j+1)
                max=2*j+1;
        }
        //最长回文串的长度为奇数
        for(j=0;i-j>=0&&i+j+1<n;j++)
        {
            if(a[i-j]!=a[i+j+1])
                break;
            if(max<2*j+2)
                max=2*j+2;
        }
    }
    cout<<max<<endl;
    return 0;
}

