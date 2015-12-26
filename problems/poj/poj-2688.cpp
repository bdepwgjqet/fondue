/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  07/13/2012 01:26:25 PM
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

struct node{ int x,y,s,cnt; }st,q[S];
int mat[N][N],id[N][N],top,dis[N][N][1025],m,n;
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}},lasts,ret;
char s[N];

inline int B(int i){ return 1<<i; }
inline int inboard(int x,int y)
{
	return 0<=x&&x<m&&0<=y&&y<n;
}

void solve()
{
	int l,r;
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			for(int k=0; k<1025; k++)
				dis[i][j][k]=inf;
	st.cnt=0;
	dis[st.x][st.y][st.s]=0;
	q[l=r=0]=st;
	for(; l<=r;)
	{
		node now=q[l++],next;
	//	printf("%d %d\n",now.x,now.y);
		if(now.cnt>dis[now.x][now.y][now.s])
			continue;
		if(now.s>=lasts)
		{
			ret=min(ret,now.cnt);
			continue;
		}
		if(now.cnt>=ret)
			continue;
		for(int i=0; i<4; i++)
		{
			int x=now.x+dir[i][0],y=now.y+dir[i][1],ns;
			if(!inboard(x,y))
				continue;
			if(mat[x][y]<0)
				continue;
			if(mat[x][y]==1)
			{
				int ii=id[x][y];
				if(now.s&B(ii))
					ns=now.s;
				else
					ns=now.s|B(ii);
			}
			else
				ns=now.s;
			if(dis[x][y][ns]>now.cnt+1)
			{
				dis[x][y][ns]=now.cnt+1;
				next.x=x,next.y=y,next.s=ns,next.cnt=now.cnt+1;
				q[++r]=next;
			}
		}
	}
}

int main()
{
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		memset(id,0,sizeof(id));
		top=0;
		if(m==0&&n==0)
			break;
		for(int i=0; i<m; i++)
		{
			scanf("%s",s);
			for(int j=0; j<n; j++)
			{
				if(s[j]=='.')
					mat[i][j]=0;
				else if(s[j]=='o')
				{
					mat[i][j]=0;
					st.x=i,st.y=j,st.s=0;
				}
				else if(s[j]=='*')
				{
					mat[i][j]=1;
					id[i][j]=top++;
				}
				else
					mat[i][j]=-1;
			}
		}
		lasts=B(top)-1;
		ret=inf;
		solve();
		if(ret>=inf)
			puts("-1");
		else
			printf("%d\n",ret);
	}
	return 0;
}
