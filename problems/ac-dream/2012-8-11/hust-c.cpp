#include <cstdio>
#include <algorithm>
#include <vector>
#define N 100011
using namespace std;

vector<int> mat[N];
int dp[N],dat[N];

int main()
{
	int m,n,x;
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		for(int i=0; i<N; i++)
			mat[i].clear();
		if(m==0&&n==0)
			break;
		for(int i=0; i<m; i++)
			for(int j=0; j<n; j++)
			{
				scanf("%d",&x);
				mat[i].push_back(x);
			}
		for(int i=0; i<m; i++)
		{

			for(int j=0; j<n; j++)
			{
				x=mat[i][j];
				if(j>=2)
					dp[j]=max(x+dp[j-2],dp[j-1]);
				else if(j==1)
					dp[j]=max(dp[0],x);
				else
					dp[j]=x;
			}
			dat[i]=dp[n-1];
		}
		for(int i=0; i<m; i++)
		{
			if(i>=2)
				dp[i]=max(dp[i-2]+dat[i],dp[i-1]);
			else if(i==1)
				dp[i]=max(dp[0],dat[i]);
			else
				dp[i]=dat[0];
		}
		printf("%d\n",dp[m-1]);
	}
	return 0;
}
