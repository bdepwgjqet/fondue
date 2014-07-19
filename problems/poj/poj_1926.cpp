#include <cstdio>
#include <cstring>
#define N 111
#define CNT 1000000000

double dat[N],mat[N][N],ret[N][N],tmp[N][N];

void _mul(double ret[][N],double a[][N],double b[][N],int n)
{
	memset(tmp,0,sizeof(tmp));
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			for(int k=0; k<n; k++)
				tmp[i][j]+=a[i][k]*b[k][j];
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			ret[i][j]=tmp[i][j];
}

void show(double a[][N],int n)
{
	for(int i=0; i<n; i++,puts(""))
		for(int j=0; j<n; j++)
			printf("%.3lf ",a[i][j]);

}

void solve(int n)
{
	int b=CNT;
	memset(ret,0,sizeof(ret));
	for(int i=0; i<n; i++)
		ret[i][i]=1;
	for(; b; b>>=1)
	{
		if(b&1)
			_mul(ret,ret,mat,n);
		_mul(mat,mat,mat,n);
	}
	double r;
	for(int i=0; i<n; i++)
	{
		r=0;
		for(int j=0; j<n; j++)
			r+=dat[j]*ret[j][i];
		printf("%.3f\n",r);
	}
}

int main()
{
	int t,ca=1,n,m;
	scanf("%d",&t);
	for(; ca<=t; ca++)
	{
		if(ca>1)
			puts("");
		memset(mat,0,sizeof(mat));
		scanf("%d%d",&n,&m);
		for(int i=0; i<n; i++)
			scanf("%lf",&dat[i]);
		for(int i=0; i<m; i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			x--,y--;
			mat[x][y]=mat[y][x]=1;
		}
		int cnt;
		for(int i=0; i<n; i++)
		{
			cnt=0;
			for(int j=0; j<n; j++)
				if(mat[i][j]>0)
					cnt++;
			if(cnt==0)
				mat[i][i]=1;
			else
			{
				for(int j=0; j<n; j++)
					mat[i][j]/=cnt;
			}
		}
		solve(n);
	}
	return 0;
}
