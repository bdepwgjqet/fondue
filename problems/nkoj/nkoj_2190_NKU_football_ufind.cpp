/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  03/27/2012 10:37:34 AM
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
#define N 301000
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

struct ufind
{
	int p[N],t;
	void init()
	{ 
		for(int i=0; i<=N; i++)
			p[i]=i;
	}
	void run(int &x)
	{
		for(; p[t=x]!=x; x=p[x],p[t]=p[x]);
	}
	int isfriend(int i,int j)
	{
		run(i); run(j);
		return i==j;
	}
	void setfriend(int i,int j)
	{
		run(i); run(j);
		p[i]=p[j];
	}
}uf;

int main()
{
	int x,y,n,m,ret;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		uf.init();
		memset(cnt,0,sizeof(cnt));
		for(int i=0; i<m; i++)
		{
			scanf("%d%d",&x,&y);
			uf.setfriend(x,y);
		}
		for(int i=1; i<=n; i++)
		{
			int tmp=i;
			uf.run(tmp);
			cnt[tmp]++;
		}
		ret=0;
		for(int i=1; i<=n; i++)
			ret+=cnt[i]/8+(cnt[i]%8>=5);
		printf("%d\n",ret);
	}
	return 0;
}
