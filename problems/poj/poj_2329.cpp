#include <cstdio>
#include <cstring>
#include <algorithm>
#define inf 0x3fffff
#define N 201
using namespace std;

int mat[N][N],l[N][N],r[N][N],u[N][N],d[N][N];
struct node{ int x,y,t; }ul[N][N],ur[N][N],dl[N][N],dr[N][N];

int dis(node a,node b)
{
	return abs(a.x-b.x)+abs(a.y-b.y);
}
int inboard(int x,int y,int n)
{
	return 1<=x&&x<=n&&1<=y&&y<=n;
}

void solve(int n)
{
	memset(l,0,sizeof(l));
	memset(r,0,sizeof(r));
	memset(u,0,sizeof(u));
	memset(d,0,sizeof(d));
	for(int i=1; i<=n; i++)
		r[i][n+1]=inf,d[n+1][i]=inf,l[i][0]=-inf,u[0][i]=-inf;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
		{
			l[i][j]=mat[i][j]>0?j:l[i][j-1];
			u[i][j]=mat[i][j]>0?i:u[i-1][j];
		}
	for(int i=n; i>=1; i--)
		for(int j=n; j>=1; j--)
		{
			r[i][j]=mat[i][j]>0?j:r[i][j+1];
			d[i][j]=mat[i][j]>0?i:d[i+1][j];
		}
	int d1,d2;
	node tmp,now;
	for(int i=1; i<=n; i++)
	{
		ul[i][1].x=u[i][1];
		ul[i][1].y=1,ul[i][1].t=0;
		for(int j=2; j<=n; j++)
		{
			tmp.x=u[i][j],tmp.y=j;
			now.x=i,now.y=j;
			d1=dis(ul[i][j-1],now);
			d2=dis(tmp,now);
			if(d1<d2)
				ul[i][j]=ul[i][j-1];
			else if(d1>d2)
				ul[i][j]=tmp,ul[i][j].t=0;
			else
				ul[i][j]=tmp,ul[i][j].t=1;
		}
	}
	for(int i=n; i>=1; i--)
	{
		dl[i][1].x=d[i][1];
		dl[i][1].y=1,dl[i][1].t=0;
		for(int j=2; j<=n; j++)
		{
			tmp.x=d[i][j],tmp.y=j;
			now.x=i,now.y=j;
			d1=dis(dl[i][j-1],now);
			d2=dis(tmp,now);
			if(d1<d2)
				dl[i][j]=dl[i][j-1];
			else if(d1>d2)
				dl[i][j]=tmp,dl[i][j].t=0;
			else
				dl[i][j]=tmp,dl[i][j].t=1;
		}
	}
	for(int i=1; i<=n; i++)
	{
		ur[i][n].x=u[i][n];
		ur[i][n].y=n,ur[i][n].t=0;
		for(int j=n-1; j>=1; j--)
		{
			tmp.x=u[i][j],tmp.y=j;
			now.x=i,now.y=j;
			d1=dis(ur[i][j+1],now);
			d2=dis(tmp,now);
			if(d1<d2)
				ur[i][j]=ur[i][j+1];
			else if(d1>d2)
				ur[i][j]=tmp,ur[i][j].t=0;
			else
				ur[i][j]=tmp,ur[i][j].t=1;
		}
	}
	for(int i=n; i>=1; i--)
	{
		dr[i][n].x=d[i][n];
		dr[i][n].y=n,dr[i][n].t=0;
		for(int j=n-1; j>=1; j--)
		{
			tmp.x=d[i][j],tmp.y=j;
			now.x=i,now.y=j;
			d1=dis(dr[i][j+1],now);
			d2=dis(tmp,now);
			if(d1<d2)
				dr[i][j]=dr[i][j+1];
			else if(d1>d2)
				dr[i][j]=tmp,dr[i][j].t=0;
			else
				dr[i][j]=tmp,dr[i][j].t=1;
		}
	}
}

int equal(int i,int j,int &x,int &y,int n)
{
	node now;
	now.x=i,now.y=j;
	int len=inf,dul,dur,ddl,ddr,tag=0;
	dul=dis(now,ul[i][j]);
	dur=dis(now,ur[i][j]);
	ddl=dis(now,dl[i][j]);
	ddr=dis(now,dr[i][j]);
	len=min(len,dul);
	len=min(len,dur);
	len=min(len,ddl);
	len=min(len,ddr);
	if(len==dul)
	{
		if(ul[i][j].t) return 0;
		x=ul[i][j].x,y=ul[i][j].y;
		tag=1;
	}
	if(len==dur)
	{
		if(ur[i][j].t) return 0;
		if(tag)
		{
			if(x!=ur[i][j].x||y!=ur[i][j].y)
				return 0;
		}
		else
			x=ur[i][j].x,y=ur[i][j].y,tag=1;
	}
	if(len==ddr)
	{
		if(dr[i][j].t) return 0;
		if(tag)
		{
			if(x!=dr[i][j].x||y!=dr[i][j].y)
				return 0;
		}
		else
			x=dr[i][j].x,y=dr[i][j].y,tag=1;
	}
	if(len==ddl)
	{
		if(dl[i][j].t) return 0;
		if(tag)
		{
			if(x!=dl[i][j].x||y!=dl[i][j].y)
				return 0;
		}
		else
			x=dl[i][j].x,y=dl[i][j].y,tag=1;
	}
	return inboard(x,y,n);
}

void show(int n)
{
	int x,y;
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			if(mat[i][j]==0)
			{
				if(equal(i,j,x,y,n))
					printf("%d",mat[x][y]);
				else
					printf("0");
			}
			else
				printf("%d",mat[i][j]);
			if(j<n)
				printf(" ");
		}
		puts("");
	}
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
			{
				scanf("%d",&mat[i][j]);
		//		printf("%d ",mat[i][j]);
			}
		solve(n);
		show(n);
	}
	return 0;
}
