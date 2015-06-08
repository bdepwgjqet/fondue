/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  08/14/2012 11:25:31 PM
 ***/

#include <cstring>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <sstream>
#include <cmath>
#include <functional>
#include <iostream>
#include <algorithm>
#define N 1010
#define M 1000010
#define S 1000100
#define eps 1e-8
#define inf 0x3fffffff
#define MOD 1000000007
#define PB push_back
#define MP make_pair
#define SZ(a) ((int)((a).size()))
#define ALL(a) (a).begin(),(a).end()
#define CLR(a,x) memset(a,x,sizeof(a))

typedef long long LL;
using namespace std;

int mat[N][N],vis[N],n;
struct edge{ int f,t,n; }e[S];
int top,list[N],cnt,ret,rt,odd,in[N];

void insert(int f,int t)
{
	e[top].f=f,e[top].t=t;
	e[top].n=list[f],list[f]=top++;
}

void dfs(int now)
{
	int leaf=1;
	vis[now]=1;
	cnt++;
	for(int i=list[now]; i!=-1; i=e[i].n)
	{
		int to=e[i].t;
		if(!vis[to])
		{
			leaf=0;
			dfs(to);
		}
	}
	if(leaf)
	{
		if(cnt&1)
			odd++;
		if(mat[rt][now])
		{
			if(cnt&1)
			{
				if(cnt>1)
					ret++,odd--;
			}
		}
	}
}

int main()
{
	int m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		memset(vis,0,sizeof(vis));
		memset(in,0,sizeof(in));
		memset(mat,0,sizeof(mat));
		top=0;
		for(int i=0; i<n; i++)
			list[i]=-1;
		for(int i=0; i<m; i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			x--,y--;
			insert(x,y);
			insert(y,x);
			mat[x][y]=mat[y][x]=1;
			in[x]++,in[y]++;
		}
		ret=0,odd=0;
		for(int i=0; i<n; i++)
			if(!vis[i]&&in[i]<=1)
			{
				cnt=0;
				rt=i;
				dfs(i);
			}
		for(int i=0; i<n; i++)
			if(!vis[i])
			{
				cnt=0;
				rt=i;
				dfs(i);
			}
		if(odd&1)
			ret++;
		printf("%d\n",ret);
	}
	return 0;
}
