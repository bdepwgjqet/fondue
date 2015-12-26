#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 1001
using namespace std;

char s1[N],s2[N];
int dp[N][N];

int main()
{
	int ret;
	while(scanf("%s%s",s1,s2)!=EOF)
	{
		ret=0;
		memset(dp,0,sizeof(dp));
		for(int i=0; s1[i]; i++)
			for(int j=0; s2[j]; j++)
			{
				dp[i+1][j+1]=max(dp[i][j]+(s1[i]==s2[j]),max(dp[i+1][j],dp[i][j+1]));
				ret=max(dp[i+1][j+1],ret);
			}
		printf("%d\n",ret);
	}
	return 0;
}
