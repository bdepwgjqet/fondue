/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  05/26/2012 12:17:12 PM
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
#define N 31
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
inline int low_bit(int x){ return x&(-x); }
int t,n,m,cnt[N];
char p[N][N];
LL ret;
LL c[N][N];
LL b[N];

void init()
{
	c[0][0]=c[1][0]=c[1][1]=1;
	b[0]=1;
	for(int i=2; i<21; i++)
	{
		c[i][0]=c[i][i]=1;
		for(int j=1; j<i; j++)
			c[i][j]=c[i-1][j-1]+c[i-1][j];
	}
	for(int i=1; i<21; i++)
		b[i]=b[i-1]<<1;
	/*
	for(int i=1; i<21; i++)
	{
		for(int j=0; j<=i; j++)
			printf("%d ",c[i][j]);
		puts("");
	}
	*/
}

int main()
{
	init();
	scanf("%d",&t);
	for(int ca=1; ca<=t; ca++)
	{
		scanf("%d%d",&n,&m);
		memset(cnt,0,sizeof(cnt));
		ret=0.0;
		for(int i=0; i<n; i++)
		{
			scanf("%s",&p[i]);
			for(int j=0; j<n; j++)
				if(p[i][j]=='1')
					cnt[i]++;
		}
		for(int i=0; i<n; i++)
		{
			for(int j=m; j<=cnt[i]; j++)
			{
				ret+=c[cnt[i]][j]*b[n-cnt[i]-1];
			}
		}
		printf("%.2lf\n",1.0*ret/b[n]);
//		printf("%lf\n",100.0*ret/b[n]);
		/*
		int r=int(100.0*ret/b[n]+0.5);
		printf("%d",r/100);
		printf(".");
		r=r%100;
		if(r<=9)
		{
			printf("0");
			printf("%d\n",r);
		}
		else
			printf("%d\n",r);
		*/
	}
	return 0;
}
