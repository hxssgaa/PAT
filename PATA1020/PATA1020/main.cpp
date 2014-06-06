#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <sstream>
#include <queue>

int N;
int postOrder[30];
int inOrder[30];

typedef struct nodeT
{
	nodeT *left;
	nodeT *right;
	int key;
}nodeT;

using namespace std;

int findIndex(int *num, int length, int found) {
	for (int i = 0; i < length; i++) {
		if (num[i] == found) return i;
	}
	return -1;
}

//solve pre-order tree traversals by in-order and post-order tree traversals
nodeT* getPreOrder(int *inorder, int *postorder, int length)
{
	if (length == 0)
	{
		return NULL;
	}
	nodeT* node = new nodeT;//Noice that [new] should be written out.
	node->key = *(postorder + length - 1);
	cout << node->key;
	int rootIndex = findIndex(inorder, length, *(postorder + length - 1));
	node->left = getPreOrder(inorder, postorder, rootIndex);
	node->right = getPreOrder(inorder + rootIndex + 1, postorder + rootIndex, length - (rootIndex + 1));
    
	return node;
}

//solve post-order tree traversals by in-order and pre-order tree traversals
nodeT *getPostOrder(int *inOrder, int *preOrder, int length) {
	if (length == 0) {
		return NULL;
	}
	nodeT *node = new nodeT;
	node->key = *preOrder;
	int split = findIndex(inOrder, length ,preOrder[0]);
	node->left = getPostOrder(inOrder, preOrder + 1, split);
	node->right = getPostOrder(inOrder + split + 1, preOrder + split + 1, length - 1 - split);
	cout << node->key;
	return node;
}

void printPostOrder(nodeT *root) {
	if (root == NULL) return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout << root->key;
}

void printPreOrder(nodeT *root) {
	if (root != NULL) {
		cout << root->key;
		printPreOrder(root->left);
		printPreOrder(root->right);
	}
}

// level tree tranversals
void printLevelOrder(nodeT* root) {
	queue<nodeT *> q;
	q.push(root);
	string result = "";
	while (!q.empty())
	{
		nodeT *node = q.front();
		stringstream ss;
		ss << node->key;
		result += (ss.str() + " ");
		q.pop();
		if (node->left != NULL) {
			q.push(node->left);
		}
		if (node->right != NULL) {
			q.push(node->right);
		}
	}
	result = result.substr(0, result.size() - 1);
	cout << result;
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> postOrder[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> inOrder[i];
	}
	nodeT *root = getPreOrder(inOrder, postOrder, N);
	cout << endl;
	printPreOrder(root);
	cout << endl;
	printLevelOrder(root);
    
	/*
     nodeT *root = getPostOrder(inOrder, postOrder, N);
     cout << endl;
     printPostOrder(root);
     cout << endl;
     printLevelOrder(root);
     */
	return 0;
}