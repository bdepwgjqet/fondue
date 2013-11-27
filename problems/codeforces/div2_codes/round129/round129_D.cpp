/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  07/12/2012 12:28:31 AM
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
#define N 201000
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

inline int L(int i){ return i<<1; }
inline int R(int i){ return (i<<1)|1; }
inline int B(int i){ return 1<<i; }
inline int low_bit(int x){ return x&(-x); }

struct node{ int x,y; }no[N];
struct CNT{ int a,b,c; }shu[N];
int num[N+N],top,tp;

int cmp(int a,int b){ return a<b; }

int find(int x)
{
	int l=0,r=tp-1,m;
	for(; l<=r;)
	{
		m=(l+r)>>1;
		if(num[m]>x)
			r=m-1;
		else if(num[m]<x)
			l=m+1;
		else
			return m;
	}
	return -1;//impossible
}

int main()
{
	int n,m;
	while(scanf("%d",&n)!=EOF)
	{
		m=(n+1)/2;
		top=0;
		for(int i=0; i<n; i++)
		{
			scanf("%d%d",&no[i].x,&no[i].y);
			num[top++]=no[i].x,num[top++]=no[i].y;
		}
		sort(num,num+top,cmp);
		tp=0;
		for(int i=1; i<top; i++)
		{
			if(num[i]==num[tp])
				continue;
			num[++tp]=num[i];
		}
		tp++;
		for(int i=0; i<tp; i++)
			shu[i].a=shu[i].b=shu[i].c=0;
		for(int i=0; i<n; i++)
		{
			int x=find(no[i].x),y=find(no[i].y);
			if(x==y)
				shu[x].c++;
			else
				shu[x].a++,shu[y].b++;
		}
	//	printf("%d\n",tp);
		int ret=inf;
		for(int i=0; i<tp; i++)
		{
			if(shu[i].a+shu[i].c+shu[i].b>=m)
			{
				if(shu[i].a+shu[i].c>=m)
				{
					ret=0;
					break;
				}
				ret=min(ret,m-shu[i].a-shu[i].c);
			}
		}
		if(ret>=inf)
			puts("-1");
		else
			printf("%d\n",ret);
	}
	return 0;
}
