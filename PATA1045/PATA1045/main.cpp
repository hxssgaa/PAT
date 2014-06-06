/*
 此题动态规划（DP）需要高度重视
 
 相关算法有LCS(最长子序列),LIS(最长递增子序列)
 做法主要利用递归式,从前向后运算
 
 */
#include <iostream>
using namespace std;

//动态规划
int main()
{
	int n;	//输入数据，颜色数量（在本算法中没用……）
	cin>>n;
	int i,j;
	int m,fav[200];	//喜欢的颜色数量，各个喜欢的颜色
	cin>>m;
	for(i=0;i<m;i++)
		scanf("%d",&fav[i]);
	int l,*color;	//色带颜色数，色带上的颜色
	cin>>l;
	color=new int[l];
	for(i=0;i<l;i++)
		scanf("%d",&color[i]);
    
	int *data;	//表示喜欢的颜色到编号j时的最多可以获得的长度(从0开始计数)
	data=new int[m];
	
	for(i=0;i<l;i++)	//自前向后运算
		for(j=0;j<m;j++)
			if(color[i]==fav[j])	//第i个颜色是第j个喜欢的颜色
				data[j]++;
			else if(j!=0&&data[j-1]>data[j])	//不是，j不为0（不是第一个喜欢的颜色），且第j-1个喜欢的颜色的子串比第j个长
				data[j]=data[j-1];
    
	cout<<data[m-1];
    
	delete[] data;
    
	return 0;
}
