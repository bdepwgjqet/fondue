/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  08/18/2012 02:37:52 PM
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

struct node{ int x,y; }no[N];
int mat[N][N];

struct ufind
{
	int p[N];
	void init(){ for(int i=0; i<N; i++) p[i]=i; }
	void run(int &x)
	{
		int y=x,t;
		for(; p[x]!=x; x=p[x]);
		for(; p[t=y]!=x; y=p[y],p[t]=x);
	}
	void setfriend(int i,int j)
	{
		run(i);
		run(j);
		p[i]=j;
	}
	int isfriend(int i,int j)
	{
		run(i);
		run(j);
		return i==j;
	}
}uf;

int vis[N];

int main()
{
	int n,ret;
	while(scanf("%d",&n)!=EOF)
	{
		int x,y,u,v;
		uf.init();
		memset(mat,0,sizeof(mat));
		for(int i=0; i<n; i++)
		{
			scanf("%d%d",&x,&y);
			no[i].x=x,no[i].y=y;
			mat[x][y]=i;
			for(int j=0; j<i; j++)
			{
				if(no[j].x==x||no[j].y==y)
					uf.setfriend(i,j);
			}
		}
		ret=0;
		memset(vis,0,sizeof(vis));
		int p;
		for(int i=0; i<n; i++)
		{
			p=i;
			uf.run(p);
			vis[p]=1;
		}
		for(int i=0; i<n; i++)
			if(vis[i])
				ret++;
		printf("%d\n",ret-1);
	}
	return 0;
}
