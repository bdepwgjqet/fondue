/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  09/26/2012 09:25:15 PM
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
#define N 1010
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

int dat[N][N],sc[N],sr[N],tc[N],tr[N];

int get(int a[],int n)
{
	int x=a[0],ret=0;
	for(int i=1; i<n; i++)
		if(a[i]<x)
			x=a[i],ret=i;
	return ret;
}

int main()
{
	int n,m;
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		memset(sc,0,sizeof(sc));
		memset(sr,0,sizeof(sr));
		memset(tc,0,sizeof(tc));
		memset(tr,0,sizeof(tr));
		for(int i=0; i<m; i++)
			for(int j=0; j<n; j++)
			{
				scanf("%d",&dat[i][j]);
				sc[j]+=dat[i][j];
				sr[i]+=dat[i][j];
			}
		for(;;)
		{
			int ic,ir;
			ic=get(sc,n);
			ir=get(sr,m);
			if(sc[ic]>=0&&sr[ir]>=0)
				break;
			if(sc[ic]>sr[ir])
			{
				tr[ir]^=1;
				for(int i=0; i<n; i++)
				{
					sr[ir]-=dat[ir][i];
					sc[i]-=dat[ir][i];
					dat[ir][i]=-dat[ir][i];
					sr[ir]+=dat[ir][i];
					sc[i]+=dat[ir][i];
				}
			}
			else
			{
				tc[ic]^=1;
				for(int i=0; i<m; i++)
				{
					sc[ic]-=dat[i][ic];
					sr[i]-=dat[i][ic];
					dat[i][ic]=-dat[i][ic];
					sc[ic]+=dat[i][ic];
					sr[i]+=dat[i][ic];
				}
			}
		}
		int ret=0;
		for(int i=0; i<m; i++)
			if(tr[i])
				ret++;
		printf("%d",ret);
		for(int i=0; i<m; i++)
			if(tr[i])
				printf(" %d",i+1);
		puts("");
		ret=0;
		for(int i=0; i<n; i++)
			if(tc[i])
				ret++;
		printf("%d",ret);
		for(int i=0; i<n; i++)
			if(tc[i])
				printf(" %d",i+1);
		puts("");
	}
	return 0;
}
