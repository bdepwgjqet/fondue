#include <cstdio>
#include <cstring>
#define N 50

int cnt[6][N],ret[11];

void dfs(int n,int i,int s)
{
	if(i==n)
	{
		cnt[n][s]++;
		return;
	}
	for(int u=0; u<10; u++)
		dfs(n,i+1,s+u);
}

int main()
{
	int n,tmp,fac;
	memset(cnt,0,sizeof(cnt));
	for(int i=1; i<=5; i++)
		dfs(i,0,0);
	ret[1]=10;
	for(int i=2; i<=10; i++)
	{
		tmp=i/2;
		if(i&1)
			fac=10;
		else
			fac=1;
		for(int j=0; j<N; j++)
			ret[i]+=cnt[tmp][j]*cnt[tmp][j]*fac;
	}
	while(scanf("%d",&n)!=EOF)
	{
		printf("%d\n",ret[n]);
	}
	return 0;
}
