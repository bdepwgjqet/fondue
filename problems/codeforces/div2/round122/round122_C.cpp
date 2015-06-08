/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  06/04/2012 12:01:05 AM
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
#define N 110
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

char s[N][N];
int n,m,v[N][N],dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

int inboard(int x,int y)
{
	return 0<=x&&x<m&&0<=y&&y<n;
}

void dfs(int i,int j)
{
	v[i][j]=1;
	for(int u=0; u<4; u++)
	{
		int x=i+dir[u][0],y=j+dir[u][1];
		if(inboard(x,y)&&!v[x][y]&&s[x][y]=='#')
			dfs(x,y);
	}
}

int to_del(int i,int j)
{
	int ret=0;
	for(int u=0; u<4; u++)
	{
		int x=i+dir[u][0],y=j+dir[u][1];
		if(inboard(x,y)&&s[x][y]=='#')
			ret++;
	}
	return ret>1;
}

int ok()
{
	int ret=0;
	memset(v,0,sizeof(v));
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
			if(!v[i][j]&&s[i][j]=='#')
			{
				dfs(i,j);
				ret++;
			}
	return ret>1;
}

int solve()
{
	int cnt=0;
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
			if(s[i][j]=='#')
				cnt++;
	if(cnt<=2)	return -1;
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
		{
			if(s[i][j]=='#')
			{
				s[i][j]='.';
				if(ok())
					return 1;
				s[i][j]='#';
			}
		}
	return 2;
}

int main()
{
	scanf("%d%d",&m,&n);
	for(int i=0; i<m; i++)
		scanf("%s",s[i]);
	printf("%d\n",solve());
	return 0;
}
