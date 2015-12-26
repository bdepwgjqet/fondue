/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  03/23/2012 10:41:19 PM
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
#define S 1000100
#define MOD 1000000007

typedef long long LL;
using namespace std;

inline int L(int i){ return i<<1; }
inline int R(int i){ return (i<<1)|1; }
inline int B(int i){ return 1<<i; }
inline int low_bit(int x){ return x&(-x); }

struct fraction{ LL a,b; };
struct point{ fraction x,y; }p[N];

LL gcd(LL a,LL b){ return b?gcd(b,a%b):a; }
LL lcm(LL a,LL b){ return a*b/gcd(a,b); }

void show(point x)
{
	printf("%lld/%lld %lld/%lld\n",x.x.a,x.x.b,x.y.a,x.y.b);

}
void show(fraction x)
{
	printf("%lld/%lld\n",x.a,x.b);

}

fraction operator+(fraction a,fraction b)
{
	fraction ret;
	LL x=lcm(a.b,b.b);
	ret.a=a.a*x/a.b+b.a*x/b.b;
	ret.b=x;
	return ret;
}

fraction operator-(fraction a,fraction b)
{
	fraction ret;
	LL x=lcm(a.b,b.b);
	ret.a=a.a*x/a.b-b.a*x/b.b;
	ret.b=x;
	return ret;
}

fraction operator*(fraction a,fraction b)
{
	fraction ret;
	LL x=gcd(a.a,b.b),y=gcd(a.b,b.a);
	ret.a=a.a/x*b.a/y;
	ret.b=a.b/y*b.b/x;
	return ret;
}

fraction operator/(fraction a,fraction b)
{
	LL t=b.b;
	b.b=b.a,b.a=t;
	return a*b;
}

fraction xmult(point a,point b,point c,point d)
{

	return (a.x-b.x)*(c.y-d.y)-(a.y-b.y)*(c.x-d.x);
}


point intersection(point a,point b,point c,point d)
{
	point ret=a;
	fraction up,dw,t;
	up=xmult(c,d,c,a);
	dw=xmult(a,b,c,d);
	t=up/dw;
	ret.x=ret.x+(b.x-a.x)*t;
	ret.y=ret.y+(b.y-a.y)*t;
	return ret;
}

int main()
{
	int n,m,top,tag=0,u,v,r,s;
	LL x,y;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=1; i<=n; i++)
		{
			scanf("%lld%lld",&x,&y);
			p[i].x.a=x,p[i].x.b=1;
			p[i].y.a=y,p[i].y.b=1;
		}
		top=n+1;
		tag=0;
		scanf("%d",&m);
		for(int i=0; i<m; i++)
		{
			scanf("%d%d%d%d",&r,&s,&u,&v);
			if(tag==1)	continue;
			point tmp=intersection(p[r],p[s],p[u],p[v]);
			if(tmp.x.a==tmp.y.a&&tmp.x.a==0)
			{
				printf("%d\n",i+1);
				tag=1;
			}
			else
				p[top++]=tmp;
		}
		if(tag==0)
			puts("0");
	}
	return 0;
}
