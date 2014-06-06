//
//  main.cpp
//  PATA1036
//
//  Created by Xin Huang on 5/12/14.
//  Copyright (c) 2014 David Huang. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int N;

typedef struct stuT{
    char name[11];
    char gender;
    char ID[11];
    int grade;
}stuT;

int main(int argc, const char * argv[])
{
    scanf("%d", &N);
    stuT *lowestGradeBoy = NULL;
    stuT *highestGradeGirl = NULL;
    stuT *cur = NULL;
    for (int i = 0; i < N; i++) {
        cur = new stuT;
        scanf("%s %c %s %d", cur->name, &cur->gender, cur->ID, &cur->grade);
        if (cur->gender == 'M') {
            if (lowestGradeBoy == NULL) {
                lowestGradeBoy = cur;
                continue;
            }
            if (cur->grade < lowestGradeBoy->grade) {
                lowestGradeBoy = cur;
            }
        } else {
            if (highestGradeGirl == NULL) {
                highestGradeGirl = cur;
                continue;
            }
            if (cur->grade > highestGradeGirl->grade) {
                highestGradeGirl = cur;
            }
        }
    }
    if (highestGradeGirl == NULL) {
        printf("Absent\n");
    } else {
        printf("%s %s\n", highestGradeGirl->name, highestGradeGirl->ID);
    }
    if (lowestGradeBoy == NULL) {
        printf("Absent\n");
    } else {
        printf("%s %s\n", lowestGradeBoy->name, lowestGradeBoy->ID);
    }
    if (highestGradeGirl == NULL || lowestGradeBoy == NULL) {
        printf("NA\n");
    } else {
        printf("%d\n", highestGradeGirl->grade - lowestGradeBoy->grade);
    }
    return 0;
}

