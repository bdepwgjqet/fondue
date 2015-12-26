/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  03/09/2012 10:23:01 PM
 ***/

#include <cstring>
#include <cstdio>
#include <vector>
#include <cstdlib>
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

struct data{ int i,x; }dat[200],A[100],B[100],tmp;

int cmp(data a,data b){ return a.x>b.x; }

int main()
{
	int k,n,suma,sumb,now,sum,x,y,i;
	while(scanf("%d",&k)!=EOF)
	{
		n=k*3;
		sum=500*k;
		for(i=0; i<n; i++)
		{
			scanf("%d",&dat[i].x);
			dat[i].i=i+1;
		}
		sort(dat,dat+n,cmp);
		for(i=2*k; i<n; i++)
			printf("%d\n",dat[i].i);
		suma=sumb=0;
		for(now=i=0; i<2*k; i++)
		{
			if(now==0)
			{
				A[i>>1]=dat[i];
				suma+=dat[i].x;
			}
			else
			{
				B[i>>1]=dat[i];
				sumb+=dat[i].x;
			}
			now^=1;
		}
//		printf("%d %d %d\n",sum,suma,sumb);
		for(; (suma<=sum||sumb<=sum);)
		{
			x=rand()%k;
			y=rand()%k;
			suma=suma-A[x].x+B[y].x;
			sumb=sumb-B[y].x+A[x].x;
			tmp=A[x],A[x]=B[y],B[y]=tmp;
		}
		for(i=0; i<k; i++)
			printf("%d\n",A[i].i);
		for(i=0; i<k; i++)
			printf("%d\n",B[i].i);
	}
	return 0;
}
