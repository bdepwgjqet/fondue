/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  07/11/2012 03:51:55 PM
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
#define N 201
#define M 1000010
#define S 40100
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

int mat[N][N];
struct node{ int x,y,dir,cnt; }q[S],st,ed;
int dir[4][2]={{1,0},{0,-1},{-1,0},{0,1}};
int dis[N][N],m,n;
char s[N];

int inboard(int x,int y)
{
	return 0<=x&&x<m+2&&0<=y&&y<n+2;
}

void solve()
{
	int l,r;
	st.dir=-1;
	st.cnt=0;
	q[l=r=0]=st;
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			dis[i][j]=inf;
	dis[st.x][st.y]=0;
	while(l<=r)
	{
		node now=q[l++];
//		printf("%d %d %d %d\n",now.x,now.y,now.cnt,mat[now.x][now.y]);
		for(int i=0; i<4; i++)
		{
			int x=now.x+dir[i][0],y=now.y+dir[i][1];
			if(!inboard(x,y))
				continue;
			int next_cnt=now.cnt+(i!=now.dir);
			if(x==ed.x&&y==ed.y)
			{
				if(next_cnt<dis[ed.x][ed.y])
					dis[ed.x][ed.y]=next_cnt;
				continue;
			}
			if(mat[x][y]==1)
				continue;
			if(dis[x][y]<=next_cnt)
				continue;
			dis[x][y]=next_cnt;
			++r;
			q[r].x=x,q[r].y=y,q[r].cnt=next_cnt,q[r].dir=i;
		}
	}
}

int main()
{
	int bd=1;
	while(scanf("%d%d",&n,&m)&&(m||n))
	{
		memset(mat,0,sizeof(mat));
		getchar();
		printf("Board #%d:\n",bd++);
		for(int i=1; i<=m; i++)
		{
			gets(s);
			for(int j=1; j<=n; j++)
				if(s[j-1]=='X')
					mat[i][j]=1;
				else
					mat[i][j]=0;
		}
		int pr=1;
		while(scanf("%d%d%d%d",&st.y,&st.x,&ed.y,&ed.x)!=EOF)
		{
			if(st.x==0&&st.y==0&&ed.x==0&&ed.y==0)
				break;
			solve();
			printf("Pair %d: ",pr++);
			if(dis[ed.x][ed.y]>=inf)
				puts("impossible.");
			else
				printf("%d segments.\n",dis[ed.x][ed.y]);
		}
		puts("");
	}
	return 0;
}
