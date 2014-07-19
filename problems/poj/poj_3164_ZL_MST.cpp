/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  07/14/2012 12:35:07 PM
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
#define S 20100
#define eps 1e-8
#define inf 1e9
#define MOD 1000000007
#define PB push_back
#define MP make_pair
#define SZ(a) ((int)((a).size()))
#define ALL(a) (a).begin(),(a).end()
#define CLR(a,x) memset(a,x,sizeof(a))

typedef long long LL;
using namespace std;

struct node{ double x,y; }no[N];
struct edge{ int f,t,n; double l; }e[S];
double mat[N][N],len[N];
int top,list[N],id[N],v[N],pre[N];

void insert(int f,int t,double l)
{
	e[top].f=f,e[top].t=t,e[top].l=l;
	e[top].n=list[f],list[f]=top++;
}

double get_len(int i,int j)
{
	return sqrt((no[i].x-no[j].x)*(no[i].x-no[j].x)+(no[i].y-no[j].y)*(no[i].y-no[j].y));
}

double ZL_MST(int r,int n)
{
	int nextn,f,t;
	double ret=0;
	while(1)
	{
		memset(pre,-1,sizeof(pre));
		memset(v,-1,sizeof(v));
		memset(id,-1,sizeof(id));
		for(int i=0; i<n; i++)
			len[i]=inf;
		for(int i=0; i<top; i++)
		{
			f=e[i].f,t=e[i].t;
			if(f==t) continue;
			if(len[t]>e[i].l)
				len[t]=e[i].l,pre[t]=f;
		}
		for(int i=0; i<n; i++)
			if(pre[i]==-1&&i!=r)
				return -1;	//impossible to spanning a tree
		nextn=0;
		len[r]=0;
		for(int i=0; i<n; i++)
		{
			ret+=len[i];
			int now=i;
			for(; v[now]!=i&&id[now]==-1&&now!=r; )
			{
				v[now]=i;
				now=pre[now];
			}
			if(now!=r&&id[now]==-1)
			{
				for(int f=pre[now]; f!=now; f=pre[f])
					id[f]=nextn;
				id[now]=nextn++;
			}
		}
		if(nextn==0) break;	//no rings
		for(int i=0; i<n; i++)
			if(id[i]<0)
				id[i]=nextn++;
		for(int i=0; i<top; i++)
		{
			f=e[i].f,t=e[i].t;
			e[i].f=id[f];
			e[i].t=id[t];
			if(f==t) continue;
			e[i].l-=len[t];
		}
		n=nextn;
		r=id[r];
	}
	return ret;
}

int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		top=0;
		for(int i=0; i<n; i++)
			list[i]=-1;
		for(int i=0; i<n; i++)
			scanf("%lf%lf",&no[i].x,&no[i].y);
		for(int i=0; i<n; i++)
			for(int j=i; j<n; j++)
				mat[j][i]=mat[i][j]=get_len(i,j);
		for(int i=0; i<m; i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			x--,y--;
			insert(x,y,mat[x][y]);
		}
		double ret=ZL_MST(0,n);
		if(ret<0)
			puts("poor snoopy");
		else
			printf("%.2f\n",ret);
	}
	return 0;
}
