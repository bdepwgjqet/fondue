/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  07/28/2012 05:07:58 PM
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
#define N 1510
#define M 1000010
#define S 4400100
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

struct node{ int x,y; }no[N][N];
struct qnode{ int r,c,x,y; }q[S],st;
int vis[N][N],mat[N][N],dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
char s[N][N];

int solve(int m,int n)
{
	memset(vis,0,sizeof(vis));
	qnode tmp;
	int ll,rr;
	q[ll=rr=0]=st;
	vis[st.r][st.c]=1;
	no[st.r][st.c].x=no[st.r][st.c].y=0;
	for(; ll<=rr;)
	{
		qnode now=q[ll++];
		for(int i=0; i<4; i++)
		{
			int r=now.r+dir[i][0],c=now.c+dir[i][1],x=now.x,y=now.y;
			if(r<0)
				r=m-1,x=now.x-1;
			else if(r>=m)
				r=0,x=now.x+1;
			else if(c<0)
				c=n-1,y=now.y-1;
			else if(c>=n)
				c=0,y=now.y+1;
			if(mat[r][c])
				continue;
			if(vis[r][c])
			{
				if(no[r][c].x!=x||no[r][c].y!=y)
					return 1;
			}
			else
			{
				vis[r][c]=1;
				no[r][c].x=x,no[r][c].y=y;
				tmp.r=r,tmp.c=c,tmp.x=x,tmp.y=y;
				q[++rr]=tmp;
			}
		}
	}
	return 0;
}

int main()
{
	int m,n;
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		for(int i=0; i<m; i++)
		{
			scanf("%s",s[i]);
			for(int j=0; j<n; j++)
			{
				mat[i][j]=0;
				if(s[i][j]=='S')
					st.r=i,st.c=j,st.x=0,st.y=0;
				if(s[i][j]=='#')
					mat[i][j]=1;
			}
		}
		if(solve(m,n))
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}
