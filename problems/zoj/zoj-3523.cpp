#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#define inf 0x3fffffff
#define N 101

using namespace std;

struct node{ string s; int i; }no[N];

int cmp(node a,node b)
{
	return a.s<b.s;
}

char ss[N];

int m,n,dp[N][N],dat[N];

int dfs(int l,int mx)
{
	if(dp[l][mx]>=0)
		return dp[l][mx];
	if(l==n)
		return dp[l][mx]=0;
	int ret=inf;
	if(dat[l]>mx)
	{
		ret=min(ret,dfs(l+1,dat[l]));
		ret=min(ret,dfs(l+1,mx)+1);
	}
	else
		ret=dfs(l+1,mx)+1;
	return dp[l][mx]=ret;
}

int main()
{
	while(scanf("%d%d",&m,&n)+1)
	{
		getchar();
		int ret=0;
		for(int i=0; i<m; i++)
		{
			for(int j=0; j<n; j++)
			{
				gets(ss);
				no[j].s=string(ss);
				no[j].i=j;
			}
			sort(no,no+n,cmp);
			for(int i=0; i<n; i++)
				dat[i]=no[i].i+1;
			memset(dp,-1,sizeof(dp));
			ret+=dfs(0,0);
		}
		printf("%d\n",ret);
	}
}

