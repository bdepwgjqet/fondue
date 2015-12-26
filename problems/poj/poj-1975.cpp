#include <cstdio>
#define inf 0x3ffffff
#define N 101

int mat[N][N];

void floyd(int n)
{
	for(int k=0; k<n; k++)
	for(int i=0; i<n; i++)
	for(int j=0; j<n; j++)
		if(mat[i][k]+mat[k][j]<mat[i][j])
			mat[i][j]=mat[i][k]+mat[k][j];
}

int main()
{
	int t,m,n;
	scanf("%d",&t);
	for(; t--;)
	{
		scanf("%d%d",&n,&m);
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				mat[i][j]=inf;
		for(int i=0; i<m; i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			x--,y--;
			mat[x][y]=1;
		}
		floyd(n);
		int ret=0,l,r,mid=(n-1)/2;
		for(int i=0; i<n; i++)
		{
			l=0,r=0;
			for(int j=0; j<n; j++)
			{
				if(mat[i][j]<inf)
					l++;
				if(mat[j][i]<inf)
					r++;
			}
			//printf("%d %d %d %d\n",l,r,mid,i);
			if(l<=mid&&r<=mid)
				ret++;
		}
		printf("%d\n",n-ret);
	}
	return 0;
}
