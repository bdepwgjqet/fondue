/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  07/17/2012 06:12:51 PM
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
#define N 50010
#define M 1000010
#define S 200010
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
char s[100];
struct edge{ int f,t,l,n; }e[S];
struct node{ int t,r,i;
	node(int a,int b,int c){ t=a,r=b,i=c; }
};
vector<node> q[N];
int v[N],vis[N],len[N],ret[N],list[N],top;

void insert(int f,int t,int l)
{
	e[top].f=f,e[top].t=t,e[top].l=l;
	e[top].n=list[f],list[f]=top++;
}

struct ufind
{
	int p[N],t;
	void init(){ for(int i=0; i<N; p[i]=i++); }
	void run(int &x)
	{ 
		int y=x;
		for(; (t=p[x])!=x; x=p[x],p[t]=p[x]);
		for(; p[t=y]!=x; p[y]=x,y=p[t]);
	}
	int isfriend(int i,int j)
	{
		run(i); run(j);
		return i==j;
	}
	void setfriend(int i,int j)
	{
		run(i); run(j);
		p[i]=j;
	}
}uf;

void tarjan(int now,int l)
{
	len[now]=l;
	v[now]=1;
	for(int i=list[now]; i!=-1; i=e[i].n)
	{
		int to=e[i].t;
		if(v[to])
			continue;
		tarjan(to,l+e[i].l);
		uf.setfriend(to,now);
	}
	vis[now]=1;
	for(int i=0; i<q[now].size(); i++)
	{
		int to=q[now][i].t;
		if(!vis[to])
			continue;
		int p=to,ii=q[now][i].i;
		uf.run(p);
		ret[ii]=l+len[to]-2*len[p];
		q[now][i].r=l+len[to]-2*len[p];
	}
}

int main()
{
	int n,m,k;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		int x,y,l;
		top=0;
		for(int i=0; i<n; i++)
			list[i]=-1,q[i].clear();
		for(int i=0; i<m; i++)
		{
			scanf("%d%d%d%s",&x,&y,&l,s);
			insert(x-1,y-1,l);
			insert(y-1,x-1,l);
		}
		scanf("%d",&k);
		for(int i=0; i<k; i++)
		{
			scanf("%d%d",&x,&y);
			x--,y--;
			q[x].push_back(node(y,0,i));
			q[y].push_back(node(x,0,i));
		}
		uf.init();
		memset(v,0,sizeof(v));
		memset(vis,0,sizeof(vis));
		memset(ret,0,sizeof(ret));
		tarjan(0,0);
		for(int i=0; i<k; i++)
			printf("%d\n",ret[i]);
	}
	return 0;
}
