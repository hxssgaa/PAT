//
//  main.cpp
//  PATA1029
//
//  此题好欢快，居然发现有merge函数可以直接用,这也太爽了....
//  1.同样对于大数据的处理，只能scanf, printf, 并且不能用vector
//  2.对于大量数组，只能发到局部变量中，函数中无法定义
//  Created by Xin Huang on 5/9/14.
//  Copyright (c) 2014 David Huang. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
long seq1[1000010];
long seq2[1000010];
long seq3[2000020];

int main(int argc, const char * argv[])
{
    int N, M;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%li", &seq1[i]);
    }
    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        scanf("%ld", &seq2[i]);
    }
    merge(seq1, seq1 + N, seq2, seq2 + M, seq3);
    printf("%ld", (N + M) % 2 == 0 ? seq3[(N + M) / 2 - 1] : seq3[(N + M) / 2]);
    
    return 0;
}

