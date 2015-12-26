/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  09/20/2012 12:19:20 AM
 ***/

#include <cstring>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <sstream>
#include <cmath>
#include <functional>
#include <iostream>
#include <algorithm>
#define N 1010
#define M 1000010
#define S 1000100
#define eps 1e-8
#define inf 0x3ffffff
#define MOD 1000000007
#define PB push_back
#define MP make_pair
#define SZ(a) ((int)((a).size()))
#define ALL(a) (a).begin(),(a).end()
#define CLR(a,x) memset(a,x,sizeof(a))

typedef long long LL;
using namespace std;

char s[N][N];
int cnt[N][2],l,r,n,m,dp[N][N][2];

int dfs(int id,int len,int tag)
{
	if(dp[id][len][tag]>=0)
		return dp[id][len][tag];
	if(id==n)
	{
		if(len>=l&&len<=r)
			return dp[id][len][tag]=0;
		return dp[id][len][tag]=inf;
	}

	int ret=inf;
	if(len<l)
		return dp[id][len][tag]=dfs(id+1,len+1,tag)+cnt[id][tag];
	if(len==r)
		return dp[id][len][tag]=dfs(id+1,1,tag^1)+cnt[id][tag^1];
	ret=dfs(id+1,len+1,tag)+cnt[id][tag];
	ret=min(ret,dfs(id+1,1,tag^1)+cnt[id][tag^1]);
	return dp[id][len][tag]=ret;
}

int main()
{
	while(scanf("%d%d%d%d",&m,&n,&l,&r)!=EOF)
	{
		for(int i=0; i<m; i++)
			scanf("%s",s[i]);
		memset(cnt,0,sizeof(cnt));
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<m; j++)
			{
				if(s[j][i]=='.')
					cnt[i][0]++;
				else
					cnt[i][1]++;
			}
		}
		memset(dp,-1,sizeof(dp));
		dfs(1,1,0);
		dfs(1,1,1);
		printf("%d\n",min(dp[1][1][0]+cnt[0][0],dp[1][1][1]+cnt[0][1]));
	}
	return 0;
}
