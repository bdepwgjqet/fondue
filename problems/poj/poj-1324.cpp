/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  07/13/2012 04:57:20 PM
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
#define N 21
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
int vis[N][N][(1<<14)+11];
struct node{ int x,y,p,cnt; }q[S],st,tmp[10];
int n,m,len;
int dir[4][2]={ {1,0},{0,-1},{-1,0},{0,1} };
int mat[N][N];

int getdir(int x,int y,int xx,int yy)
{
	for(int i=0; i<4; i++)
		if(x+dir[i][0]==xx&&y+dir[i][1]==yy)
			return i;
}

inline int inboard(int x,int y){ return 0<=x&&x<m&&0<=y&&y<n; } 
int hit(int x,int y)
{
	for(int i=0; i<len; i++)
		if(x==tmp[i].x&&y==tmp[i].y)
			return 1;
	return 0;
}

int solve()
{
	int l,r,dd[10];
	if(st.x==0&&st.y==0)
		return 0;
	memset(vis,0,sizeof(vis));
	st.cnt=0;
	q[l=r=0]=st;
	vis[st.x][st.y][st.p]=1;
	for(; l<=r; )
	{
		node now=q[l++],next;
		//printf("%d %d %d\n",now.x,now.y,now.cnt);
		tmp[0].x=now.x,tmp[0].y=now.y;
		int p=now.p,np;
		for(int i=len-2; i>=0; i--)
		{
			dd[i]=p%4,p/=4;
		//	printf("%d--->",dd[i]);
		}
		//puts("");
		for(int i=1; i<len; i++)
		{
			tmp[i].x=tmp[i-1].x+dir[dd[i-1]][0];
			tmp[i].y=tmp[i-1].y+dir[dd[i-1]][1];
		}
		for(int i=0; i<4; i++)
		{
			int x=now.x+dir[i][0],y=now.y+dir[i][1];
			if(!inboard(x,y))
				continue;
			if(mat[x][y]||hit(x,y))
				continue;
			if(x==0&&y==0)
				return now.cnt+1;
			next.x=x,next.y=y;
			np=(i+2)%4;
			for(int j=0; j<len-2; j++)
			{
			//	printf("%d--=>",dd[j]);
				np*=4,np+=dd[j];
			}
			//puts("");
			if(vis[x][y][np])
				continue;
			next.p=np;
			next.cnt=now.cnt+1;
			q[++r]=next;
			vis[x][y][np]=1;
		}
	}
	return -1;
}

int main()
{
	int ca=1;
	while(scanf("%d%d%d",&m,&n,&len)!=EOF)
	{
		if(m==0&&n==0&&len==0)
			break;
		printf("Case %d: ",ca++);
		int s=0,x,y,xx,yy,dir;
		scanf("%d%d",&x,&y);
		st.x=x-1,st.y=y-1;
		for(int i=0; i<len-1; i++)
		{
			scanf("%d%d",&xx,&yy);
			dir=getdir(x,y,xx,yy);
			//printf("%d\n",dir);
			s*=4;
			s+=dir;
			x=xx,y=yy;
		}
		st.p=s;
		int k;
		scanf("%d",&k);
		memset(mat,0,sizeof(mat));
		for(int i=0; i<k; i++)
		{
			scanf("%d%d",&x,&y);
			mat[x-1][y-1]=1;
		}
		printf("%d\n",solve());
	}
	return 0;
}
