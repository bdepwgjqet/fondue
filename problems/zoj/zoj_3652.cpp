#include <cstdio>
#include <algorithm>
#include <cstring>
#define inf 0x3fffffff
#define S 2000011
#define N 55

using namespace std;

int m,n,inil,mat[N][N],boss[N][N],bitch;
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

inline int inboard(int x,int y){ return 1<=x&&x<=m&&1<=y&&y<=n; }
struct node{ int x,y,l,c,st; }st,ed,q[S];
int dp[N][N][N][11];

inline int B(int i){ return 1<<i; }

void bfs()
{
	int l,r;
	for(int i=0; i<=m; i++)
		for(int j=0; j<=n; j++)
			for(int k=0; k<B(bitch); k++)
				for(int u=0; u<11; u++)
					dp[i][j][k][u]=inf;
	st.c=0,st.l=0,st.st=B(bitch)-1;
	q[l=r=0]=st;
	dp[st.x][st.y][st.st][st.l]=0;
	for(; l<=r;)
	{
		node now=q[l++],next;
		if(now.l==0)
		{
			now.l=inil;
			now.c++;
			q[++r]=now;
			continue;
		}
		for(int i=0; i<4; i++)
		{
			int xx=now.x+dir[i][0],yy=now.y+dir[i][1],nl=now.l,nc=now.c,nb=now.st;
			if(!inboard(xx,yy))
				continue;
			if(mat[xx][yy]==-1)
				continue;
			if(mat[xx][yy]>0)
			{
				if(now.st&B(mat[xx][yy]-1))
				{
					nl=0;
				}
				else
					nl--;
			}
			else
				nl--;

			if(boss[xx][yy]>0)
				if(now.st&B(boss[xx][yy]-1))
					nb=now.st-B(boss[xx][yy]-1);

			if(nc<dp[xx][yy][nb][nl])
			{
				dp[xx][yy][nb][nl]=nc;
				next.c=nc,next.l=nl,next.st=nb;
				next.x=xx,next.y=yy;
				if(r+1>=S)
					for(;;);
				q[++r]=next;
			}
		}
	}
}

int main()
{
	while(scanf("%d%d%d",&m,&n,&inil)+1)
	{
		memset(boss,0,sizeof(boss));
		for(int i=1; i<=m; i++)
			for(int j=1; j<=n; j++)
				scanf("%d",&mat[i][j]);
		scanf("%d",&bitch);
		for(int i=1; i<=bitch; i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			boss[x][y]=i;
		}
		scanf("%d%d%d%d",&st.x,&st.y,&ed.x,&ed.y);
		bfs();
		int rr=inf;
		for(int i=0; i<B(bitch); i++)
		{
			for(int u=0; u<=inil; u++)
			{
				rr=min(rr,dp[ed.x][ed.y][i][u]);
			}
		}
		if(rr>=inf)
			puts("We need God's help!");
		else
			printf("%d\n",rr);
	}
	return 0;
}
