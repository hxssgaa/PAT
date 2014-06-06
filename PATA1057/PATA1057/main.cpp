#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<stack>
using namespace std;

int N;

#define MAXN 100001

stack<int> data;
int statistic[MAXN];

int lowbit(int x)
{
	return x&(-x);
}

void edit(int i, int delta)
{
	for (int j = i; j <= MAXN; j += lowbit(j))
		statistic[j] += delta;
}

int sum(int k)
{
	int ans = 0;
	for (int i = k; i > 0; i -= lowbit(i))
		ans += statistic[i];
	return ans;
}

int findIndex(size_t k, int l = 0, int h = MAXN - 1) {
	while (l <= h)
	{
		int mid = (l + h) / 2;
		int sumValue = sum(mid);
		//printf("test:%d,value:%d,mid:%d\n", statistic[mid],sumValue,mid);
		//if (sumValue >= k && sumValue - statistic[mid] + 1 <= k) {
		if (l == h) {
			return l;
		}
		else if (sumValue < k) {
			l = mid + 1;
		}
		else
		{
			h = mid;
		}
	}
	return -1;
}

void push(int num) {
	data.push(num);
	edit(num, 1);
}

void pop() {
	if (data.empty()) {
		printf("Invalid\n");
		return;
	}
	printf("%d\n", data.top());
	edit(data.top(), -1);
	data.pop();
}

void peekMedian() {
	if (data.empty()) {
		printf("Invalid\n");
		return;
	}
	int num = findIndex(data.size() % 2 == 0 ? data.size() / 2 : ((data.size() + 1) / 2));
	printf("%d\n", num);
}

int main(){
	scanf("%d", &N);
	int i, pushNum;
	char s[20];
	for (i = 0; i < N; i++) {
		scanf("%s", s);
		if (s[1] == 'u') {
			scanf("%d", &pushNum);
			push(pushNum);
		}
		else if (s[1] == 'o')
		{
			pop();
		}
		else if (s[1] == 'e')
		{
			peekMedian();
		}
		else
		{
			printf("Invalid\n");
		}
	}
	return 0;
}