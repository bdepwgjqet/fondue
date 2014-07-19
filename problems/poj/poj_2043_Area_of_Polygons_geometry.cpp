/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  03/21/2012 11:07:24 AM
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
#define N 1010
#define M 1000010
#define inf 0x7fffffff
#define S 1000100
#define MOD 1000000007

typedef long long LL;
using namespace std;

inline int L(int i){ return i<<1; }
inline int R(int i){ return (i<<1)|1; }
inline int B(int i){ return 1<<i; }
inline int low_bit(int x){ return x&(-x); }

struct point{ int x,y; }p[N];
struct line{ point a,b; }ln[N];
struct segment{ double y1,y2; }ep[N<<1];

inline double cal(point a,point b,double x)
{
	double delta=(x-a.x)*(b.y-a.y)/(b.x-a.x);
	return a.y+delta;
}

int cmp(segment a,segment b)
{
	return a.y1==b.y1?a.y2<b.y2:a.y1<b.y1; 
}

int main()
{
	int n,ret,top,pre,Rst,Lst;
	while(scanf("%d",&n)&&n)
	{
		Lst=inf,Rst=-inf;
		for(int i=0; i<n; i++)
		{
			scanf("%d%d",&p[i].x,&p[i].y);
			Lst=min(Lst,p[i].x);
			Rst=max(Rst,p[i].x);
		}
		for(int i=0; i<n; i++)
		{
			int s=i,t=(i+1)%n;
			if(p[s].x<p[t].x)
				ln[i].a=p[s],ln[i].b=p[t];
			else
				ln[i].a=p[t],ln[i].b=p[s];
		}
		ret=0;
		for(int u=Lst; u<Rst; u++)
		{
			top=0;
			double xl=u,xr=u+1;
			for(int j=0; j<n; j++)
				if(ln[j].a.x<=xl&&ln[j].b.x>=xr)
				{
					ep[top].y1=cal(ln[j].a,ln[j].b,xl);
					ep[top++].y2=cal(ln[j].a,ln[j].b,xr);
				}
			sort(ep,ep+top,cmp);
			for(int j=0; j+1<top; j+=2)
			{
				int d=floor(min(ep[j].y1,ep[j].y2)),u=ceil(max(ep[j+1].y1,ep[j+1].y2));
				ret+=u-d;
				if(j>0&&d<pre)
					ret-=pre-d;
				pre=u;
			}
		}
		printf("%d\n",ret);
	}
	return 0;
}
