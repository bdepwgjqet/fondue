#include <cstdio>
#include <vector>
#include <algorithm>
#define N 1011

using namespace std;

int dp[N];
vector<int> vec;

void init()
{
	dp[1]=1;
	dp[2]=1;
	for(int i=3; i<N; i++)
	{
		dp[i]=N;
		for(int j=2; j<i; j++)
			dp[i]=min(dp[i],max(dp[j],dp[i-j])+1);
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	init();
	int n;
	while(scanf("%d",&n)+1)
	{
		int cnt=1;
		printf("%d\n",dp[n]);
		int d;
		for(d=2; d<n; d<<=1)
		{
			vec.clear();
			for(int i=1; i<=n; i+=d)
			{
				int l=i,r=i+d-1,m=(l+r)/2;
				for(int j=l; j<=m&&j<=n; j++)
					vec.push_back(j);
			}
			printf("%d",vec.size());
			for(int i=0; i<vec.size(); i++)
				printf(" %d",vec[i]);
			puts("");
			cnt++;
		}
		vec.clear();
		int l=1,r=l+d-1,m=(l+r)/2;
		for(int i=1; i<=m; i++)
			vec.push_back(i);
		printf("%d",vec.size());
		for(int i=0; i<vec.size(); i++)
			printf(" %d",vec[i]);
		puts("");
		if(cnt!=dp[n])
			for(;;);
	}
	return 0;
}
