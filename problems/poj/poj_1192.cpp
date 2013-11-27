#include <cstdio>
#include <algorithm>
#define N 1001
using namespace std;

struct edge{ int f,t,n; }e[N<<1];
struct node{ int x,y,c; }no[N];

int top,list[N],dp[N][2];

void insert(int f,int t)
{
	e[top].f=f,e[top].t=t;
	e[top].n=list[f],list[f]=top++;
}

int len(int i,int j)
{
	return abs(no[i].x-no[j].x)+abs(no[i].y-no[j].y);
}

void dfs(int now,int p)
{
	dp[now][1]=no[now].c;
	dp[now][0]=0;
	for(int i=list[now]; i!=-1; i=e[i].n)
	{
		int to=e[i].t;
		if(to==p)
			continue;
		dfs(to,now);
		if(dp[to][1]>0)
			dp[now][1]+=dp[to][1];
		dp[now][0]=max(dp[now][0],max(dp[to][0],dp[to][1]));
	}
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		top=0;
		for(int i=0; i<n; i++)
		{
			scanf("%d%d%d",&no[i].x,&no[i].y,&no[i].c);
			list[i]=-1;
		}
		for(int i=0; i<n; i++)
			for(int j=i+1; j<n; j++)
				if(len(i,j)==1)
				{
					insert(i,j);
					insert(j,i);
				}
		dfs(0,-1);
		printf("%d\n",max(dp[0][1],dp[0][0]));
	}
	return 0;
}
