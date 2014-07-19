/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  04/09/2012 12:42:01 PM
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
#define N 60
#define M 1000010
#define S 1000100
#define eps 1e-8
#define inf 0x3fffffff
#define MOD 1000000007
#define PB push_back
#define SZ(a) ((int)((a).size()))
#define ALL(a) (a).begin(),(a).end()
#define CLR(a,x) memset(a,x,sizeof(a))

typedef long long LL;
using namespace std;

inline int L(int i){ return i<<1; }
inline int R(int i){ return (i<<1)|1; }
inline int B(int i){ return 1<<i; }
inline int low_bit(int x){ return x&(-x); }

int dp[N][N][4][2],dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}},n,m;
char s[N][N];

inline int get_id(int d,int c)
{
	if(c==0)
		return (d+3)%4;
	return (d+1)%4;
}

inline int inboard(int x,int y)
{
	return 1<=x&&x<=n&&1<=y&&y<=m;
}

inline int to_go(int x,int y)
{
	return inboard(x,y)&&s[x][y]>'0';
}

int main()
{
	int k,u,d,c,x,y,tx,ty,dx,dy;
	scanf("%d%d",&n,&k);
	for(int i=1; i<=n; i++)
		scanf("%s",s[i]+1);
	m=strlen(s[1]+1);
	CLR(dp,0);
	x=y=1,d=1,c=0;
	for(u=1; u<=k; u++)
	{
		if(dp[x][y][d][c])
		{
			int t=u-dp[x][y][d][c];
			if(k-u>=t)
				u+=(k-u)/t*t;
		}
		else
			dp[x][y][d][c]=u;
		tx=x,ty=y;
		dx=dir[d][0],dy=dir[d][1];
		for(; s[tx][ty]==s[x][y]; )
			tx+=dx,ty+=dy;
		tx-=dx,ty-=dy;
		dx=dir[get_id(d,c)][0],dy=dir[get_id(d,c)][1];
		for(; s[tx][ty]==s[x][y]; )
			tx+=dx,ty+=dy;
		tx-=dx,ty-=dy;
		tx+=dir[d][0],ty+=dir[d][1];
		if(to_go(tx,ty))
			x=tx,y=ty;
		else if(c==0)
			c=1;
		else
			c=0,d=(d+1)%4;
	}
	printf("%d\n",s[x][y]-'0');
	return 0;
}
