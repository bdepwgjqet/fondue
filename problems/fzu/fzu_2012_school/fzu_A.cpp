/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  04/28/2012 02:01:06 PM
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

inline int L(int i){ return i<<1; }
inline int R(int i){ return (i<<1)|1; }
inline int B(int i){ return 1<<i; }
inline int low_bit(int x){ return x&(-x); }

int cnt[5];
LL pri[5][20];

int main()
{
	int t,ca;
	LL ret,ttl,x,y;
	LL aa,bb,cc,dd,ee;
	scanf("%d",&t);
	for(ca=1; ca<=t; ca++)
	{
		ret=0;
		memset(pri,0,sizeof(pri));
		for(int i=0; i<5; i++)
			scanf("%d",&cnt[i]);
		for(int i=0; i<5; i++)
		{
			for(int j=1; j<=cnt[i]; j++)
				cin>>pri[i][j];
		}
		cin>>x>>y;
		for(int xx=0; xx<=cnt[3]; xx++)
		for(int yy=xx; yy<=cnt[3]; yy++)
		{
			if(xx==0||yy==0)
				continue;
			if(xx==yy)
				aa=pri[3][xx];
			else
				aa=pri[3][xx]+pri[3][yy];
			for(int uu=0; uu<=cnt[4]; uu++)
			for(int vv=uu; vv<=cnt[4]; vv++)
			{
				if(uu==0)	continue;
				if(uu==vv)
					bb=pri[4][uu];
				else
					bb=pri[4][uu]+pri[4][vv];
				for(int k=0; k<=cnt[2]; k++)
				{
					cc=pri[2][k];
					if(k!=0)
					{
						if(aa+bb+cc>=x&&aa+bb+cc<=y)
							ret++;
					}
					else
					{
						for(int u=1; u<=cnt[0]; u++)
						{
							for(int v=1; v<=cnt[1]; v++)
							{
								ttl=aa+bb+cc+pri[0][u]+pri[1][v];
								if(ttl>=x&&ttl<=y)
									ret++;
							}
						}
					}
				}
			}
		}
		cout<<ret<<endl;
	}
	return 0;
}
