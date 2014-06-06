//
//  main.cpp
//  PATA1039
//
//  此题有几点要注意的地方，
//  第一、对于N大于20000的case又用到sort的，一定记得最好用 char *来记录名字
//  第二、对于char * 要用到map的，可以使用hash来把char * 转换成name
//  第三、记录char *最好每次记录新建一个char 数组，再scanf进去，这样就不会有指针重复问题
//  第四、对于查询结果这种事情来说，直接输入一个查询，就输出一个结果就可以了，没必要把其存入vector再遍历输出结果
//  Created by Xin Huang on 5/14/14.
//  Copyright (c) 2014 David Huang. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;

const int MAXN=26*26*26*10;

//映射name到hash
int hashName(char *name){
    return (name[0]-'A')*26*26*10+(name[1]-'A')*26*10+(name[2]-'A')*10+(name[3]-'0');
}

int main(int argc, const char * argv[])
{
    //N (<=40000), the number of students who look for their course lists,
    //and K (<=2500), the total number of courses.
    int i, j;
    scanf("%d %d", &N, &K);
    int courseIndex, numRegisteredStu;

    vector<vector<int> > courseMap(MAXN + 1);
    for (i = 0; i < K; i++) {
        scanf("%d %d", &courseIndex, &numRegisteredStu);
        for (j = 0; j < numRegisteredStu; j++) {
            char name[5];
            scanf("%s", name);
            courseMap[hashName(name)].push_back(courseIndex);
        }
    }
    for (i = 0; i < N ;i++) {
        char name[5];
        scanf("%s", name);
        vector<int> vec = courseMap[hashName(name)];
        printf("%s %ld", name, vec.size());
        sort(vec.begin(), vec.end());
        for (int eachCourse : vec) {
            printf(" %d", eachCourse);
        }
        printf("\n");
    }
    return 0;
}

