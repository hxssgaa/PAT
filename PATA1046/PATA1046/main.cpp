/*
此优化题必须采用优化算法，将每一个Distance距起点的距离储存起来，
并利用remaining = total - distance利用最小值判断距离最小
 
 
 */

#include<iostream>
#include<cmath>
using namespace std;
#define MAX 100000
int dis[MAX];

int min(int a,int b){
	if(a>b) return b;
	else
		return a;
}

int main()
{
	int N,M;
	int total = 0; //如果变量没有初始化便进行运算，会出错。
	int i,j,temp;
	int begin,end;
	cin>>N;
	dis[1] = 0;
	for(i=1; i<=N; i++){
		cin>>temp;
		total += temp;
		dis[i+1] = dis[i] + temp;
	}
    
	cin>>M;
	while(M--){
		cin>>begin>>end;
        
		temp = abs(dis[end] - dis[begin]);
		cout<<min( temp,total-temp )<<endl;
	}
    
	return 0;
}