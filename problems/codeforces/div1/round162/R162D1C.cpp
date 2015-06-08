#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 100011
#define inf 0x3fffffffffffffLL

typedef long long LL;
using namespace std;

LL dp[N];
int v[N],c[N],vis[N];

struct node{ int c; LL v; }no[2];

void gao(LL a,LL b,int n)
{
	memset(dp,0,sizeof(dp));
	memset(vis,0,sizeof(vis));
	no[0].c=no[1].c=-1;
	no[0].v=no[1].v=0;
	LL ret=0;
	for(int i=0; i<n; i++)
	{
		LL now=b*v[i];
		if(vis[c[i]])
			now=max(now,dp[c[i]]+a*v[i]);

		if(no[0].c==c[i])
			now=max(now,no[1].v+b*v[i]);
		else
			now=max(now,no[0].v+b*v[i]);

		if(vis[c[i]])
			dp[c[i]]=max(dp[c[i]],now);
		else
			dp[c[i]]=now;
		vis[c[i]]=1;

		if(c[i]==no[0].c)
			no[0].v=max(no[0].v,now);
		else if(c[i]==no[1].c)
			no[1].v=max(no[1].v,now);
		else
		{
			if(no[1].v<now)
				no[1].v=now,no[1].c=c[i];
		}
		if(no[0].v<no[1].v)
			swap(no[0],no[1]);
		ret=max(ret,now);
	}
	cout<<ret<<endl;
}

int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=0; i<n; i++)
		scanf("%d",&v[i]);
	for(int i=0; i<n; i++)
		scanf("%d",&c[i]);
	for(int i=0; i<q; i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		gao(a,b,n);
	}
	return 0;
}
