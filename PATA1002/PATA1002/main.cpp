#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

vector<pair<int, double> > getPolyVec(int nz) {
	int nk;
	double ank;
	vector<pair<int, double> > polyVec;
	for (int i = 0; i < nz; i++) {
		cin >> nk >> ank;
		polyVec.push_back(pair<int, double>(nk, ank));
	}
	return polyVec;
}

void solvePolySum(vector<pair<int, double> > &vecA, vector<pair<int, double> > &vecB, vector<pair<int, double> >&result) {
	if (vecA.size() == 0 && vecB.size() == 0) return;
	if (vecA.size() == 0) {
		for (int i = 0; i < vecB.size();i++) {
			result.push_back(vecB[i]);
		}
	}
	else if (vecB.size() == 0)
	{
		for (int i = 0; i < vecA.size(); i++) {
			result.push_back(vecA[i]);
		}
	}
	else {
		pair<int, double>vecAFirst = vecA[0];
		pair<int, double>vecBFirst = vecB[0];
		if (vecAFirst.first == vecBFirst.first) {
			if (vecAFirst.second + vecBFirst.second != 0) {
				pair <int, double> p(vecAFirst.first, vecAFirst.second + vecBFirst.second);
				result.push_back(p);
			}
			vecA.erase(vecA.begin());
			vecB.erase(vecB.begin());
		}
		else if (vecAFirst.first < vecBFirst.first)
		{
			result.push_back(vecBFirst);
			vecB.erase(vecB.begin());
		}
		else if (vecAFirst.first > vecBFirst.first)
		{
			result.push_back(vecAFirst);
			vecA.erase(vecA.begin());
		}
		solvePolySum(vecA, vecB, result);
	}
}

int main()
{
	int nzA,nzB;
	cin >> nzA;
	vector<pair<int, double> > polyVecA = getPolyVec(nzA);
	cin >> nzB;
	vector<pair<int, double> > polyVecB = getPolyVec(nzB);
	vector<pair<int, double> > result;
    
	solvePolySum(polyVecA, polyVecB, result);
    
	if (result.size() == 0) {
		cout << 0;
	}
	else {
		cout << result.size() << " ";
	}
	for (int i = 0; i < result.size(); i++) {
		if (i == result.size() - 1) {
			printf("%d %.1f", result[i].first, result[i].second);
		}
		else {
			printf("%d %.1f ", result[i].first, result[i].second);
		}
	}
	return 0;
}

