#include <cstdio>
#include <algorithm>
#include <cstring>
#define N 211
using namespace std;

int dp[401][201],l;
char s1[N],s2[N],s[N<<1];

int dfs(int i,int j)
{
	if(dp[i][j]>=0)
		return dp[i][j];
	if(j==l)
		return dp[i][j]=1;
	int ret=0;
	if(s[i]==s1[j])
		ret=max(ret,dfs(i+1,j+1));
	if(s[i]==s2[i-j])
		ret=max(ret,dfs(i+1,j));
	return dp[i][j]=ret;
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int ca=1; ca<=n; ca++)
	{
		scanf("%s%s%s",s1,s2,s);
		l=strlen(s);
		memset(dp,-1,sizeof(dp));
		printf("Data set %d: ",ca);
		if(dfs(0,0))
			puts("yes");
		else
			puts("no");
	}
	return 0;
}
