/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  07/13/2012 06:46:05 PM
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
#define N 22
#define M 1000010
#define S 2000100
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
struct node{ int x,y,bx,by,pcnt,scnt,p,d,pre; }st,ed,q[S];
char s[N];
char small_dir[4]={'n','s','w','e'};
char big_dir[4]={'N','S','W','E'};
int mp[N][N][N][N],ms[N][N][N][N],mat[N][N],id;
int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int m,n,can_solve,best_p,best_s;

int inboard(int x,int y){ return 0<=x&&x<m&&0<=y&&y<n; }
int better(int x,int y,int bx,int by,int pcnt,int scnt)
{
	if(pcnt<mp[x][y][bx][by])
		return 1;
	if(pcnt==mp[x][y][bx][by])
		return scnt<ms[x][y][bx][by];
	return 0;
}

void solve()
{
	int l,r;
	best_p=best_s=inf;
	for(int i=0; i<N; i++)
	for(int j=0; j<N; j++)
	for(int k=0; k<N; k++)
	for(int u=0; u<N; u++)
		mp[i][j][k][u]=inf,ms[i][j][k][u]=inf;
	q[l=r=0]=st;
	mp[st.x][st.y][st.bx][st.by]=ms[st.x][st.y][st.bx][st.by]=0;
	for(; l<=r;)
	{
		node now=q[l++],next;
		if(now.bx==ed.x&&now.by==ed.y)
			continue;
		for(int i=0; i<4; i++)
		{
			int x=now.x+dir[i][0],y=now.y+dir[i][1];
			if(!inboard(x,y))
				continue;
			if(mat[x][y]==1)
				continue;
			if(x==now.bx&&y==now.by)
			{
				int xx=x+dir[i][0],yy=y+dir[i][1];
				if(!inboard(xx,yy))
					continue;
				if(mat[xx][yy]==1)
					continue;
				if(xx==ed.x&&yy==ed.y)
				{
					if(better(x,y,xx,yy,now.pcnt+1,now.scnt+1))
					{
						can_solve=1;
						mp[x][y][xx][yy]=now.pcnt+1;
						ms[x][y][xx][yy]=now.scnt+1;
						next.x=x,next.y=y,next.bx=xx,next.by=yy;
						next.pcnt=now.pcnt+1,next.scnt=now.scnt+1;
						next.p=1,next.d=i,next.pre=l-1;
						q[++r]=next;
						if(next.pcnt<best_p||(next.pcnt==best_p&&next.scnt<best_s))
							id=r,best_p=next.pcnt,best_s=next.scnt;
					}
					continue;
				}
				if(better(x,y,xx,yy,now.pcnt+1,now.scnt+1))
				{
					mp[x][y][xx][yy]=now.pcnt+1;
					ms[x][y][xx][yy]=now.scnt+1;
					next.x=x,next.y=y,next.bx=xx,next.by=yy;
					next.pcnt=now.pcnt+1,next.scnt=now.scnt+1;
					next.p=1,next.d=i,next.pre=l-1;
					q[++r]=next;
				}
			}
			else
			{
				if(better(x,y,now.bx,now.by,now.pcnt,now.scnt+1))
				{
					mp[x][y][now.bx][now.by]=now.pcnt;
					ms[x][y][now.bx][now.by]=now.scnt+1;
					next.x=x,next.y=y,next.bx=now.bx,next.by=now.by;
					next.pcnt=now.pcnt,next.scnt=now.scnt+1;
					next.p=0,next.d=i,next.pre=l-1;
					q[++r]=next;
				}
			}
		}
	}
//	printf("%d\n",r);
}

void show(int id)
{
	if(q[id].pre>=0)
		show(q[id].pre);
	else
		return;
	if(q[id].p==1)
		printf("%c",big_dir[q[id].d]);
	else
		printf("%c",small_dir[q[id].d]);
}

int main()
{
	int ca=1;
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		can_solve=0;
		if(m==0&&n==0)
			continue;
		printf("Maze #%d\n",ca++);
		memset(mat,0,sizeof(mat));
		for(int i=0; i<m; i++)
		{
			scanf("%s",s);
			for(int j=0; j<n; j++)
			{
				if(s[j]=='S')
				{
					st.x=i,st.y=j;
					st.pcnt=st.scnt=0;
					st.pre=-1;
				}
				else if(s[j]=='B')
					st.bx=i,st.by=j;
				else if(s[j]=='#')
					mat[i][j]=1;
				else if(s[j]=='T')
				{
					ed.x=i,ed.y=j;
					mat[i][j]=-1;
				}
			}
		}
		solve();
		if(can_solve)
		{
			show(id);
			puts("");
			//printf("%d %d\n",q[id].pcnt,q[id].scnt);
		}
		else
			puts("Impossible.");
		puts("");
	}
	return 0;
}
