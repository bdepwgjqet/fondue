#include <cstdio>
#include <cstring>
#define inf 0x3fffffff
#define N 30
#define S 10100

int id[N][N],mat[N][N],top,now[N][N],ret[N][N],tmp[N][N];

void show(int mat[][N])
{
	for(int i=0; i<top; i++,puts(""))
		for(int j=0; j<top; j++)
			printf("%d ",mat[i][j]);
}

void mul(int c[][N],int a[][N],int b[][N])
{
	memset(tmp,0,sizeof(tmp));
	for(int i=0; i<top; i++)
		for(int j=0; j<top; j++)
			for(int k=0; k<top; k++)
				tmp[i][j]+=a[i][k]*b[k][j];
	for(int i=0; i<top; i++)
		for(int j=0; j<top; j++)
			if(tmp[i][j])
				c[i][j]=1;
			else
				c[i][j]=0;
}

void solve(int x)
{
	memset(ret,0,sizeof(ret));
	for(int i=0; i<top; i++)
		ret[i][i]=1;
	for(; x;)
	{
		if(x&1)
		{
			mul(ret,ret,now);
		}
		mul(now,now,now);
		x>>=1;
	}
}

int main()
{
	int ts,m,n;
	scanf("%d",&ts);
	for(; ts--;)
	{
		memset(mat,0,sizeof(mat));
		scanf("%d%d\n",&m,&n);
		top=0;
		for(int i=1; i<=m; i++)
			for(int j=1; j<=n; j++)
				id[i][j]=top++;
		for(int i=1; i<=m; i++)
			for(int j=1; j<=n; j++)
			{
				scanf(" (");
				for(int k=0; k<4; k++)
				{
					int x,y;
					scanf("%*c%d%*c%d%*c",&x,&y);
					if(k+1<4)
						scanf("%*c");
					mat[id[i][j]][id[x][y]]=1;
				}
				scanf(")");
			}
		for(int i=0; i<top; i++)
			mat[id[m][n]][i]=0;
		int qs;
		scanf("%d",&qs);
		for(int i=0; i<qs; i++)
		{
			int x;
			scanf("%d",&x);
			for(int u=0; u<top; u++)
				for(int v=0; v<top; v++)
					now[u][v]=mat[u][v];
			solve(x);
			if(ret[0][id[m][n]])
			{
				int cnt=0;
				for(int j=0; j<top; j++)
					if(ret[0][j])
						cnt++;
				if(cnt>1)
					puts("Maybe");
				else
					puts("True");
			}
			else
				puts("False");
		}
		puts("");
	}
	return 0;
}
