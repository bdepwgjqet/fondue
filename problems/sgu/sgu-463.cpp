#include <cstdio>
#include <cstring>
#define N 111

int mat[N][N];
char sm[N][N];
char s[1111];
int vis[N][N];
int dir[4][2]={ {1,0},{0,-1},{-1,0},{0,1} };
struct node{ int d,x,y; }no;

int solve()
{
	memset(vis,0,sizeof(vis));
	int l=strlen(s);
	int ret=0;
	no.x=no.y=0,no.d=3;
	for(int i=0; i<l; i++)
	{
		if(s[i]=='L')
			no.d=((no.d-1)%4+4)%4;
		else if(s[i]=='R')
			no.d=(no.d+1)%4;
		else
		{
			int x=no.x+dir[no.d][0],y=no.y+dir[no.d][1],xx[3],yy[3];
			if(no.d==0)
			{
				xx[1]=x,yy[1]=y;
				xx[2]=x,yy[2]=y+1;
			}
			else if(no.d==1)
			{
				xx[1]=no.x,yy[1]=no.y;
				xx[2]=no.x+1,yy[2]=no.y;
			}
			else if(no.d==2)
			{
				xx[1]=no.x,yy[1]=no.y;
				xx[2]=no.x,yy[2]=no.y+1;
			}
			else
			{
				xx[1]=x,yy[1]=y;
				xx[2]=x+1,yy[2]=y;
			}
			for(int k=1; k<=2; k++)
			{
				if(vis[xx[k]][yy[k]])
					ret+=mat[xx[k]][yy[k]]/2;
				else
				{
					ret+=mat[xx[k]][yy[k]];
					vis[xx[k]][yy[k]]=1;
				}
			}
			no.x=x,no.y=y;
		}
	}
	return ret;
}

int main()
{
	int m,n;
	while(scanf("%d%d",&m,&n)+1)
	{
		memset(mat,0,sizeof(mat));
		for(int i=1; i<=m; i++)
			scanf("%s",sm[i]+1);
		for(int i=1; i<=m; i++)
			for(int j=1; j<=n; j++)
				mat[i][j]=sm[i][j]-'0';
		scanf("%s",s);
		printf("%d\n",solve());
	}
	return 0;
}
