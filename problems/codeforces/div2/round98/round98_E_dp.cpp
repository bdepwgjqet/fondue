/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  04/09/2012 08:28:02 PM
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
#define N 200010
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

int dp[N],q[N],top;
char s[N];

int del(char x)
{
	if('A'<=x&&x<='Z')
		x+='a'-'A';
	return x=='a'||x=='e'||x=='i'||x=='o'||x=='u';
}

int find(int x)
{
	int l=0,r=top-1,m;
	for(; l<=r; )
	{
		m=(l+r)>>1;
		if(dp[q[m]]>x)
			l=m+1;
		else
			r=m-1;
	}
	return l;
}

int main()
{
	int ret,l,x,id,cnt;
	while(scanf("%s",s)!=EOF)
	{
		l=strlen(s);
		ret=dp[0]=0;
		for(int i=0; i<l; i++)
		{
			if(del(s[i]))
				dp[i+1]=dp[i]-1;
			else
				dp[i+1]=dp[i]+2;
		}
		/*
		for(int i=0; i<=l; i++)
			printf("%d ",dp[i]);
		puts("");
		*/
		top=0;
		q[top++]=0;
		for(int i=1; i<=l; i++)
		{
			x=dp[q[top-1]];
			if(x<=dp[i])
			{
				id=find(dp[i]);
				if(i-q[id]>ret)
					ret=i-q[id];
			}
			else
				q[top++]=i;
		}
		if(ret==0)
		{
			puts("No solution");
			continue;
		}
		cnt=0;
		for(int i=0; i+ret<=l; i++)
			if(dp[i+ret]>=dp[i])
				cnt++;
		printf("%d %d\n",ret,cnt);
	}
	return 0;
}
