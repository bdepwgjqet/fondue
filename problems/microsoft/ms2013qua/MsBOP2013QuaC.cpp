#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#define N 100011

using namespace std;

vector<pair<int,int> > tr[N];
vector<int> vec;

int lev[N],pre[N][18],len[N];

inline int B(int i){ return 1<<i; }

void add(int v,int p)
{
	for(; v!=p; v=pre[v][0])
		vec.push_back(len[v]);
}

void dfs(int now,int p,int d)
{
	lev[now]=d;
	pre[now][0]=p;
	for(int i=0; i<tr[now].size(); i++)
	{
		int to=tr[now][i].first;
		if(to==p) continue;
		len[to]=tr[now][i].second;
		dfs(to,now,d+1);
	}
}

int cal(int x,int y)
{
	if(lev[x]>lev[y]) return cal(y,x);
	int d=lev[y]-lev[x];
	for(int i=0; i<18; i++)
		if(d&B(i))
		{
			y=pre[y][i];
		}
	if(x==y) return x;
	for(int i=17; i>=0; i--)
	{
		if(pre[x][i]==pre[y][i])
			continue;
		x=pre[x][i],y=pre[y][i];
	}
	return pre[x][0];
}

int main()
{
	int T,n;
	scanf("%d",&T);
	for(int ca=1; ca<=T; ca++)
	{
		printf("Case #%d:\n",ca);
		scanf("%d",&n);
		for(int i=0; i<n; i++) tr[i].clear();
		for(int i=0; i<n-1; i++)
		{
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			x--,y--;
			tr[x].push_back(make_pair(y,z));
			tr[y].push_back(make_pair(x,z));
		}
		dfs(0,-1,0);
		for(int i=1; i<18; i++)
			for(int j=0; j<n; j++)
				pre[j][i]=pre[pre[j][i-1]][i-1];
		int m;
		scanf("%d",&m);
		for(int i=0; i<m; i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			x--,y--;
			int p=cal(x,y);
			vec.clear();
			add(x,p);
			add(y,p);
			sort(vec.begin(),vec.end());
			int tag=0;
			for(int i=2; i<vec.size(); i++)
				if(vec[i-2]+vec[i-1]>vec[i])
					tag=1;
			if(tag) puts("Yes");
			else puts("No");
		}
	}
	return 0;
}
