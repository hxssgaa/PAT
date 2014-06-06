//
//  main.cpp
//  PATA1043
//
//  1.特别注意树的相关算法
//  2.特别注意树的下标计算方法，对于从字符串构建树而言
//  3.题目容易出错的点在于忽略了树只有左子树或右子树的情况
//  4.该题最好对Image of BST 和 BST分开考虑，合在一起考虑的话容易出错.

//  Created by Xin Huang on 5/18/14.
//  Copyright (c) 2014 David Huang. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <sstream>

using namespace std;

int keys[1000];
int N;
bool isBSTOrImageBST = true;

typedef struct nodeT{
    int key;
    nodeT *left;
    nodeT *right;
}nodeT;

nodeT *buildTree(int rootIndex, int length, bool isBST) {
    if (length <= 0) {
        return NULL;
    }
    int i;
    nodeT *root = new nodeT;
    root->key = keys[rootIndex];
    if (length == 1) {
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    int find = rootIndex + length;
    for (i = rootIndex + 1; i < rootIndex + length; i++) {
        if (isBST) {
            if (keys[i] >= keys[rootIndex]) {
                find = i;
                break;
            }
        } else {
            if (keys[i] < keys[rootIndex]) {
                find = i;
                break;
            }
        }
    }
    for (i = find; i < rootIndex + length; i++) {
        if (isBST) {
            if (keys[i] < keys[rootIndex]) {
                isBSTOrImageBST = false;
                return NULL;
            }
        } else {
            if (keys[i] >= keys[rootIndex]) {
                isBSTOrImageBST = false;
                return NULL;
            }
        }
    }
    root->left = buildTree(rootIndex + 1, find - (rootIndex + 1), isBST);
    root->right = buildTree(find, length - (find - rootIndex), isBST);
    return root;
}

void postOrder(nodeT *root, string &s) {
    if (root == NULL) return;
    postOrder(root->left, s);
    postOrder(root->right, s);
    stringstream ss;
    ss << root->key;
    s += (ss.str() + " ");
}

int main(int argc, const char * argv[])
{
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> keys[i];
    }
    nodeT *root = buildTree(0, N, false);
    if (!isBSTOrImageBST) {
        isBSTOrImageBST = true;
        root = buildTree(0, N, true);
    }
    if (!isBSTOrImageBST) cout << "NO";
    else {
        cout << "YES" << endl;
        string s;
        postOrder(root, s);
        s = s.substr(0,s.length() - 1);
        cout << s;
    }
    return 0;
}

