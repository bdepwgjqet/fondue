/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  07/13/2012 09:50:06 AM
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
#define N 25
#define M 1000010
#define S 1000100
#define eps 1e-8
#define inf 0x3fffffff
#define MOD 1000000007
#define PB push_back
#define MP make_pair
#define SZ(a) ((int)((a).size()))
#define ALL(a) (a).begin(),(a).end()
#define CLR(a,x) memset(a,x,sizeof(a))

typedef long long LL;
using namespace std;
int ret,n,m,ss[N],vv[N];

void dfs(int lay,int preh,int prer,int nowsum,int w)
{
	int x,nr,nh,add;
	if(nowsum+2*w/prer>=ret||nowsum+ss[m-lay]>=ret)
		return;
	if(w<vv[m-lay])
		return;
	if(lay==m)
	{
		if(w==0&&ret>nowsum)
			ret=nowsum;
		return;
	}
	if(lay>m)
		return;
	if(w<=0)
		return;
	if(lay==m-1)
	{
		if((prer-1)*(prer-1)*(preh-1)<w)
			return;
		for(nr=prer-1; nr>0; nr--)
		{
			x=nr*nr;
			if(w%x)
				continue;
			nh=w/x;
			if(nh>=preh)
				continue;
			if(nowsum+2*nr*nh<ret)
			{
				ret=nowsum+2*nr*nh;
				return;
			}
		}
		return;
	}
	for(nr=prer-1; nr>=m-lay; nr--)
		for(nh=preh-1; nh>=m-lay; nh--)
			dfs(lay+1,nh,nr,nowsum+2*nr*nh,w-nr*nr*nh);
}

void init()
{
	ss[1]=2;
	vv[1]=1;
	for(int i=2; i<=25; i++)
	{
		ss[i]=ss[i-1]+2*i*i;
		vv[i]=vv[i-1]+i*i*i;
	}
}

int main()
{
	init();
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		ret=inf;
		for(int i=1; i<26; i++)
			for(int j=1; j<26; j++)
				dfs(1,j,i,i*i+2*i*j,n-i*i*j);
		if(ret>=inf)
			puts("0");
		else
			printf("%d\n",ret);
	}
	return 0;
}
