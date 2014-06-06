#include <iostream>
#include <vector>
#include <map>

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

void solvePolyProduct(vector<pair<int, double> > &vecA, vector<pair<int, double> > &vecB, map<int, double> &result) {
	for (pair<int, double> eachPA : vecA) {
        for (pair<int, double> eachPB : vecB) {
            int first = eachPA.first + eachPB.first;
            double second = eachPA.second * eachPB.second;
            //为什么这里不能判断second == 0 就continue是考虑到赋值相加的问题，这里特别注意.
            if (result.find(first) != result.end()) {
                result[first] = second + result[first];
            } else {
                result.insert(pair<int, double>(first, second));
            }
        }
    }
    //在最后删除所有为0的元素是正确的.
    for(map<int,double>::iterator it=result.begin(); it!=result.end();) {
        if (it->second == 0.0) {
            result.erase(it++);
        }
        else it++;
    }
}

int main()
{
	int nzA,nzB;
	cin >> nzA;
	vector<pair<int, double> > polyVecA = getPolyVec(nzA);
	cin >> nzB;
	vector<pair<int, double> > polyVecB = getPolyVec(nzB);
	map<int, double> result;
	solvePolyProduct(polyVecA, polyVecB, result);
    
	if (result.size() == 0) {
		cout << 0;
	}
	else {
		cout << result.size() << " ";
	}
	for (map<int, double>::reverse_iterator it = result.rbegin(); it != result.rend(); ++it) {
        if (next(it) == result.rend()) {
            printf("%i %.1f",it->first, it->second);
        } else {
            printf("%i %.1f ",it->first, it->second);
        }
    }
	return 0;
}

