/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  04/06/2012 04:50:24 PM
 ***/

#include <cstring>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cmath>
#include <iostream>
#include <algorithm>
#define N 510
#define M 1000010
#define S 1000100
#define MOD 1000000007

typedef long long LL;
using namespace std;

inline int L(int i){ return i<<1; }
inline int R(int i){ return (i<<1)|1; }
inline int B(int i){ return 1<<i; }
inline int low_bit(int x){ return x&(-x); }

int mat[N][N],dp[N];
char s[N][N];

int ok(int i,int j)
{
	if(s[i][j]=='1'&&s[i+1][j]=='1'&&s[i][j+1]=='1'&&s[i][j-1]=='1'&&s[i-1][j]=='1')
		return 1;
	return 0;
}

int main()
{
	int n,m,k;
	LL ret=0;
	while(scanf("%d%d%d",&n,&m,&k)!=EOF)
	{
		memset(mat,0,sizeof(mat));
		for(int i=0; i<n; i++)
			scanf("%s",s[i]);
		for(int i=1; i<n-1; i++)
			for(int j=1; j<m-1; j++)
			{
				mat[i][j]=mat[i][j-1];
				if(ok(i,j))
					mat[i][j]+=1;
			}
		/*
		for(int i=0; i<n; i++,puts(""))
			for(int j=0; j<m; j++)
				printf("%d ",mat[i][j]);
				*/
		ret=0;
		for(int i=0; i<m; i++)
			for(int j=i+2; j<m; j++)
			{
				for(int u=0; u<n; u++)
					dp[u]=mat[u][j-1]-mat[u][i];
				/*
				for(int u=0; u<n; u++)
					printf("%d ",dp[u]);
				puts("");
				*/
				int u=0,v=u+2,cnt=dp[v-1];
				for(; u<n&&v<n; u++)
				{
					cnt-=dp[u];
					for(; cnt<k&&v<n; v++)
						cnt+=dp[v];
					ret+=n-v;
				}
			}
		//printf("%d\n",ret);
		cout<<ret<<endl;
	}
	return 0;
}


