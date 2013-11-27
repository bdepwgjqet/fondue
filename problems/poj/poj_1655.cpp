#include <cstdio>
#include <algorithm>
#define N 20010
using namespace std;

struct edge{ int f,t,n; }e[N<<1];
int list[N],top;
struct node{ int s,mx; }no[N];

void insert(int f,int t)
{
	e[top].f=f,e[top].t=t;
	e[top].n=list[f],list[f]=top++;
}

void dfs(int now,int p,int n)
{
	no[now].s=1;
	no[now].mx=0;
	for(int i=list[now]; i!=-1; i=e[i].n)
	{
		int to=e[i].t;
		if(to==p)
			continue;
		dfs(to,now,n);
		no[now].mx=max(no[now].mx,no[to].s);
		no[now].s+=no[to].s;
	}
	no[now].mx=max(no[now].mx,n-no[now].s);
}

int main()
{
	int ts,n;
	scanf("%d",&ts);
	for(int ca=1; ca<=ts; ca++)
	{
		scanf("%d",&n);
		top=0;
		for(int i=0; i<n; i++)
			list[i]=-1;
		for(int i=0; i<n-1; i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			x--,y--;
			insert(x,y);
			insert(y,x);
		}
		dfs(0,-1,n);
		int ret=N,id;
		for(int i=0; i<n; i++)
			if(ret>no[i].mx)
				ret=no[i].mx,id=i+1;
		printf("%d %d\n",id,ret);
	}
	return 0;
}
