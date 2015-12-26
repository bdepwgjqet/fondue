#include <cstdio>
#include <cstring>
#define inf 100000000
#define MAXL 2002

char s[MAXL],ss[5];
int fee[30],dp[MAXL][MAXL];

inline int min(int a,int b){ return a<b?a:b; }

int dfs(int l,int r)
{
	int ret=inf;
	if(dp[l][r]>=0)	return dp[l][r];
	if(l>=r)	return dp[l][r]=0;
	if(s[l]==s[r])
		ret=dfs(l+1,r-1);
	else
	{
		ret=min(ret,dfs(l+1,r)+fee[s[l]]);
		ret=min(ret,dfs(l,r-1)+fee[s[r]]);
	}
	return dp[l][r]=ret;
}

int main()
{
	int l,m,a,b,ret,i;
	while(scanf("%d%d",&m,&l)!=EOF)
	{
		scanf("%s",s);
		for(i=0; i<l; i++)
			s[i]-='a';
		for(i=0; i<m; i++)
		{
			scanf("%s%d%d",ss,&a,&b);
			fee[ss[0]-'a']=min(a,b);
		}
		memset(dp,-1,sizeof(dp));
		ret=dfs(0,l-1);
		printf("%d\n",dp[0][l-1]);
	}
	return 0;
}
