#include <cstdio>
#include <map>
#define N 501001

using namespace std;

int dp[N],dat[N];
map<int,int> mp;

int main()
{
	int n;
	while(scanf("%d",&n)+1)
	{
		mp.clear();
		dp[0]=0;
		for(int i=1; i<=n; i++)
		{
			scanf("%d",&dat[i]);
			dp[i]=max(dp[i-1],mp[dat[i]]);
			mp[dat[i]]=i;
		}
		int m;
		scanf("%d",&m);
		for(; m--;)
		{
			int l,r;
			scanf("%d%d",&l,&r);
			if(dp[r]>=l)
				printf("%d\n",dat[dp[r]]);
			else
				puts("OK");
		}
		puts("");
	}
	return 0;
}
