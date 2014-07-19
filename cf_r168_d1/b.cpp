#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#define N 100101
#define inf 2000000000

typedef long long LL;
using namespace std;

LL v[N],ps[N],qs[N];
vector<int> tr[N];

void dfs(int now,int p)
{
	ps[now]=qs[now]=0;
	for(int i=0; i<tr[now].size(); i++)
	{
		int to=tr[now][i];
		if(to==p)
			continue;
		dfs(to,now);
		ps[now]=max(ps[now],ps[to]);
		qs[now]=min(qs[now],qs[to]);
	}
	LL x=v[now]-ps[now]-qs[now];
	if(x>0)
		ps[now]+=x;
	else
		qs[now]+=x;
}

void gao(int n)
{
	dfs(0,-1);
	cout<<ps[0]-qs[0]<<endl;
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0; i<n; i++)
		tr[i].clear();
	for(int i=0; i<n-1; i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		x--,y--;
		tr[x].push_back(y);
		tr[y].push_back(x);
	}
	for(int i=0; i<n; i++)
	{
		int x;
		scanf("%d",&x);
		v[i]=x;
	}
	gao(n);
	return 0;
}
