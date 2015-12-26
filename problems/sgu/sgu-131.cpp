/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  07/28/2012 11:03:25 AM
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
#define N 11
#define M 1000010
#define S 1000100
#define eps 1e-8
#define inf 0x3fffffff
#define MOD 1000000007
#define PB push_back
#define MP make_pair
#define SZ(a) ((int)((a).size()))
#define ALL(a) (a).begin(),(a).end()
#define CLR(a,x) memset(a,x,sizeof(a))

typedef long long LL;
using namespace std;

LL dp[N][1<<N];
int m,n;
inline int B(int i){ return 1<<i; }

void dfs(int lay,int id,int st,int nst)
{
	if(id==n)
	{
		dp[lay+1][nst]+=dp[lay][st];
		return ;
	}
	if(st&B(id))
		dfs(lay,id+1,st,nst);
	else
	{
		if((nst&B(id))==0)
		{
			dfs(lay,id+1,st,nst+B(id));
			if(id>0&&(nst&B(id-1))==0)
				dfs(lay,id+1,st,nst+B(id-1)+B(id));
			if(id+1<n&&(nst&B(id+1))==0)
				dfs(lay,id+1,st,nst+B(id)+B(id+1));
		}
		if(id+1<n&&(st&B(id+1))==0)
		{
			dfs(lay,id+2,st,nst);
			if((nst&B(id))==0)
				dfs(lay,id+2,st,nst+B(id));
			if((nst&B(id+1))==0)
				dfs(lay,id+2,st,nst+B(id+1));
		}
	}
}

int main()
{
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		memset(dp,0,sizeof(dp));
		dp[0][0]=1;
		for(int i=0; i<m; i++)
			for(int j=0; j<B(n); j++)
			{
				if(i==0&&j>=1)
					break;
				dfs(i,0,j,0);
			}
		cout<<dp[m][0]<<endl;
		//printf("%lld\n",dp[m][0]);
	}
	return 0;
}
