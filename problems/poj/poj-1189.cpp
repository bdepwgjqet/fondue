#include <cstdio>
#include <cstring>
#define N 101
typedef long long LL;

char s[N],ss[N];
LL dp[N][N];

LL gcd(LL a,LL b){ return b?gcd(b,a%b):a; }

int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		getchar();
		memset(dp,0,sizeof(dp));
		dp[0][1]=1;
		for(int i=1; i<=n; i++)
		{
			//for(int j=1; j<=i; j++)
			//	printf("%d ",dp[i-1][j]);
			//puts("");
			gets(ss);
			int top=0;
			for(int j=0; ss[j]; j++)
			{
				if(ss[j]==' ') continue;
				s[top++]=ss[j];
			}
			for(int j=1; j<=i; j++)
			{
				if(s[j-1]=='*')
				{
					dp[i][j]+=dp[i-1][j];
					dp[i][j+1]+=dp[i-1][j];
				}
				else
				{
					dp[i+1][j+1]+=4*dp[i-1][j];
				}
			}
		}
		LL sum=0,a,b;
		for(int i=1; i<=n+1; i++)
			sum+=dp[n][i];
		a=sum,b=dp[n][m+1];
		if(b==0)
		{
			puts("0/1");
			continue;
		}
		LL g=gcd(a,b);
		printf("%lld/%lld\n",b/g,a/g);
	}
	return 0;
}
