#include <cstdio>
#include <cstring>
#include <algorithm>
#define inf 0x3ffffffffffffLL
#define N 111
using namespace std;

char s[N];
int dp[N];

int cmp(int i,int j,int u,int v)
{
	for(; i<j&&s[i]==0; i++);
	for(; u<v&&s[u]==0; u++);
	if(j-i<v-u)
		return 1;
	else if(j-i>v-u)
		return 0;
	for(int k=0; k<=j-i; k++)
	{
		if(s[i+k]<s[u+k])
			return 1;
		else if(s[i+k]>s[u+k])
			return 0;
	}
	return 0;
}

int main()
{
	int l;
	while(scanf("%s",s)+1)
	{
		l=strlen(s);
		if(l==1&&s[0]=='0')
			break;
		for(int i=0; i<l; i++)
			s[i]-='0';
		dp[0]=0;
		for(int i=1; i<l; i++)
		{
			dp[i]=0;
			for(int k=i-1; k>=0; k--)
			{
				if(cmp(dp[k],k,k+1,i))
				{
					dp[i]=k+1;
					break;
				}
			}
		}
		int x=dp[l-1];
		dp[x]=l-1;
		for(int i=x-1; i>=0; i--)
		{
			if(s[i]==0)
			{
				dp[i]=dp[i+1];
				continue;
			}
			for(int j=x; j>=0; j--)
			{
				if(cmp(i,j-1,j,dp[j]))
				{
					dp[i]=j-1;
					break;
				}
			}
		}
		int nx=dp[0]+1;
		printf("%d",s[0]);
		for(int i=1; i<l; i++)
		{
			if(nx==i)
			{
				printf(",%d",s[i]);
				nx=dp[i]+1;
			}
			else
				printf("%d",s[i]);
		}
		puts("");
	}
	return 0;
}
