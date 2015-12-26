#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 1011
using namespace std;

struct node{ int l,r; }dp[N][N];
char s[3];
int mat[N][N],u[N][N],st[N],top;

int main()
{
	int ts;
	scanf("%d",&ts);
	for(; ts--;)
	{
		int m,n;
		scanf("%d%d",&m,&n);
		memset(u,0,sizeof(u));
		for(int i=1; i<=m; i++)
			for(int j=1; j<=n; j++)
			{
				scanf("%s",s);
				if(s[0]=='R')
				{
					mat[i][j]=1;
					u[i][j]=0;
				}
				else
				{
					mat[i][j]=0;
					u[i][j]=u[i-1][j]+1;
				}
			}
		for(int i=1; i<=m; i++)
		{
			st[top=0]=1;
			dp[i][1].l=1;
			for(int j=2; j<=n; j++)
			{
				for(; top>=0; top--)
				{
					if(u[i][j]<u[i][st[top]])
						dp[i][st[top]].r=j-1;
					else
						break;
				}
				dp[i][j].l=(top>=0)?st[top]+1:1;
				st[++top]=j;
			}
			for(; top>=0; top--)
				dp[i][st[top]].r=n;
		}
		int ret=0;
		for(int i=1; i<=m; i++)
			for(int j=1; j<=n; j++)
			{
				ret=max(ret,(dp[i][j].r-dp[i][j].l+1)*(u[i][j]));
			}
		printf("%d\n",ret*3);
	}
	return 0;
}
