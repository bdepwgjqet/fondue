/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  09/28/2012 12:31:30 AM
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
#define N 111
#define M 1000010
#define S 100010
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

int mat[N][N];
vector<int> vec;
int vis[N],list[N],vv[N];

int dfs(int now,int tag,int n)
{
	if(vis[now])
	{
		if(vv[now]!=tag)
			return 0;
		return 1;
	}
	vis[now]=1;
	vv[now]=tag;
	if(tag)
		vec.push_back(now);
	for(int i=1; i<=n; i++)
		if(mat[now][i]!=-1)
		{
			int nt=dfs(i,tag^(1-mat[now][i]),n);
			if(nt==0)
				return 0;
		}
	return 1;
}

int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		vec.clear();
		memset(mat,-1,sizeof(mat));
		memset(vis,0,sizeof(vis));
		memset(vv,0,sizeof(vv));
		for(int i=0; i<m; i++)
		{
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			mat[x][y]=mat[y][x]=z;
		}
		int tag=1;
		for(int i=1; i<=n; i++)
		{
			int ok;
			if(!vis[i])
			{
				ok=dfs(i,0,n);
				if(ok==0)
				{
					tag=0;
					break;
				}
			}
		}
		if(tag==0)
			puts("Impossible");
		else
		{
			printf("%d\n",vec.size());
			for(int i=0; i<vec.size(); i++)
				printf("%d ",vec[i]);
			puts("");
		}
	}
	return 0;
}
