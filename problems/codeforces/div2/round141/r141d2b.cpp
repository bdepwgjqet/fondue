/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  09/27/2012 11:52:58 PM
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
#define N 101
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

char mta[N][N],mtb[N][N];

int main()
{
	int na,ma,nb,mb,x,y,ret;
	while(scanf("%d%d",&na,&ma)+1)
	{
		ret=-1;
		for(int i=1; i<=na; i++)
			scanf("%s",mta[i]+1);
		scanf("%d%d",&nb,&mb);
		for(int i=1; i<=nb; i++)
			scanf("%s",mtb[i]+1);
		x=y=inf;
		for(int i=-na+1; i<=nb; i++)
			for(int j=-ma+1; j<=mb; j++)
			{
				int tmp=0;
				for(int u=1; u<=na; u++)
					for(int v=1; v<=ma; v++)
						if(i+u>=1&&i+u<=nb)
							if(v+j>=1&&v+j<=mb)
							{
								tmp+=((mta[u][v]-'0')*(mtb[i+u][j+v]-'0'));
							}
				if(tmp>ret)
					ret=tmp,x=i,y=j;
			}
		printf("%d %d\n",x,y);
	}
	return 0;
}
