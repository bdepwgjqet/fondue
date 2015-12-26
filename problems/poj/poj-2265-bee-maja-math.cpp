/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  03/15/2012 08:37:04 PM
 ***/

#include <cstring>
#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>
#define MAXN 1010
#define MAXM 1000010
#define MOD 1000000007

typedef long long LL;
using namespace std;

inline int L(int i){ return i<<1; }
inline int R(int i){ return (i<<1)|1; }
inline int max(int a,int b){ return a<b?b:a; }
inline int min(int a,int b){ return a<b?a:b; }
inline int abs(int x){ return x<0?-x:x; }

int ans[10][2]={{-1,1},{-1,0},{0,-1},{1,-1},{1,0},{0,1}};

int lay(int n,int &id)
{
	int ret,y;
	double x;
	x=(-3+sqrt(9+12.0*(n-1)))/6.0;
	ret=int(x);
//	printf("%d %d %d\n",n,ret,id);
	y=3*ret*ret+3*ret+1;
	if(y==n)
	{
		if(ret==0)	id=1;
		else	id=6*ret;
		return ret;
	}
	id=n-y;
	return ret+1;
}

void get(int &x,int &y,int k,int id)
{
	if(id==0)	
		x=k-1,y=1;
	else if(id==1)
		x=-1,y=k;
	else if(id==2)
		x=-k,y=k-1;
	else if(id==3)
		x=1-k,y=-1;
	else if(id==4)
		x=1,y=-k;
	else 
		x=k,y=1-k;
}

int main()
{
	int n,x,y,a,b,retx,rety;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==1)	
		{
			puts("0 0");
			continue;
		}
		x=lay(n,y);
		a=y/x,b=y%x;
		if(b==0)
			a--,b=x;
		//printf("%d %d %d %d=>\n",x,y,a,b);
		get(retx,rety,x,a);
		printf("%d %d\n",retx+ans[a][0]*(b-1),rety+ans[a][1]*(b-1));
	}
	return 0;
}
