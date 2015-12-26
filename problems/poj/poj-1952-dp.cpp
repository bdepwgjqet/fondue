#include <cstdio>
#include <algorithm>
#include <cstring>
#define N 100001
using namespace std;

int dat[N],n,dp[N],cnt[N];

void solve()
{
	memset(cnt,0,sizeof(cnt));
	memset(dp,0,sizeof(dp));
	int mx=0;
	for(int i=1; i<=n; i++)
	{
		dp[i]=1,cnt[i]=1;
		for(int j=i-1; j>=0; j--)
		{
			if(dat[j]>dat[i])
			{
				if(dp[j]+1>dp[i])
					dp[i]=dp[j]+1,cnt[i]=cnt[j];
				else if(dp[j]+1==dp[i])
					cnt[i]+=cnt[j];
			}
			else if(dat[j]==dat[i])
			{
				if(dp[i]==1)
					cnt[i]=0;
				break;
			}
		}
	}
	int ret=0,cc=0;
	for(int i=1; i<=n; i++)
		if(ret<dp[i])
			ret=dp[i];
	for(int i=1; i<=n; i++)
		if(dp[i]==ret)
			cc+=cnt[i];
	printf("%d %d\n",ret,cc);

}

int main()
{
	for(; scanf("%d",&n)!=EOF ;)
	{
		for(int i=1; i<=n; i++)
			scanf("%d",&dat[i]);
		solve();
	}
	return 0;
}
