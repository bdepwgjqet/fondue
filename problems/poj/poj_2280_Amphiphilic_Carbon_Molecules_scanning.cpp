/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  03/18/2012 04:40:39 PM
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
#define MAXN 1010
#define MAXM 1000010
#define MOD 1000000007
#define N 10100
#define M 100000

typedef long long LL;
using namespace std;

struct point{ int x,y,t; double st; }p[N],p0,pp[N];

inline int L(int i){ return i<<1; }
inline int R(int i){ return (i<<1)|1; }
inline int max(int a,int b){ return a<b?b:a; }
inline int min(int a,int b){ return a<b?a:b; }
inline int abs(int x){ return x<0?-x:x; }
inline int lower_bound(int x){ return x&(-x); }

int ret,top;
double pi;

int xmult(point a,point b,point c){ return (a.x-c.x)*(b.y-c.y)-(a.y-c.y)*(b.x-c.x); }
int len(point a,point b){ return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y); }

int cmp(point a,point b)
{
	return a.st<b.st;
}

void solve(int n)
{
	int i,r,o,t;
	sort(pp,pp+n,cmp);
	for(i=0,r=1; i<n; i++)
	{
		o=2;
		if(pp[i].st>0)	break;
		for(; r<n; r++)
		{
			t=xmult(pp[i],pp[r],p0);
			if(t==0)
				o++;
			else if(t<0)
				break;
		}
		ret=max(ret,max(r-i+1,n-r+i+o));
	}
}

int main()
{
	int n,i,j;
	pi=acos(-1);
	while(scanf("%d",&n)&&n)
	{
		if(n==1)	
		{
			puts("1");
			continue;
		}
		for(i=0; i<n; i++)
			scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].t);
		for(ret=i=0; i<n; i++)
		{
			p0=p[i];
			for(top=j=0; j<n; j++)
			{
				if(j==i)	continue;
				if(p[j].t==1)
					pp[top]=p[j];
				else
				{
					pp[top].x=2*p0.x-p[j].x;
					pp[top].y=2*p0.y-p[j].y;
					pp[top].t=p[j].t;
				}
				pp[top].st=atan2(pp[top].y-p[i].y,pp[top].x-p[i].x);
				top++;
			}
			solve(top);
		}
		printf("%d\n",ret);
	}
	return 0;
}
