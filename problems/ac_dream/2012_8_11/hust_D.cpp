#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 1111
using namespace std;

int dp[N][N],cnt[N][N];
char s1[N],s2[N];
int n,l1,l2;

int solve()
{
	int ret=0;
	memset(dp,0,sizeof(dp));
	memset(cnt,0,sizeof(cnt));
	for(int i=1; i<=l1; i++)
		for(int j=1; j<=l2; j++)
		{
			if(s1[i]==s2[j])
				cnt[i][j]=cnt[i-1][j-1]+1;
			else
				cnt[i][j]=0;
		}
	for(int i=1; i<=l1; i++)
		for(int j=1; j<=l2; j++)
		{
			if(s1[i]==s2[j])
			{
				if(cnt[i][j]>=n)
				{
					for(int k=n; k<=cnt[i][j]; k++)
						dp[i][j]=max(dp[i][j],dp[i-k][j-k]+k);
				}
			}
			dp[i][j]=max(dp[i][j],max(dp[i-1][j],dp[i][j-1]));
			ret=max(ret,dp[i][j]);
		}
	return ret;
}

int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			break;
		scanf("%s%s",s1+1,s2+1);
		l1=strlen(s1+1);
		l2=strlen(s2+1);
		int ret=solve();
		printf("%d\n",ret);
	}
	return 0;
}
