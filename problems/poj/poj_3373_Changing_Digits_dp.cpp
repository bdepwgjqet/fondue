#include <cstdio>
#include <cstring>
#define MAXN 110
#define X 10011

int dp[MAXN][6][X],num[MAXN],M,len,ret[MAXN],min,rr[MAXN];
char s[MAXN];

void init(int l)
{
	int i;
	num[0]=l;
	for(i=0; i<l; i++)
		num[i+1]=s[i]-'0';
}

void dfs(int now,int cnt,int _mod)
{
	int i,t,add;
	if(cnt>=min)
		return ;
	if(dp[now][cnt][_mod]>=0)
		return ;	 
	dp[now][cnt][_mod]=1;
	if(now==len)
	{
		if(_mod!=0)	
			return ;
		else	
		{
			if(min>cnt)	
			{
				min=cnt;
				for(i=1; i<=len; i++)
					rr[i]=ret[i];
			}
			return ;
		}
	}

	if(now==0)	i=1;
	else	i=0;
	for(; i<=9; i++)
	{
		if(i==num[now+1])	add=0;
		else	add=1;
		t=_mod;
		t*=10,t+=i,t%=M;
		ret[now+1]=i;
		dfs(now+1,cnt+add,t);
	}
}

int main()
{
	int l,i;
	while(scanf("%s%d",&s,&M)!=EOF)
	{
		memset(dp,-1,sizeof(dp));
		len=strlen(s);
		init(len);
		min=6;
		dfs(0,0,0);
		for(i=1; i<=len; i++)
			printf("%d",rr[i]);
		puts("");
	}
	return 0;
}
