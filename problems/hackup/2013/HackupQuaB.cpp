#include <cstdio>
#include <cstring>
#define N 1001

char s[N];
int dp[101][101],len;

int isok(char x)
{
	if('a'<=x&&x<='z')
		return 1;
	return x==':'||x==' '||x==')'||x=='(';
}

int dfs(int l,int c)
{
	if(dp[l][c]>=0) return dp[l][c];
	if(l==len)
		return c==0;
	int ret=0;
	if(s[l]=='(')
	{
		if(l>0&&s[l-1]==':')
			ret+=dfs(l+1,c);
		ret+=dfs(l+1,c+1);
	}
	else if(s[l]==')')
	{
		if(l>0&&s[l-1]==':')
			ret+=dfs(l+1,c);
		if(c>0)
			ret+=dfs(l+1,c-1);
	}
	else
		ret+=dfs(l+1,c);
	return dp[l][c]=(ret>0);
}

int check(char s[])
{
	for(int i=0; s[i]; i++)
		if(!isok(s[i]))
			return 0;
	len=strlen(s);
	memset(dp,-1,sizeof(dp));
	if(dfs(0,0))
		return 1;
	return 0;
}

int main()
{
	int n;
	scanf("%d",&n);
	getchar();
	for(int i=1; i<=n; i++)
	{
		gets(s);
		printf("Case #%d: ",i);
		if(check(s))
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
