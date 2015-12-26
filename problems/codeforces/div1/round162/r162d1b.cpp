#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 100011

using namespace std;

int dp[N],p[N],pl[N],top;

void init()
{
	top=0;
	for(int i=0; i<N; i++)
		p[i]=i;
	for(int i=2; i<N; i++)
	{
		if(p[i]==i)
			pl[top++]=i;
		for(int j=0; j<top&&i*pl[j]<N; j++)
		{
			p[i*pl[j]]=pl[j];
			if(i%pl[j]==0)
				break;
		}
	}
}

void gao(int x)
{
	int ret=0,z=x;
	for(; x>1;)
	{
		int y=p[x];
		ret=max(ret,dp[y]);
		for(; x%y==0; x/=y);
	}
	x=z;
	for(; x>1;)
	{
		int y=p[x];
		dp[y]=ret+1;
		for(; x%y==0; x/=y);
	}
}

int main()
{
	int n;
	memset(dp,0,sizeof(dp));
	dp[1]=1;
	init();
	scanf("%d",&n);
	for(int i=0; i<n; i++)
	{
		int x;
		scanf("%d",&x);
		gao(x);
	}
	int ret=0;
	for(int i=0; i<N; i++)
		ret=max(ret,dp[i]);
	printf("%d\n",ret);
	return 0;
}
