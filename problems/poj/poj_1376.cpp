/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  07/13/2012 11:45:58 AM
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
int mat[N][N],m,n; 
int dir[4][2]={{1,0},{0,-1},{-1,0},{0,1}},dis[N][N][4];
int dd[4][2]={{-1,-1},{-1,0},{0,-1},{0,0}};
struct node{ int x,y,d,cnt; }st,ed,q[S];
map<string,int> mp;
string s;

inline int inboard(int x,int y)
{
	return 1<=x&&x<m&&1<=y&&y<n;
}

inline int anti(int x,int y,int d,int cnt)
{
	int xx,yy,x1,y1;
	for(int k=1; k<=cnt; k++)
	{
		x1=x+k*dir[d][0],y1=y+k*dir[d][1];
		for(int i=0; i<4; i++)
		{
			xx=x1+dd[i][0],yy=y1+dd[i][1];
			if(mat[xx][yy])
				return 1;
		}
	}
	return 0;
}

void solve()
{
	int l=0,r=0,x,y,d;
	st.cnt=0;
	q[0]=st;
	for(int i=0; i<=m; i++)
		for(int j=0; j<n; j++)
			for(int k=0; k<4; k++)
				dis[i][j][k]=inf;
	dis[st.x][st.y][st.d]=0;
	for(; l<=r;)
	{
		node now=q[l++],next;
//		printf("%d %d %d\n",now.x,now.y,now.d);
		for(int i=1; i<=3; i++)
		{
			x=now.x+i*dir[now.d][0],y=now.y+i*dir[now.d][1];
		//	printf("%d %d=>\n",x,y);
			if(!inboard(x,y))
				continue;
			if(anti(now.x,now.y,now.d,i))
				continue;
			if(dis[x][y][now.d]>now.cnt+1)
			{
				dis[x][y][now.d]=now.cnt+1;
				if(x==ed.x&&y==ed.y)
					continue;
				next.x=x,next.y=y,next.cnt=now.cnt+1,next.d=now.d;
				q[++r]=next;
			}
		}
		for(int i=-1; i<=1; i+=2)
		{
			int ii=((now.d+i)%4+4)%4;
			if(dis[now.x][now.y][ii]>now.cnt+1)
			{
				dis[now.x][now.y][ii]=now.cnt+1;
				next.x=now.x,next.y=now.y,next.cnt=now.cnt+1,next.d=ii;
				q[++r]=next;
			}
		}
	}
}

int main()
{
	int ret;
	mp[string("south")]=0;
	mp[string("west")]=1;
	mp[string("north")]=2;
	mp[string("east")]=3;
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		if(m==0&&n==0)
			break;
		for(int i=0; i<m; i++)
			for(int j=0; j<n ;j++)
				scanf("%d",&mat[i][j]);

		scanf("%d%d%d%d",&st.x,&st.y,&ed.x,&ed.y);
		cin>>s;
		st.d=mp[s];
		solve();
		ret=inf;
		for(int i=0; i<4; i++)
			ret=min(ret,dis[ed.x][ed.y][i]);
		if(ret<inf)
			printf("%d\n",ret);
		else
			puts("-1");
	}
	return 0;
}
