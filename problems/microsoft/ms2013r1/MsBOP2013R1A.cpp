#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int dp[20][12][12],n;

int gao(int id,int a,int b)
{
	if(dp[id][a][b]>=0) return dp[id][a][b];
	if(id==n) return dp[id][a][b]=0;
	if(a==0) {
		return dp[id][a][b]=max(-(n-id),-b);
	}
	int ret=-100;
	for(int i=1; i<=a; i++)
	{
		int xa,xb=100;
		xa=gao(id+1,a-i,b)+1;
		if(b-i-1>=0)
			xb=gao(id+1,a,b-i-1)-1;
		ret=max(ret,min(xa,xb));
	}
	return dp[id][a][b]=ret;
}

int main()
{
	int a,b,t;
	scanf("%d",&t);
	for(int ca=1; ca<=t; ca++)
	{
		printf("Case #%d: ",ca);
		scanf("%d%d%d",&n,&a,&b);
		memset(dp,-1,sizeof(dp));
		int x=gao(0,a,b);
		if(x>0)
			puts("1");
		else if(x==0)
			puts("0");
		else
			puts("-1");
	}
	return 0;
}
