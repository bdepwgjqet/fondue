/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  07/11/2012 03:26:31 PM
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
#define N 12
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

char s[20];
int mat[N][N][N],v[N][N][N],n;
struct node{ int x,y,z,cnt; }st,ed,q[N*N*N];
int dir[6][3]={ {1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1} };

int inboard(int x,int y,int z)
{
	return 0<=x&&x<n&&0<=y&&y<n&&0<=z&&z<n;
}

int solve()
{
	int l,r;
	memset(v,0,sizeof(v));
	st.cnt=0;
	q[l=r=0]=st;
	v[st.x][st.y][st.z]=1;
	while(l<=r)
	{
		node now=q[l++];
		if(now.x==ed.x&&now.y==ed.y&&now.z==ed.z)
			return now.cnt;
		for(int i=0; i<6; i++)
		{
			int x=now.x+dir[i][0],y=now.y+dir[i][1],z=now.z+dir[i][2];
			if(inboard(x,y,z)&&!v[x][y][z]&&mat[x][y][z]==0)
			{
				v[x][y][z]=1;
				++r;
				q[r].x=x,q[r].y=y,q[r].z=z;
				q[r].cnt=now.cnt+1;
			}
		}
	}
	return -1;
}

int main()
{
	int x,y,z;
	while(scanf("%s",s)!=EOF)
	{
		scanf("%d",&n);
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
			{
				scanf("%s",s);
				for(int k=0; k<n; k++)
					if(s[k]=='X')
						mat[j][k][i]=1;
					else
						mat[j][k][i]=0;
			}
		}
		scanf("%d%d%d",&st.y,&st.x,&st.z);
		scanf("%d%d%d",&ed.y,&ed.x,&ed.z);
		scanf("%s",s);
		int ret;
		ret=solve();
		if(ret<0)
			puts("NO ROUTE");
		else
			printf("%d %d\n",n,ret);
	}
	return 0;
}
