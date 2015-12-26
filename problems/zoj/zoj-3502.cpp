#include <cstdio>
#include <algorithm>
#define N 2000

using namespace std;

int dp[N];
int mat[12][12];
int ord[N];

inline int B(int i){ return 1<<i; }

int dfs(int st,int n,int l)
{
	if(dp[st]>=0)
		return dp[st];
	if(st==B(n)-1)
		return dp[st]=0;
	int ret=-1;
	int p=0;
	for(int i=0; i<n; i++)
	{
		if(st&B(i))
			continue;
		int p=mat[i][i];
		for(int j=0; j<n; j++)
			if(st&B(j))
				p=max(p,mat[j][i]);
		int x=dfs(st+B(i),n,l+1)+p;
		if(ret<x)
		{
//		printf("%d %d %d %d=>\n",st,ret,x,i);
			ret=x,ord[st]=i;
		}
	}
	return dp[st]=ret;
}

void show(int st,int n)
{
	if(st==B(n)-1)
		return;
	int nx=ord[st];
	printf("%c",'A'+nx);
	show(st+B(nx),n);
}

int main()
{
	int ts,n;
	scanf("%d",&ts);
	while(ts--)
	{
		scanf("%d",&n);
		for(int i=0; i<B(n)+1; i++)
			dp[i]=-1;
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
			{
				scanf("%d",&mat[i][j]);
			}
		printf("%.2lf\n",0.01*dfs(0,n,0));
		show(0,n);
		puts("");
	}
	return 0;
}
