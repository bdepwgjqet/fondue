/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  03/10/2012 10:25:47 PM
 ***/

#include <cstring>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>
#define MAXN 10000011
#define MAXM 1000010
#define MOD 1000000007

typedef long long LL;
using namespace std;

inline int L(int i){ return i<<1; }
inline int R(int i){ return (i<<1)|1; }
inline int max(int a,int b){ return a<b?b:a; }
inline int min(int a,int b){ return a<b?a:b; }
inline int abs(int x){ return x<0?-x:x; }

int n,dp[MAXN],cnt[111],D[111],sum,res;

struct data{ char s[110]; int l; }dat[111];

inline int cmp(data a,data b){ return a.l<b.l; }

void init()
{
	int i;
	memset(D,0,sizeof(D));
	sum=D[0]=1;
	res=0;
	for(i=1; i<n; i++)
		D[i]=D[i-1]*dat[i-1].l,sum+=D[i];
	for(i=0; i<n; i++)
		res+=D[i]*(dat[i].l-1);
}

void dfs(int now,int id)
{
	int i,tag,tt;
	char x;
	if(now==n)
	{
		x=dat[0].s[cnt[0]];
		for(tt=tag=1,i=0; i<n; i++)
		{
			if(x!=dat[i].s[cnt[i]])
				tag=0;
			if(cnt[i]>0)
			{
				dp[id]=max(dp[id],dp[id-D[i]]);
			}
			else
				tt=0;
		}
		if(tag)
		{
			if(tt==0)
				dp[id]=max(dp[id],1);
			else
				dp[id]=max(dp[id],dp[id-sum]+1);
		}
		return;
	}

	for(i=0; i<dat[now].l; i++)
	{
		cnt[now]=i;
		dfs(now+1,id+i*D[now]);
	}
}

int main()
{
	int i;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0; i<n; i++)
		{
			scanf("%s",dat[i].s);
			dat[i].l=strlen(dat[i].s);
//			printf("%d=>",dat[i].l);
		}
		sort(dat,dat+n,cmp);
		init();
		memset(cnt,0,sizeof(cnt));
		memset(dp,0,sizeof(dp));
		dfs(0,0);
		printf("%d\n",dp[res]);
	}
	return 0;
}
