#include <cstdio>
#include <cstring>

int a[3],dp[333][333];

int main()
{
	int n,tag;
	scanf("%d",&n);
	for(int i=0; i<n; i++)
	{
		scanf("%d",&a[i]);
		tag^=a[i];
	}
	if(n==2)
	{
		memset(dp,0,sizeof(dp));
		for(int i=0; i<300; i++)
			for(int j=0; j<300; j++)
				for(int k=1; k<300; k++)
				{
					if(i>=k&&dp[i-k][j]==0)
						dp[i][j]=1;
					if(j>=k&&dp[i][j-k]==0)
						dp[i][j]=1;
					if(i>=k&&j>=k&&dp[i-k][j-k]==0)
						dp[i][j]=1;
				}
		tag=dp[a[0]][a[1]];
	}
	printf("%s\n",tag?"BitLGM":"BitAryo");
	return 0;
}
