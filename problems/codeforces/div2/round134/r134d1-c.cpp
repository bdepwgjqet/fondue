/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  08/18/2012 02:38:08 PM
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
#define N 1000010
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

int match[N],st[N],top,dp[N][2][2];

char s[N];

int get(int a,char sig,int b)
{
	if(sig=='&')
		return a&b;
	if(sig=='|')
		return a|b;
	return a^b;
}

void calc(int pl,int sp,int pr,int now)
{
	int x,y;
	for(int i=0; i<2; i++)
		for(int j=0; j<2; j++)
		{
			if(dp[pl][i][j]==0)
				continue;
			for(int u=0; u<2; u++)
				for(int v=0; v<2; v++)
				{
					if(dp[pr][u][v]==0)
						continue;
					x=get(i,s[sp],u);
					y=get(j,s[sp],v);
					dp[now][x][y]=1;
				}
		}
}

void solve(int l)
{
	int sp;
	for(int i=0; i<l; i++)
	{
		if(s[i]=='1')
			dp[i][1][1]=1;
		else if(s[i]=='0')
			dp[i][0][0]=1;
		else if(s[i]=='?')
			dp[i][0][1]=dp[i][1][0]=1;
		else if(s[i]==')')
		{
			if(s[i-1]==')')
				sp=match[i-1]-1;
			else
				sp=i-2;
			calc(sp-1,sp,i-1,i);
		}
	}
}

int main()
{
	int l,n;
	while(scanf("%d%s",&n,s)!=EOF)
	{
		l=strlen(s);
		top=-1;
		memset(dp,0,sizeof(dp));
		for(int i=0; i<l; i++)
		{
			if(s[i]=='(')
				st[++top]=i;
			else if(s[i]==')')
			{
				match[st[top]]=i;
				match[i]=st[top];
				top--;
			}
		}
		solve(l);
		if(dp[l-1][0][1]||dp[l-1][1][0])
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
