#include <cstdio>
#include <vector>
#define inf 0x3fffffff
#define N 16100

using namespace std;

vector<int> vec[N];
int dp[N];

void dfs(int now,int p)
{
	for(int i=0; i<vec[now].size(); i++)
	{
		int to=vec[now][i];
		if(to==p) continue;
		dfs(to,now);
		dp[now]=max(dp[now],dp[now]+dp[to]);
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0; i<n; i++)
		scanf("%d",&dp[i]);
	for(int i=0; i<n-1; i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		x--,y--;
		vec[x].push_back(y);
		vec[y].push_back(x);
	}
	dfs(0,-1);
	int ret=-inf;
	for(int i=0; i<n; i++)
		ret=max(ret,dp[i]);
	printf("%d\n",ret);
	return 0;
}
