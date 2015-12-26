#include <cstdio>
#include <algorithm>
#define N 201
#define inf 0x3ffffff

using namespace std;

int mat[N][N],dis[N][N];

struct node{ int x,y; }no[N],st[N];
int cmp(node a,node b){ return a.x<b.x; }

double gao(int a,int b,int n)
{
	for(int i=0; i<n; i++)
		no[i].x=dis[a][i],no[i].y=dis[b][i];
	sort(no,no+n,cmp);
	int top=0;
	st[0]=no[0];
	for(int i=1; i<n; i++)
	{
		while(top>=0&&no[i].y>=st[top].y)
			top--;
		st[++top]=no[i];
	}
	if(top==0)
		return min(st[0].x,st[0].y);
	double ret=inf;
	for(int i=1; i<=top; i++)
		ret=min(ret,(st[i-1].x+st[i].y+mat[a][b])/2.0);
	return ret;
}

int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)+1)
	{
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				mat[i][j]=(i==j)?0:inf;
		for(int i=0; i<m; i++)
		{
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			x--,y--;
			mat[x][y]=mat[y][x]=z;
		}
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				dis[i][j]=mat[i][j];

		for(int k=0; k<n; k++)
			for(int i=0; i<n; i++)
				for(int j=0; j<n; j++)
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
		double ret=inf;
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				if(mat[i][j]<inf)
					ret=min(ret,gao(i,j,n));
		printf("%.12lf\n",ret);
	}
	return 0;
}
