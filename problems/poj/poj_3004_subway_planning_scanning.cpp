/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  03/18/2012 09:12:39 PM
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
#define N 1001
#define eps 1e-8
#define inf 100000000

typedef long long LL;
using namespace std;

inline int L(int i){ return i<<1; }
inline int R(int i){ return (i<<1)|1; }
inline int max(int a,int b){ return a<b?b:a; }
inline int min(int a,int b){ return a<b?a:b; }
inline int abs(int x){ return x<0?-x:x; }
inline int lower_bound(int x){ return x&(-x); }

struct point{ double l,r; }p[N],pp[N];

inline double len(double x,double y){ return sqrt(x*x+y*y); }

int cmp(point a,point b){ return a.r<b.r; }
double pi;

int main()
{
	int n,t,ret,i,tmp,j,k,pre,top; double d,sita,x,y;
	pi=acos(-1);
	scanf("%d",&t);
	for(; t--; )
	{
		scanf("%d%lf",&n,&d);
		top=0;
		for(i=0; i<n; i++)
		{
			scanf("%lf%lf",&x,&y);
			if(d>=len(x,y))
				continue;
			sita=asin(d/len(x,y));
			p[top].l=atan2(y,x)-sita;
			p[top++].r=atan2(y,x)+sita;
		}
		if(top==0)
		{
			puts("0");
			continue;
		}
		sort(p,p+top,cmp);
		for(ret=inf,k=0; k<top; k++)
		{
			for(i=k,j=0; j<top; j++,i++)
			{
				pp[j]=p[i%top];
				if(i>=top)
					pp[j].l+=2*pi,pp[j].r+=2*pi;
			}
			/*
			for(i=0; i<n; i++)
				printf("%lf %lf\n",pp[i].l,pp[i].r);
			puts("");
			*/
			for(tmp=0,i=0; i<top; )
			{
				pre=i;
				sita=pp[i].r;
				tmp++;
				for(; pp[i].l<sita+eps&&i<top; i++);
				if(pre==i)	i++;	//impossible
			}
			ret=min(ret,tmp);
		}
		printf("%d\n",ret);
	}
	return 0;
}
