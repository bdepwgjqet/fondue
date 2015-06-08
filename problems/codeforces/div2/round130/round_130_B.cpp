/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  07/23/2012 11:12:43 PM
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
#define N 110
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

char s[N];
int dat[N];
int tag[N][N];
int dp[53][53][53][53];


int getv(char x)
{
	if(x<='9') return x-'0'-1;
	if(x=='T') return 9;
	if(x=='A') return 0;
	if(x=='J') return 10;
	if(x=='Q') return 11;
	if(x=='K') return 12;
}

int get(char x)
{
	if(x=='S') return 0;
	if(x=='D') return 1;
	if(x=='H') return 2;
	return 3;
}

int dfs(int l,int a,int b,int c)
{
	int ret=0,x,y,u,v;
	if(dp[l][a][b][c]>=0)
		return dp[l][a][b][c];
	if(l==2)
	{
		x=dat[2]%4,y=dat[1]%4;
		u=dat[2]/4,v=dat[1]/4;
		if(x==y||u==v)
			ret=1;
		if(ret==0)
			return dp[l][a][b][c]=0;
		ret=0;
		x=dat[2]%4,y=dat[0]%4;
		u=dat[2]/4,v=dat[0]/4;
		if(x==y||u==v)
			ret=1;
		return dp[l][a][b][c]=ret;
	}
	x=dat[l]%4,y=dat[l-1]%4;
	u=dat[l]/4,v=dat[l-1]/4;
	if(x==y||u==v)
	{
		int tmp=dat[l-1];
		dat[l-1]=dat[l];
		if(dfs(l-1,a,c,dat[l-3]))
			ret=1;
		dat[l-1]=tmp;
	}
	x=dat[l]%4,y=dat[l-3]%4;
	u=dat[l]/4,v=dat[l-3]/4;
	if(x==y||u==v)
	{
		int tmp=dat[l-3];
		dat[l-3]=dat[l];
		if(dfs(l-1,b,c,dat[l-3]))
			ret=1;
		dat[l-3]=tmp;
	}
	return dp[l][a][b][c]=ret;
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		memset(dp,-1,sizeof(dp));
		for(int i=0; i<n; i++)
		{
			int x;
			scanf("%s",s);
			x=getv(s[0])*4;
			x+=get(s[1]);
			dat[i]=x;
		}
		if(n==1)
			puts("YES");
		else if(n==2)
		{
			if((dat[0]%4)==(dat[1]%4)||(dat[0]/4)==(dat[1]/4))
				puts("YES");
			else
				puts("NO");
		}
		else if(dfs(n-1,dat[n-1],dat[n-2],dat[n-3]))
		{
			puts("YES");
		}
		else
		{
			puts("NO");
		}
	}
	return 0;
}
