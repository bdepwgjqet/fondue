/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  07/21/2012 08:14:13 PM
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
char mat[N][N];
int cnt[N][N],n,m;
int dir[8][2]={{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,1},{1,-1},{-1,-1}};

inline int in(int i,int j)
{
	return 0<=i&&i<n&&0<=j&&j<n; 
}

int main()
{
	int t;
	scanf("%d",&t);
	for(; t--; )
	{
		int x,y;
		scanf("%d%d",&n,&m);
		for(int i=0; i<n; i++)
			scanf("%s",mat[i]);
		for(int i=0; i<m; i++)
		{
			memset(cnt,0,sizeof(cnt));
			for(int u=0; u<n; u++)
				for(int v=0; v<n; v++)
					if(mat[u][v]=='b')
					{
						cnt[u][v]++;
						for(int j=0; j<8; j++)
						{
							x=dir[j][0]+u,y=dir[j][1]+v;
							if(in(x,y))
								cnt[x][y]++;
						}
					}
			for(int u=1; u<n-1; u++)
				for(int v=1; v<n-1; v++)
				{
					if(cnt[u][v]>=5)
						mat[u][v]='b';
					else
						mat[u][v]='w';
				}
		}
		int w=0,b=0;
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
			{
				if(mat[i][j]=='b')
					b++;
				else
					w++;
			}
		printf("%d %d\n",b,w);
	}
	return 0;
}
