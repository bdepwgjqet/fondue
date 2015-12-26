#include <cstdio>
#include <cstring>
#include <vector>
#define N 111

using namespace std;

int dfn[N],ID,mx,id[N],low[N],time,top,st[N],vis[N];
vector<int> list[N];

void tar(int now)
{
	low[now]=dfn[now]=time++;
	st[++top]=now;
	vis[now]=1;
	for(int i=0; i<list[now].size(); i++)
	{
		int to=list[now][i];
		if(!dfn[to])
		{
			tar(to);
			low[now]=min(low[now],low[to]);
		}
		else if(vis[to])
			low[now]=min(low[now],dfn[to]);
	}
	if(dfn[now]==low[now])
	{
		int cnt=0;
		for(; top>=0; )
		{
			int x=st[top--];
			vis[x]=0;
			id[x]=ID;
			cnt++;
			if(x==now)
				break;
		}
		if(cnt<2)
			cnt=0;
		mx=max(mx,cnt);
		ID++;
	}
}

int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(int i=0; i<n; i++)
			list[i].clear();
		for(int i=0; i<m; i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			list[x].push_back(y);
		}
		int ret=N;
		for(int i=0; i<n; i++)
		{
			memset(vis,0,sizeof(vis));
			memset(dfn,0,sizeof(dfn));
			memset(low,0,sizeof(low));
			mx=0;
			ID=1;
			time=1;
			top=-1;
			dfn[i]=time++;
			id[i]=ID++;
			for(int j=0; j<n; j++)
				if(!dfn[j])
					tar(j);
			ret=min(ret,mx);
		}
		printf("%d\n",ret);
	}
	return 0;
}
