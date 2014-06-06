// PATA1012.cpp : Defines the entry point for the console application.
/*
 
 To evaluate the performance of our first year CS majored students,
 we consider their grades of three courses only: C - C Programming Language,
 M - Mathematics (Calculus or Linear Algrbra), and E - English.
 At the mean time, we encourage students by emphasizing on their best ranks
 -- that is, among the four ranks with respect to the three courses and
 the average grade, we print the best rank for each student.
 
 For example, The grades of C, M, E and A - Average of 4 students are
 given as the following:
 
 StudentID  C  M  E  A
 310101     98 85 88 90
 310102     70 95 88 84
 310103     82 87 94 88
 310104     91 91 91 91
 Then the best ranks for all the students are No.1 since
 the 1st one has done the best in C Programming Language,
 while the 2nd one in Mathematics, the 3rd one in English,
 and the last one in average.
 
 Input
 
 Each input file contains one test case.
 Each case starts with a line containing 2 numbers N and M (<=2000),
 which are the total number of students,
 and the number of students who would check their ranks, respectively.
 Then N lines follow, each contains a student ID which
 is a string of 6 digits, followed by the t
 hree integer grades (in the range of [0, 100])
 of that student in the order of C, M and E.
 Then there are M lines, each containing a student ID.
 
 Output
 
 For each of the M students, print in one line the best rank
 for him/her, and the symbol of the corresponding rank, separated by a space.
 
 The priorities of the ranking methods are ordered as A > C > M > E.
 Hence if there are two or more ways for a student to obtain the same
 best rank, output the one with the highest priority.
 
 If a student is not on the grading list, simply output "N/A".
 
 Sample Input
 5 6
 310101 98 85 88
 310102 70 95 88
 310103 82 87 94
 310104 91 91 91
 310105 85 90 90
 310101
 310102
 310103
 310104
 310105
 999999
 
 Sample Output
 1 C
 1 M
 1 E
 1 A
 3 A
 N/A
 
 5 5
 1000 80 82 84
 1001 80 82 86
 1002 80 82 88
 1003 81 83 40
 1004 81 83 41
 1000
 1001
 1002
 1003
 1004

 */
//
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef struct stuT
{
	string id;
	int C, M, E, A;
}stuT;

int *calculateRank(vector<stuT *>vec, stuT *fStu) {
	int *rank = new int[4];
	for (int i = 0; i < 4; i++) {
		rank[i] = 1;
	}
	for (stuT *stu : vec) {
		if (stu == fStu) continue;
		if (stu->A > fStu->A) {
			rank[0]++;
		}
		if (stu->C > fStu->C) {
			rank[1]++;
		}
		if (stu->M > fStu->M) {
			rank[2]++;
		}
		if (stu->E > fStu->E) {
			rank[3]++;
		}
	}
	return rank;
}

int main()
{
	map<int, char>subjectMap;
	subjectMap.insert(pair<int, char>(0, 'A'));
	subjectMap.insert(pair<int, char>(1, 'C'));
	subjectMap.insert(pair<int, char>(2, 'M'));
	subjectMap.insert(pair<int, char>(3, 'E'));
	int N, M;
	cin >> N >> M;
	stuT *stu = NULL;
	string id;
	int C, Ma, E, A;
	map<string, stuT*> stuMap;
	vector<stuT *>stuVec;
	for (int i = 0; i < N; i++) {
		stu = new stuT;
		cin >> id >> C >> Ma >> E;
		A = (C + Ma + E);
		stu->id = id;
		stu->C = C;
		stu->M = Ma;
		stu->E = E;
		stu->A = A;
		stuVec.push_back(stu);
		stuMap.insert(pair<string, stuT*>(id, stu));
	}
	vector<string> query;
	for (int i = 0; i < M; i++) {
		cin >> id;
		query.push_back(id);
	}
	for (string q : query) {
		if (stuMap.find(q) == stuMap.end()) {
			cout << "N/A" << endl;
			continue;
		}
		int *rank = calculateRank(stuVec, stuMap[q]);
		int hRank = rank[0];
		int hSubj = 0;
		for (int i = 1; i < 4; i++) {
			int ranki = rank[i];
			if (ranki < hRank) {
				hRank = ranki;
				hSubj = i;
			}
		}
		cout << hRank << " " << subjectMap[hSubj] << endl;
	}
	return 0;
}

