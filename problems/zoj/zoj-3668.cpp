#include <cstdio>
#include <cassert>
#include <vector>
#include <utility>
#define N 1111
#define M 1000000
#define inf 0x3fffffff

using namespace std; 

int n,m;
int q[M],dis[N],cnt[N],inq[N];
vector<pair<int,int> > vec[N];

void insert(int f,int t,int l)
{
	vec[f].push_back(make_pair(t,l));
}

inline int get(int &i){ return (++i)%M; }

int spfa(int s)
{
	int l=0,r=1;
	q[0]=s;
	dis[s]=0;
	inq[s]=1;

	for(; l!=r;)
	{
		int now=q[l++];
		if (l == M) l = 0;
		inq[now]=0;
		if(cnt[now]>n) return 0;

		for(int i=0; i<vec[now].size(); i++)
		{
			int to=vec[now][i].first,l=vec[now][i].second;
			if(dis[now]+l<dis[to])
			{
				dis[to]=dis[now]+l;
				if(inq[to]) continue;
				q[r++]=to;
				if (r == M) r = 0;
				cnt[to]++;
				inq[to]=1;
			}
		}
	}
	return 1;
}

int main()
{
	while(scanf("%d%d",&n,&m)+1)
	{
		for(int i=0; i<n+3; i++)
			vec[i].clear();
		for(int i=0; i<m; i++)
		{
			int l,r,x,y;
			scanf("%d%d%d%d",&l,&r,&x,&y);
			insert(l-1,r,y);
			insert(r,l-1,-x);
		}
		for(int i=1; i<=n; i++)
		{
			insert(i-1,i,10000);
			insert(i,i-1,10000);
		}
		for(int i=0; i<=n+2; i++)
			dis[i]=inf,cnt[i]=0,inq[i]=0;
		int tag=spfa(0);
		if(tag)
		{
			printf("%d",dis[1]);
			for(int i=2; i<=n; i++)
				printf(" %d",dis[i]-dis[i-1]);
			puts("");
		}
		else
			puts("The spacecraft is broken!");
	}
	return 0;
}
