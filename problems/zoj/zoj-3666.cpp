#include <cstdio>
#include <vector>
#define N 11000

using namespace std;

vector<int> tr[N];
int tag[N];

int flag[4][4]={0,0,0,0,
	0,1,2,3,
	0,2,1,3,
	0,3,3,1
};

int n;

inline int B(int i){ return 1<<i; }

int dfs(int now)
{
	int ret=0;
	for(int i=0; i<tr[now].size(); i++)
	{
		int to=tr[now][i];
		if(tag[to]>=0)
		{
			if(tag[to]&B(0))
			{
				ret|=B(1);
				if(tag[to]&B(2))
					ret|=B(2);
			}
			else
				ret|=B(0);
		}
		else
		{
			int tg=dfs(to);
			if(tg&B(0))
			{
				ret|=B(1);
				if(tg&B(2))
					ret|=B(2);
			}
			else
				ret|=B(0);
		}
	}
	if(ret==0)
		ret=B(0);
	if((ret&B(0))&&(ret&B(1)))
		ret|=B(2);
	return tag[now]=ret;
}

int main()
{
	int ca=1;
	while(scanf("%d",&n)+1)
	{
		for(int i=0; i<n; i++)
			tr[i].clear();
		printf("Case %d:\n",ca++);
		for(int i=0; i<n-1; i++)
		{
			int m;
			scanf("%d",&m);
			for(int j=0; j<m; j++)
			{
				int x;
				scanf("%d",&x);
				tr[i].push_back(x-1);
			}
		}
		for(int i=0; i<n; i++)
			tag[i]=-1;
		for(int i=0; i<n; i++)
			if(tag[i]==-1)
			{
				dfs(i);
			}
		/*
		for(int i=0; i<n; i++)
			printf ("%d %d=>\n",i+1,tag[i]);
		puts("");
		*/
		int q;
		scanf("%d",&q);
		for(int i=0; i<q; i++)
		{
			int m,x;
			scanf("%d%d",&m,&x);
			int ret=tag[x-1]&3;
			for(int j=1; j<m; j++)
			{
				int x;
				scanf("%d",&x);
				ret=flag[tag[x-1]&3][ret];
			}
			if(ret&B(1))
				puts("Alice");
			else
				puts("Bob");
		}
	}
	return 0;
}
