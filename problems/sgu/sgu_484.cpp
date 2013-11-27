#include <cstdio>
#include <cstring>

#define N 111
#define S 111111

struct node{ int x,y; }q[S],st;

char mat[N][N];
int m,n;
int vis[N][N];

inline int inboard(int x,int y){ return 0<=x&&x<=m&&0<=y&&y<n; }

int gao()
{
	memset(vis,0,sizeof(vis));
	int l,r,f=0;
	char pre='P';
	q[l=r=0]=st;
	for(; l<=r;)
	{
		node now=q[l++],next=now;
		if(now.x==m)
			return now.y+1;
		if(vis[now.x][now.y])
			return -1;
		vis[now.x][now.y]=1;
		char nc=mat[now.x][now.y];
		if(nc==pre&&!f)
			next.x++,f=1;
		else if(nc=='/')
			next.y--,f=0;
		else if(nc=='\\')
			next.y++,f=0;
		else
			next.x++,f=1;
		if(!inboard(next.x,next.y))
			return -1;
		pre=nc;
		q[++r]=next;
	}
	return -1;
}

int main()
{
	while(scanf("%d%d",&m,&n)+1)
	{
		for(int i=0; i<m; i++)
		{
			scanf("%s",&mat[i]);
			for(int j=0; j<n; j++)
				if(mat[i][j]=='P')
					st.x=i,st.y=j;
		}
		printf("%d\n",gao());
	}
	return 0;
}
