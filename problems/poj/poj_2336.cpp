#include <cstdio>
#include <algorithm>
#include <cstring>
#define inf 0x3ffffff
#define N 1440 
using namespace std;

int dp[N<<1][N],cnt[N],sum[N],mxt,mit,mic,n,ti,m;

void dfs(int t,int c,int num)
{
	int lf,nowt,nowc;
	if(t>=mxt)
	{
		lf=sum[mxt]-c;
		if(lf%n==0)
		{
			nowt=t+lf/n*2*ti-ti;
			nowc=num+lf/n;
		}
		else
		{
			nowt=t+lf/n*2*ti+ti;
			nowc=num+lf/n+1;
		}
		if(nowt<mit)
			mit=nowt,mic=nowc;
		else if(nowt==mit&&nowc<mic)
			mic=nowc;
		return;
	}
	if(dp[t][c]>=0)
		return ;
	dp[t][c]=1;
	if(sum[t]>c)
	{
		if(sum[t]-c>=n)
			dfs(t+2*ti,c+n,num+1);
		else
		{
			dfs(t+1,c,num);
			dfs(t+2*ti,sum[t],num+1);
		}
	}
	else
		dfs(t+1,c,num);
}

int main()
{
	int T,x;
	scanf("%d",&T);
	for(int ca=1; ca<=T; ca++)
	{
		scanf("%d%d%d",&n,&ti,&m);
		memset(cnt,0,sizeof(cnt));
		memset(sum,0,sizeof(sum));
		memset(dp,-1,sizeof(dp));
		mxt=0;
		for(int i=0; i<m; i++)
		{
			scanf("%d",&x);
			cnt[x]++;
			mxt=max(mxt,x);
		}
		sum[0]=cnt[0];
		for(int i=1; i<N; i++)
			sum[i]=cnt[i]+sum[i-1];
		mit=inf;
		mic=inf;
		dfs(0,0,0);
		printf("%d %d\n",mit,mic);
	}
	return 0;
}
