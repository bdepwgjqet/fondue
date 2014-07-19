#include <cstdio>
#include <cstring>;
#define MAXN 110

int sum[MAXN][MAXN],mat[MAXN][MAXN];

inline int max(int a,int b){ return a<b?b:a; }

int main()
{
	int n,m,w,h,ww,hh,ret,i,j,x,y;
	while(scanf("%d",&n)&&n)
	{
		memset(mat,0,sizeof(mat));
		memset(sum,0,sizeof(sum));
		scanf("%d%d",&w,&h);
		for(i=0; i<n; i++)
		{
			scanf("%d%d",&y,&x);
			mat[x][y]=1;
		}
		scanf("%d%d",&ww,&hh);
		for(i=1; i<=h; i++)
			for(j=1; j<=w; j++)
				sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+mat[i][j];
		ret=0;
		for(i=1; i+hh-1<=h; i++)
			for(j=1; j+ww-1<=w; j++)
				ret=max(ret,sum[i+hh-1][j+ww-1]-sum[i+hh-1][j-1]-sum[i-1][j+ww-1]+sum[i-1][j-1]);
		printf("%d\n",ret);
	}
	return 0;
}
