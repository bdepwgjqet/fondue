#include <cstdio>
#include <cstring>
#define X 70

int dp[110][X][X],m,n,list[X],top,sum[X],mat[110];
char map[110][14];

inline int B(int i){ return 1<<i; }
inline int max(int x,int y){ return x>y?x:y; }

int sec(int x,int &cnt)
{
	int b=-3,now=0;
	for(cnt=0; x; now++,x>>=1)
		if(x&1)
		{
			if(now-b<=2)	return 0;
			b=now;
			cnt++;
		}
	return 1;
}

void init()
{
	int i,N=1<<m,cnt;
	for(top=i=0; i<N; i++)
		if(sec(i,cnt))
		{
			sum[top]=cnt;
			list[top++]=i;
		}
}

int calc2(char s[])
{
	int ret=0,i;
	for(i=0; i<m; i++)
	{
		ret<<=1;
		if(s[i]=='H')
			ret++;
	}
	return ret;
}

int solve()
{
	int i,fir,sec,now,ret;
	for(i=0; i<top; i++)
	{
		if(list[i]&mat[0])	continue;
		dp[0][0][i]=sum[i];
	}
	for(i=1; i<n; i++)
	for(now=0; now<top; now++)
	{
		if(list[now]&mat[i])	continue;
		for(fir=0; fir<top; fir++)
		{
			if(list[now]&list[fir])	continue;
			for(sec=0; sec<top; sec++)
			{
				if(list[now]&list[sec])	continue;
				if(list[fir]&list[sec])	continue;
				if(dp[i-1][fir][sec]==-1)	continue;
				dp[i][sec][now]=max(dp[i][sec][now],dp[i-1][fir][sec]+sum[now]);
			}
			if(i<=1)	break;
		}
	}
	for(ret=0,fir=0; fir<top; fir++)
		for(sec=0; sec<top; sec++)
			ret=max(ret,dp[n-1][fir][sec]);
	return ret;
}

int main()
{
	int i,ret;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		memset(dp,-1,sizeof(dp));
		for(i=0; i<n; i++)
		{
			scanf("%s",map[i]);
			mat[i]=calc2(map[i]);
		}
		init();
		/*
		for(i=0; i<top; i++)
			printf("%d %d\n",list[i],sum[i]);
		puts("");
		*/
		ret=solve();
		printf("%d\n",ret);
	}
	return 0;
}

