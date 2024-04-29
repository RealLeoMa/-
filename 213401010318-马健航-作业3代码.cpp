#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include<fstream>
#include<iostream>
#define SIZE 110
#define INF 0x3fffffff
using namespace std;
const int maxn = 100;
int dp[maxn], choice[maxn];
int temp =INF;
int map[SIZE][SIZE],visit[SIZE],len[SIZE];
int n,m;  
int j,pos,anss;
int DP(int i)
{
    if(dp[i] > 0) 
		return dp[i];
    for(int j=1; j<=n; j++)
	{
        if(map[i][j]!=INF)
		{
            int temp = map[i][j]+DP(j);
            if(temp > dp[i])
			{
                dp[i] = temp;
                choice[i] = j;
            }
        }

    }
    return dp[i];
}
int dijkstra(int from, int to)
{	 
    int i;  
    for(i = 1 ; i <= n ; i ++)
	{	 
        visit[i] = 0;	
        len[i] = map[from][i];	 
    }  
  
    for(i = 1 ; i < n ; ++i)
	{	 
        int min = INF;   
        for(j = 1 ; j <= n ; ++j)
		{	
            if(!visit[j] && min > len[j])
			{  
                pos = j;  
                min = len[j];  
            }  
        }  
        visit[pos] = 1;  
        for(j = 1 ; j <= n ; ++j)
		{
            if(!visit[j] && (len[j] > (len[pos] +map[pos][j])))		 
			{														 
                len[j] = len[pos] + map[pos][j];		
            }  
        }  
    }  
    return len[to];
}
int main()
{
	fill(choice, choice+maxn, -1);
	printf("请输入节点数，边数以及各条边信息：");
	scanf("%d %d",&n,&m);
	for(int i = 1 ; i <= n ; ++i)
	{										
        for(int j = 1 ; j <= n ; ++j)
		{  
            map[i][j] = INF;  
        }  
    }
	  
	int s,t,weight;
	for(int i = 1;i <=m;++i)
	{
		scanf("%d %d %d",&s,&t,&weight);
		map[s][t]  = weight;
	}
	for(int i = 1; i<=n; i++)
	{
        DP(i);
    }
	for(int i = 1 ; i <= n ; ++i)
	{
		for(int j = 1 ; j <= n ; ++j)
		{
			if(map[i][j] == temp)
				map[i][j] = map[j][i];
		}
	}
	int Maxx = 0, j = -1;
    for(int i = 1; i <= n; i++)
	{
        if(dp[i] > Maxx)
		{
            Maxx = dp[i];
            j = i;
        }
    }
    if(j != -1)
	{
        int ans = dp[j] ;
    }
	anss = dijkstra(1, n);
	printf("正常工期为：");
	printf("%d\n",dp[j]);
	printf("最短工期为：");
	printf("%d\n",anss);
	int max=dp[j]-anss;
	if(max<0)
	{
		cout<<"错误"<<endl;
	}
	else
	{
		max=max*500;
		cout<<"节省成本为："<<max<<endl;
	}
	system("pause");
} 

