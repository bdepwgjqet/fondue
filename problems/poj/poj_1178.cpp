#include <cstdio>
#include <algorithm>
#include <cstring>
#define inf 1001
#define N 10
using namespace std;

char s[1001];
struct node{ int x,y; }no[N],q[1001];
int dir[8][2]={{-2,-1},{-2,1},{2,-1},{2,1},{1,2},{1,-2},{-1,2},{-1,-2}},vis[N][N],top,mat[N][N][N][N];

inline int inboard(int x,int y)
{
	return 0<=x&&x<8&&0<=y&&y<8;
}

int dis(node st,node ed)
{
	int l,r;
	memset(vis,-1,sizeof(vis));
	q[l=r=0]=st;
	vis[st.x][st.y]=0;
	for(; l<=r;)
	{
		node now=q[l++],nx;
		if(now.x==ed.x&&now.y==ed.y)
			return vis[now.x][now.y];
		for(int i=0; i<8; i++)
		{
			int x=now.x+dir[i][0],y=now.y+dir[i][1];
			if(!inboard(x,y))
				continue;
			if(vis[x][y]>=0)
				continue;
			vis[x][y]=vis[now.x][now.y]+1;
			nx.x=x,nx.y=y;
			q[++r]=nx;
		}
	}
	return inf;
}

int main()
{
	node a,b;
	for(int i=0; i<8; i++)
		for(int j=0; j<8; j++)
			for(int u=0; u<8; u++)
				for(int v=0; v<8; v++)
				{
					a.x=i,a.y=j,b.x=u,b.y=v;
					mat[i][j][u][v]=dis(a,b);
				}
	while(scanf("%s",s)!=EOF)
	{
		int l=strlen(s);
		top=0;
		for(int i=0; i<l; i+=2)
		{
			int y=s[i]-'A',x=s[i+1]-'1';
			y=7-y,x=7-x;
			no[top].x=x,no[top++].y=y;
		}
		int ret=inf,tmp;
		for(int i=0; i<8; i++)
			for(int j=0; j<8; j++)
			{
				tmp=0;
				for(int k=1; k<top; k++)
					tmp+=mat[no[k].x][no[k].y][i][j];
				for(int u=0; u<8; u++)
					for(int v=0; v<8; v++)
					{
						for(int k=1; k<top; k++)
						{
							int now=tmp-mat[no[k].x][no[k].y][i][j];
							now+=mat[no[k].x][no[k].y][u][v];
							now+=mat[i][j][u][v];
							now+=max(abs(no[0].x-u),abs(no[0].y-v));
							ret=min(ret,now);
						}
					}
			}
		if(top==1)
			ret=0;
		printf("%d\n",ret);
	}
	return 0;
}
