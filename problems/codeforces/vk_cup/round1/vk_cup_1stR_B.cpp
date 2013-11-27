/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  03/11/2012 10:56:20 PM
 ***/

#include <cstring>
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

struct data{ int v,i,t; }A[MAXN],B[MAXN],tmp;

int cmp(data a,data b){ return a.v>b.v; }
int cnt[MAXN],top,ta,tb;

int main()
{
	int n,k,i,x,y; double ret=0;
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		ret=0;
		ta=tb=0;
		for(i=0; i<n; i++)
		{
			scanf("%d%d",&tmp.v,&tmp.t);
			tmp.i=i+1;
			if(tmp.t==1) A[ta++]=tmp;
			else		 B[tb++]=tmp;
			ret+=tmp.v;
		}
		sort(A,A+ta,cmp);
		sort(B,B+tb,cmp);
		for(i=0; i<ta&&i<k-1; i++)
			ret-=A[i].v/2.0;
		if(i==ta)
		{
			printf("%.1lf\n",ret);
			for(i=0; i<ta; i++)
				printf("1 %d\n",A[i].i);
			for(i=0; i<k-ta-1; i++)
				printf("1 %d\n",B[i].i);
			printf("%d",tb+ta-k+1);
			for(; i<tb; i++)
				printf(" %d",B[i].i);
			puts("");
		}
		else
		{
			x=A[ta-1].v;
			if(tb>0)
				x=min(x,B[tb-1].v);
			ret-=x/2.0;
			printf("%.1lf\n",ret);
			for(i=0; i<k-1; i++)
				printf("1 %d\n",A[i].i);
			printf("%d",ta+tb-k+1);
			for(; i<ta; i++)
				printf(" %d",A[i].i);
			for(i=0; i<tb; i++)
				printf(" %d",B[i].i);
			puts("");
		}
	}
	return 0;
}


