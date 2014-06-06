//
//  main.cpp
//  PATA1021
//
//  此题对于N很大的图可以采用二级vector<vector<int> >的方式来表示
//  只需要刚开始assign vector,然后push的是节点下标.
//
//  对于图的环检查，通过对每一个节点进行DFS，没经过一个结点就使之就可以了
//
//  Created by Xin Huang on 5/4/14.
//  Copyright (c) 2014 David Huang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int N, connected = 0;
vector<vector<int>>graph;
vector<bool>visited;

//visit the node in the graph by DFS, set the visited mark for each passing route.
void visit(int i)
{
    visited[i] = 1;
    for(int j = 0; j < graph[i].size(); j++)
    {
        if(!visited[graph[i][j]])
        {
            visit(graph[i][j]);
        }
    }
}

//query the number of connected components in the graph by iterating visiting every node in the graph
void checkTree()
{
    for(int i = 1; i <= N; i++)
    {
        if(!visited[i])
        {
            visit(i);
            connected++;
        }
    }
}

//get the deepth from the node in the tree if this node is the root.
int heightOfTree(int root)
{
    int maxHeight = 1;
    for (int i = 0; i < graph[root].size(); i++) {
        int height = 1;
        if (!visited[graph[root][i]]) {
            visited[graph[root][i]] = true;
            height += heightOfTree(graph[root][i]);
            if (height > maxHeight) maxHeight = height;
            visited[graph[root][i]] = false;
        }
    }
    return maxHeight;
}

int main(int argc, const char * argv[])
{
    cin >> N;
    int x, y;
    graph.assign(N + 1, vector<int>());//init graph vector, so we can push_back directly
    visited.assign(N + 1, 0);//init the visited vector
    for (int i = 0; i < N - 1; i++) {
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    checkTree();
    visited.assign(N + 1, 0);
    if (connected > 1) {
        cout << "Error: " << connected << " components";
    } else {
        int maxHeight = 0;
        vector<int> vec;
        for (int i = 1; i <= N; i++) {
            visited[i] = true;
            int height = heightOfTree(i);
            if (height > maxHeight) {
                vec.clear();
                maxHeight = height;
            }
            if (height == maxHeight) {
                vec.push_back(i);
            }
            visited[i] = false;
        }
        sort(vec.begin(), vec.end());
        for (int eachRoot : vec) {
            cout << eachRoot << endl;
        }
    }
    return 0;
}

