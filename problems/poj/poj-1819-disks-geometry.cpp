/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  03/20/2012 01:45:06 PM
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
#define eps 1e-8
#define N 1010
#define M 1000010
#define S 1000100
#define MOD 1000000007

typedef long long LL;
using namespace std;

inline int L(int i){ return i<<1; }
inline int R(int i){ return (i<<1)|1; }
inline int max(int a,int b){ return a<b?b:a; }
inline int min(int a,int b){ return a<b?a:b; }
inline double abs(double x){ return x<0?-x:x; }
inline int low_bit(int x){ return x&(-x); }

struct circle{ double x,y; }c[N];
int top,tag[N];

double y0_cut(int i)
{
	return 2*c[i].y;
}

double tagent(int u,int v)
{
	double b=c[u].y+c[v].y,a=fabs(c[u].y-c[v].y);
	return c[u].x+sqrt(b*b-a*a)+c[v].y;
}

int main()
{
	int n,i,id,num,j;
	double maxx,tmpx,retx;
	while(scanf("%d",&n)!=EOF)
	{
		memset(tag,0,sizeof(tag));
		for(i=1; i<=n; i++)
			scanf("%lf",&c[i].y);
		retx=0.0;
		for(top=0,i=1; i<=n; i++)
		{
			maxx=y0_cut(i);
			id=0;
			for(j=1; j<i; j++)
			{
				tmpx=tagent(j,i);
				if(maxx<tmpx)
					maxx=tmpx,id=j;
			}
			c[i].x=maxx-c[i].y;
			for(j=id+1; j<i; j++)
				tag[j]=1;
			double ttt=retx;
			if(maxx>retx)	
				retx=maxx;
		}
		for(i=1; i<=n; i++)
			if(fabs(c[i].x+c[i].y-retx)<eps)
				break;
		for(j=i+1; j<=n; j++)
			tag[j]=1;
		for(num=0,i=1; i<=n; i++)
			if(tag[i])	
				num++;
		printf("%d\n",num);
		for(i=1; i<=n; i++)
			if(tag[i])
				printf("%d\n",i);
	}
	return 0;
}
