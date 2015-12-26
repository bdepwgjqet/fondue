#include <cstdio>
#include <algorithm>
#define inf 0x3fffffff
#define N 111
using namespace std;

int op[N],dat[N]; //op[i] i..i-1
int dp1[N][N],dp2[N][N],q[N];

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		char s[10];
		int x;
		for(int i=1; i<=n; i++)
		{
			scanf("%s%d",s,&x);
			op[i]=(s[0]!='t');
			dat[i]=x;
		}
		for(int i=1; i<n; i++)
			dat[n+i]=dat[i],op[i+n]=op[i];
		for(int i=1; i<2*n; i++)
			dp1[i][i]=dp2[i][i]=dat[i];
		/*
		for(int i=1; i<2*n; i++)
			printf("%d ",dat[i]);
		puts("");
		for(int i=1; i<2*n; i++)
			printf("%d ",op[i]);
		puts("");
		*/
		for(int d=1; d<n; d++)
		{
			for(int i=1; i+d<2*n; i++)
			{
				int ret1=-inf,ret2=inf;
				for(int j=i+1; j<=i+d; j++)
				{
					if(op[j]==0)
					{
						ret1=max(ret1,dp1[i][j-1]+dp1[j][i+d]);
						ret2=min(ret2,dp2[i][j-1]+dp2[j][i+d]);
					}
					else
					{
						ret1=max(ret1,dp1[i][j-1]*dp1[j][i+d]);
						ret1=max(ret1,dp2[i][j-1]*dp2[j][i+d]);
						ret2=min(ret2,dp1[i][j-1]*dp2[j][i+d]);
						ret2=min(ret2,dp2[i][j-1]*dp1[j][i+d]);
					}
				}
				//printf("%d %d %d %d\n",ret1,ret2,i,i+d);
				dp1[i][i+d]=ret1;
				dp2[i][i+d]=ret2;
			}
		}
		int ret=-inf;
		for(int i=1; i<=n; i++)
			ret=max(ret,dp1[i][i+n-1]);
		printf("%d\n",ret);
		int tag=0;
		for(int i=1; i<=n; i++)
			if(ret==dp1[i][i+n-1])
			{
				if(tag) printf(" ");
				else tag=1;
				printf("%d",i);
			}
		puts("");
	}
	return 0;
}
