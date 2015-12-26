/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  03/20/2012 03:31:32 PM
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

int cnt[N];

struct point{ double x1,y1,x2,y2; }p[N];

int get_id(int x,int y)
{
	if(y==0)	return x;
	if(y==100)	return 300-x;
	if(x==100)	return 100+y;
	return 400-y;
}

double xmult(double ax,double ay,double bx,double by,double cx,double cy)
{
	return (ax-cx)*(by-cy)-(ay-cy)*(bx-cx);
}

int main()
{
	int n,ret,i,a,b,t,j,k;
	double x,y,xmul;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0; i<400; i++)	cnt[i]=1;
		cnt[0]=cnt[100]=cnt[200]=cnt[300]=cnt[400]=N;
		ret=N;
		for(i=0; i<n; i++)
			scanf("%lf%lf%lf%lf",&p[i].x1,&p[i].y1,&p[i].x2,&p[i].y2);
		scanf("%lf%lf",&x,&y);
		for(i=0; i<n; i++)
		{
			a=get_id(int(p[i].x1),int(p[i].y1));
			b=get_id(int(p[i].x2),int(p[i].y2));
			xmul=xmult(p[i].x1,p[i].y1,p[i].x2,p[i].y2,x,y);
			if(xmul<0)
				t=a,a=b,b=t;
			if(a>b)
				k=b+400-a-1;
			else
				k=b-a-1;
			for(j=(a+1)%400; k>0; k--,j=(j+1)%400)
				cnt[j]++;
		}
		for(i=0; i<400; i++)
			ret=min(ret,cnt[i]);
		printf("Number of doors = %d\n",ret);
	}
	return 0;
}
