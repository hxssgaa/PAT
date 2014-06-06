//
//  main.cpp
//  PATA1028
//
//  此题对于需要较大量的排序特别注意
//  1.对于大量N的排序，必须使用scanf，在scanf时要注意结构体char数组的容量是有效长度+1（结束符）
//  2.结构体直接使用char数组就可以了,char的比较用strcmp
//  3.尽量不要使用vector，使用数组，数组也可以利用sort函数排序
//  Created by Xin Huang on 5/9/14.
//  Copyright (c) 2014 David Huang. All rights reserved.
//

#include <cstring>
#include <algorithm>

int N, C;

using namespace std;

typedef struct stuT{
    char id[7];
    char name[9];
    int grade;
}stuT;

bool compareStuID(stuT stu1, stuT stu2) {
    return strcmp(stu1.id, stu2.id) < 0;
}

bool compareStuName(stuT stu1, stuT stu2) {
    if (strcmp(stu1.name, stu2.name) == 0) {
        return strcmp(stu1.id, stu2.id) < 0;
    }
    return strcmp(stu1.name, stu2.name) < 0;
}

bool compareStuGrade(stuT stu1, stuT stu2) {
    if (stu1.grade == stu2.grade) {
        return strcmp(stu1.id, stu2.id) < 0;
    }
    return stu1.grade < stu2.grade;
}

int main(int argc, const char * argv[])
{
    scanf("%d %d", &N, &C);
    stuT vec[100000];
    for (int i = 0; i < N; i++) {
        scanf("%s %s %d",vec[i].id,vec[i].name,&vec[i].grade);
    }
    switch (C) {
        case 1:
            sort(vec, vec + N, compareStuID);
            break;
        case 2:
            sort(vec, vec + N, compareStuName);
            break;
        case 3:
            sort(vec, vec + N, compareStuGrade);
            break;
        default:
            break;
    }
    for (int i = 0; i < N; i++) {
        printf("%s %s %d\n", vec[i].id, vec[i].name, vec[i].grade);
    }
    return 0;
}

