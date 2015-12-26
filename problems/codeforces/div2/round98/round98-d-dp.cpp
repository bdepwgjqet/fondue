/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  04/09/2012 07:05:46 PM
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
#define N 610
#define M 1000010
#define S 1000100
#define eps 1e-8
#define inf 0x3fffffff
#define MOD 1000000007
#define PB push_back
#define SZ(a) ((int)((a).size()))
#define ALL(a) (a).begin(),(a).end()
#define CLR(a,x) memset(a,x,sizeof(a))

typedef long long LL;
using namespace std;

inline int L(int i){ return i<<1; }
inline int R(int i){ return (i<<1)|1; }
inline int B(int i){ return 1<<i; }
inline int low_bit(int x){ return x&(-x); }

char s[N];
int dp[N][N],pal[N][N],pre[N][N];

void show(int l,int u)
{
	if(u<1)	return;
	show(pre[l][u],u-1);
	if(u>1)
		printf("+");
	for(int i=pre[l][u]+1; i<=l; i++)
		printf("%c",min(s[i],s[pre[l][u]+l-i+1]));
}

int main()
{
	int m,l;
	scanf("%s%d",s+1,&m);
	l=strlen(s+1);
	for(int i=1; i<=l; i++)
		for(int j=i; j<=l; j++)
		{
			pal[i][j]=0;
			for(int k=i; k<=j; k++)
				pal[i][j]+=(s[k]!=s[i+j-k]);
			pal[i][j]/=2;
		}
	for(int i=0; i<=l; i++)
		for(int j=0; j<=m; j++)
			dp[i][j]=inf;
	dp[0][0]=0;
	for(int i=1; i<=l; i++)
		for(int j=1; j<=m; j++)
		{
			for(int k=1; k<=i; k++)
			{
				if(dp[k-1][j-1]+pal[k][i]<dp[i][j])
				{
					dp[i][j]=dp[k-1][j-1]+pal[k][i];
					pre[i][j]=k-1;
				}
			}
		}
	int u,ret=inf;
	for(int i=1; i<=m; i++)
		if(ret>dp[l][i])
			ret=dp[l][i],u=i;
	printf("%d\n",ret);
	show(l,u);
	puts("");
	return 0;
}
