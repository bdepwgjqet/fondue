#include <cstdio>
#include <algorithm>
#include <cstring>
#define inf 0x3fffffff
#define N 11
using namespace std;

struct edge{ int f,t,n,l; }e[1001];
int dp[N][1<<N],top,list[N],len[N],n;
char s[N][44];

inline int B(int i){ return 1<<i; }

void insert(int f,int t,int l)
{
	e[top].f=f,e[top].t=t,e[top].l=l;
	e[top].n=list[f],list[f]=top++;
}

int ok(int i,int x,int y)
{
	for(int j=i; j<len[x]&&j-i<len[y]; j++)
		if(s[x][j]!=s[y][j-i])
				return 0;
	return 1;
}

int cal(int x,int y)
{
	for(int i=max(len[x]-len[y],0); i<len[x]; i++) 
		if(ok(i,x,y))
			return max(len[y]-(len[x]-i),0);
	return len[y];
}

int dfs(int now,int st)
{
	int ret=inf;
	if(dp[now][st]>=0)
		return dp[now][st];
	if(st==B(n+1)-1)
		return dp[now][st]=0;
	for(int i=list[now]; i!=-1; i=e[i].n)
	{
		int to=e[i].t;
		if(st&B(to))
			continue;
		ret=min(ret,dfs(to,st+B(to))+e[i].l);
	}
	return dp[now][st]=ret;
}

int main()
{
	int t;
	scanf("%d",&t);
	for(; t--;)
	{
		scanf("%d",&n);
		top=0;
		for(int i=0; i<=n; i++)
			list[i]=-1;
		for(int i=1; i<=n; i++)
		{
			scanf("%s",s[i]);
			len[i]=strlen(s[i]);
		}
		for(int i=1; i<=n; i++)
		{
			insert(0,i,len[i]);
			insert(i,0,len[i]);
		}
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=n; j++)
			{
				if(i==j)
					continue;
				insert(i,j,cal(i,j));
			}
		}
		memset(dp,-1,sizeof(dp));
		printf("%d\n",dfs(0,1));
	}
	return 0;
}
