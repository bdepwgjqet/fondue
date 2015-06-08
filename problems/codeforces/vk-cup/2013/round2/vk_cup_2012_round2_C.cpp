/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  03/25/2012 10:42:53 PM
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
#define N 101000
#define M 1000010
#define S 1000100
#define MOD 1000000007

typedef long long LL;
using namespace std;

inline int L(int i){ return i<<1; }
inline int R(int i){ return (i<<1)|1; }
inline int B(int i){ return 1<<i; }
inline int low_bit(int x){ return x&(-x); }

int n,top,xtop,tag[N];
double l,v1,v2,xx[N<<2],ret[N];

struct cho{ int i; double p; }c[N];
struct seg{ double x; int i,t; }ln[N<<2];

void add(double x,int i,int t)
{
	ln[top].i=i;
	ln[top].t=t;
	ln[top++].x=x;
}

int cmp(seg a,seg b){ return a.x<b.x; }

int main()
{
	double d,x;
	while(scanf("%d%lf%lf%lf",&n,&l,&v1,&v2)!=EOF)
	{
		top=0;
		d=l*v2/(v1+v2);
		//printf("%lf=>\n",d);
		for(int i=0; i<n; i++)
		{
			scanf("%lf",&x);
			if(d>x)
			{
				add(0,i,0);
				add((d-x),i,1);
				add((2*l-x),i,0);
				add(2*l,i,1);
			}
			else
			{
				add((2*l-x),i,0);
				add((2*l-x+d),i,1);
			}
		}
		ln[top].t=-1;
		ln[top++].x=2*l;
		sort(ln,ln+top,cmp);
		/*
		for(int i=0; i<top; i++)
			printf("%lf ",ln[i].x);
		puts("");
		*/
		xtop=0;
		xx[0]=ln[0].x;
		for(int i=1; i<top; i++)
		{
			if(ln[i].x==xx[xtop])
				continue;
			else
				xx[++xtop]=ln[i].x;
		}
		/*
		for(int i=0; i<=xtop; i++)
			printf("%lf ",xx[i]);
		puts("");
		*/
		memset(tag,0,sizeof(tag));
		memset(ret,0,sizeof(ret));
		int j=0,cnt=0;
		double pre=0;
		for(int i=0; i<=xtop; i++)
		{
	//		printf("%d %lf %lf=>\n",cnt,xx[i],pre);
			ret[cnt]+=xx[i]-pre;
			pre=xx[i];
			for(; ln[j].x==xx[i]&&j<top; j++)
			{
				if(ln[j].t==1)
					cnt--;
				else if(ln[j].t==0)
					cnt++;
			}
			
		}
		for(int i=0; i<=n; i++)
			printf("%.20lf\n",ret[i]/2/l);
	}
	return 0;
}
