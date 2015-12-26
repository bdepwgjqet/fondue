/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  03/25/2012 04:20:29 PM
 ***/

#include <cstring>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cmath>
#include <iostream>
#include <algorithm>
#define inf 0x7fffffff
#define N 1010
#define M 1000010
#define S 1000100
#define MOD 1000000007

typedef long long LL;
using namespace std;

inline int L(int i){ return i<<1; }
inline int R(int i){ return (i<<1)|1; }
inline int B(int i){ return 1<<i; }
inline int low_bit(int x){ return x&(-x); }

int n,m,w,dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}},v[N][N],id[N][N],vis[30],ret;
char s[1001][1001];

struct to_beat{ int g,f,jg,jf,x; }bt[20],me;
struct point{ int x,y; }q[N*N],wh[20],tmp;

vector<int> list[20];
int top;

inline int in_board(int x,int y)
{
	return 0<=x<n&&0<=y<m;
}

void bfs(int now)
{
	list[now].clear();
	int l,r,x,y,i;
	tmp.x=wh[now].x,tmp.y=wh[now].y;
	v[tmp.x][tmp.y]=1;
	memset(v,0,sizeof(v));
	q[l=r=0]=tmp;
	for(; l<=r; )
	{
		x=q[l].x,y=q[l].y,l++;
		for(i=0; i<4; i++)
		{
			int tx=x+dir[i][0],ty=y+dir[i][1];
			if(in_board(tx,ty)&&!v[tx][ty]&&s[tx][ty]!='*')
			{
				if(id[tx][ty]>0)
					list[now].push_back(id[tx][ty]);
				else 
				{
					if(id[tx][ty]==0)
						list[now].push_back(id[tx][ty]);
					tmp.x=tx,tmp.y=ty;
					v[tx][ty]=1;
					q[++r]=tmp;
				}
				v[tx][ty]=1;
			}
		}
	}
}

inline int get(int x)
{
	return x>0?x:0; 
}

void solve(int now,int cnt,int val)
{
	if(cnt==top)
	{
		ret=min(ret,val);
		return ;
	}
	vis[now]=1;
	int t=s[wh[now].x][wh[now].y]-'0';
	if(get(me.g-bt[t].f==0))
	{
		vis[now]=0;
		return ;
	}
	val+=(bt[t].x/(get(me.g-bt[t].f)))*get(bt[t].g-me.f);
	me.f+=bt[t].jf;
	me.g+=bt[t].jg;

	for(int i=0; i<list[now].size(); i++)
	{
		int t=list[now][i];
		if(!vis[t])
			solve(t,cnt+1,val);
	}
	me.f-=bt[t].jf;
	me.g-=bt[t].jg;
	vis[now]=0;
}

int main()
{
	int x,y;
	while(scanf("%d%d%d",&n,&m,&w)!=EOF)
	{
		memset(v,0,sizeof(v));
		memset(id,-1,sizeof(id));
		me.g=me.f=10;
		for(int i=1; i<=w; i++)
			scanf("%d%d%d%d%d",&bt[i].x,&bt[i].g,&bt[i].f,&bt[i].jg,&bt[i].jf);
		for(int i=0; i<n; i++)
			scanf("%s",s[i]);
		top=1;
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
			{
				if(s[i][j]=='#')
				{
					id[i][j]=0;
					wh[0].x=i,wh[0].y=j;
				}
				else if(s[i][j]>='1'&&s[i][j]<='9')
				{
					id[i][j]=top;
					wh[top].x=i,wh[top].y=j;
					top++;
				}
			}
		/*
		for(int i=0; i<n; i++,puts(""))
			for(int j=0; j<m; j++)
				printf("%d ",id[i][j]);
				*/
		for(int i=0; i<top; i++)
		{
			memset(v,0,sizeof(v));
			bfs(i);
		}
		/*
		for(int i=0; i<top; i++,puts(""))
			for(int j=0; j<list[i].size(); j++)
				printf("%d ",list[i][j]);
				*/
		ret=inf;
		solve(0,0,0);
		if(ret>=inf)
			puts("-1");
		else
			printf("%d\n",ret);
	}
	return 0;
}
