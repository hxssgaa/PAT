//
//  main.cpp
//  PATA1058
//  Mark
//  Created by Xin Huang on 6/6/14.
//  Copyright (c) 2014 David Huang. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[])
{
    bool plus = false;
    int galleon1, sickle1, knut1, galleon2, sickle2, knut2;
    scanf("%d.%d.%d", &galleon1, &sickle1, &knut1);
    scanf("%d.%d.%d", &galleon2, &sickle2, &knut2);
    int resultKnut = knut1 + knut2;
    if (resultKnut >= 29) {
        resultKnut -= 29;
        plus = true;
    }
    int resultSickle = sickle1 + sickle2 + (plus ? 1 : 0);
    if (resultSickle >= 17) {
        resultSickle -= 17;
        plus = true;
    } else {
        plus = false;
    }
    int resultGalleon = galleon1 + galleon2 + (plus ? 1 : 0);
    printf("%d.%d.%d", resultGalleon, resultSickle, resultKnut);
    return 0;
}

