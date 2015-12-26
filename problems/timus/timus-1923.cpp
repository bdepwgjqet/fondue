#include <cstdio>
#include <cstring>
#define N 55

char s[N][N];
int m,n;
int vis[N][N];
int ret=0;

inline int inboard(int i,int j){ return 0<=i&&i<m&&0<=j&&j<n; }

void fill(int x,int y,int now,int z)
{
	if(!inboard(x,y))
		return;
	if(vis[x][y])
		return;
	if(s[x][y]!=now)
		return;
	vis[x][y]=1;
	s[x][y]=z;
	fill(x+1,y,now,z);
	fill(x-1,y,now,z);
	fill(x,y+1,now,z);
	fill(x,y-1,now,z);
}

void gao(int x,int y,int z)
{
	if(!inboard(x,y))
		return;
	if(vis[x][y])
		return;
	if(s[x][y]!=z)
		return;
	vis[x][y]=1;
	ret++;
	gao(x+1,y,z);
	gao(x-1,y,z);
	gao(x,y+1,z);
	gao(x,y-1,z);
}

int main()
{
	while(scanf("%d%d",&m,&n)+1)
	{
		for(int i=0; i<m; i++)
		{
			scanf("%s",&s[i]);
			for(int j=0; j<n; j++)
				s[i][j]-='0';
		}
		int l;
		scanf("%d",&l);
		int now=0;
		for(int i=0; i<l; i++)
		{
			int x,x0,y0;
			scanf("%d",&x);
			if(now==0)
				x0=m-1,y0=0;
			else
				x0=0,y0=n-1;
			memset(vis,0,sizeof(vis));
			fill(x0,y0,s[x0][y0],x);
			/*
			for(int u=0; u<m; u++,puts(""))
				for(int v=0; v<n; v++)
					printf("%c",s[u][v]+'0');
			puts("");
			*/
			now^=1;
		}
		int r1,r2;
		memset(vis,0,sizeof(vis));
		ret=0;
		gao(m-1,0,s[m-1][0]);
		r1=ret;
		ret=0;
		memset(vis,0,sizeof(vis));
		gao(0,n-1,s[0][n-1]);
		r2=ret;
		printf("%d\n%d\n",r1,r2);
	}
	return 0;
}
