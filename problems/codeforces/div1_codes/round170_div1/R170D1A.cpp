#include <cstdio>
#include <vector>
#include <set>
#include <cstring>
#define N 111

using namespace std;

set<int> la[N];
set<int>::iterator it;

int mp[N][N];
int vis[N];
int n,m,id[N],top,cnt[N];

int ok(int i,int j)
{
	for(it=la[i].begin(); it!=la[i].end(); it++)
	{
		if(la[j].count(*it)>0)
			return 1;
	}
	return 0;
}

void dfs(int now)
{
	vis[now]=1;
	id[now]=top;
	for(int i=0; i<n; i++)
		if(!vis[i])
			if(mp[now][i])
				dfs(i);
}

int main()
{
	memset(mp,0,sizeof(mp));
	scanf("%d%d",&n,&m);
	for(int i=0; i<n; i++)
	{
		int k;
		scanf("%d",&k);
		for(int j=0; j<k; j++)
		{
			int x;
			scanf("%d",&x);
			x--;
			la[i].insert(x);
		}
	}
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(i==j) continue;
			if(ok(i,j))
				mp[i][j]=mp[j][i]=1;
		}
	}
	memset(vis,0,sizeof(vis));
	memset(id,-1,sizeof(id));
	top=0;
	for(int i=0; i<n; i++)
		if(!vis[i])
		{
			dfs(i);
			top++;
		}
	memset(cnt,0,sizeof(cnt));
	for(int i=0; i<n; i++)
		if(la[i].size()>0)
			cnt[id[i]]=1;
	int ze=0;
	for(int i=0; i<top; i++)
		if(cnt[i]==0)
			ze++;
	printf("%d\n",top-1+(ze==top));
	return 0;
}
