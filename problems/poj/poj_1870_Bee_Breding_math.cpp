/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  03/15/2012 10:00:49 PM
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

void get_pos(int &retx,int &rety,int n)
{
	int x,y,a,b;
	if(n==1)
		retx=rety=0;
	else
	{
		x=lay(n,y);
		a=y/x,b=y%x;
		if(b==0)
			a--,b=x;
		get(retx,rety,x,a);
		retx=retx+ans[a][0]*(b-1),rety=rety+ans[a][1]*(b-1); }
}

int main()
{
	int n,retx,rety,m,nx,ny,mx,my,ret;
	while(scanf("%d%d",&n,&m)&&(n||m))
	{
		get_pos(nx,ny,n);
		get_pos(mx,my,m);
		retx=nx-mx,rety=ny-my;
		if(retx*rety<0)
			ret=max(abs(retx),abs(rety));
		else
			ret=abs(retx+rety);
		printf("The distance between cells %d and %d is %d.\n",n,m,ret);
	}
	return 0;
}
