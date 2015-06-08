/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  09/26/2012 12:49:41 PM
 ***/

#include <cstring>
#include <cstdio>
#include <cstdlib>
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
#define X 262145
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

char s[N][N];
int m,n,top,pre,len;

struct node{ int x,y,pre,cnt,d; }no[S];
int inboard(int x,int y){ return 0<=x&&x<m&&0<=y&&y<n; }
int dir[4][2]={{-1,0},{1,0},{0,1},{0,-1}},pred;
set<int> st;

void build(int x,int y)
{
	no[top].x=x,no[top].y=y;
	no[top].pre=pre;
	no[top].d=pred;
	pre=top;
	top++;
	for(int i=0; i<4; i++)
	{
		int xx=x+dir[i][0],yy=y+dir[i][1];
		if(!inboard(xx,yy))
			continue;
		if(s[x][y]!=s[xx][yy]+1)
			continue;
		pred=i;
		build(xx,yy);
	}
}

int ok(int x,int y,int id,int pd)
{
	if(!inboard(x,y))
		return 0;
	if(s[x][y]=='#')
		return 0;
	if(s[x][y]!='.')
		if(s[x][y]==' '||s[x][y]==0)
			return 0;
	int nd=id,state=(x*15+y)*X,dst=pd;
	for(int i=0; i<len-1; i++)
	{
		if(i<len-2)
			dst<<=2,dst+=no[nd].d;
		if(no[nd].x==x&&no[nd].y==y)
			return 0;
		nd=no[nd].pre;
	}
	state+=dst;
	if(st.find(state)!=st.end())
		return 0;
	st.insert(state);
	return 1;
}

int bfs()
{
	int l=top-1,r=top-1;
	no[l].cnt=0;
	for(; l<=r; l++)
	{
		node now=no[l],next;
		for(int i=0; i<4; i++)
		{
			int xx=now.x+dir[i][0],yy=now.y+dir[i][1];
			if(!ok(xx,yy,l,i))
				continue;
			if(s[xx][yy]=='@')
			{
				return now.cnt+1; 
			}
			next.cnt=now.cnt+1;
			next.x=xx,next.y=yy,next.pre=l;
			next.d=i;
			no[++r]=next;
		}
	}
	return -1;
}

int main()
{
	int sx,sy,rx,ry;
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		memset(s,0,sizeof(s));
		st.clear();
		len=-1;
		for(int i=0; i<m; i++)
		{
			scanf("%s",s[i]);
			for(int j=0; j<n; j++)
			{
				if(s[i][j]<='9'&&'0'<=s[i][j])
					if(len<s[i][j]-'0')
						len=s[i][j]-'0',sx=i,sy=j;
				if(s[i][j]=='@')
					rx=i,ry=j;
			}
		}
		top=0;
		pre=-1;
		pred=4;
		build(sx,sy);
		len=top;
		printf("%d\n",bfs());
	}
	return 0;
}
