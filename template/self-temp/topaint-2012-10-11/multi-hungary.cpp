#include <cstdio>
#define N 1001
#define S 100001

struct edge{ int f,t,n; }e[S];
int list[N],top,y[N],match[N][N],cnt[N],lim[N];

void insert(int f,int t)
{
	e[top].f=f,e[top].t=t;
	e[top].n=list[f],list[f]=top++;
}

int find(int now)
{
	for(int i=list[now]; i!=-1; i=e[i].n)
	{
		int to=e[i].to;
		if(!y[to])
		{
			v[to]=1;
			if(cnt[to]<lim[to])
			{
				match[to][cnt[to]++]=now;
				return 1;
			}
			for(int j=0; j<cnt[to]; j++)
				if(find(match[to][j]))
				{
					match[to][j]=now;
					return 1;
				}
		}
	}
	return 0;
}

int multi_hungary(int m,int n)
{
	int ret=0;
	memset(cnt,0,sizeof(cnt));
	for(int i=0; i<m; i++)
	{
		memset(y,0,sizeof(y));
		if(find(i))
			ret++;
	}
	return ret;
}
