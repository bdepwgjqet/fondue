#include <cstdio>
#include <algorithm>
#include <vector>
#define inf 0x3fffffff
#define T 10010
#define N 1010

using namespace std;

int dp[T][128];
struct node{ int r,v; 
	node(int rr,int vv){ r=rr,v=vv; }
	node(){;}
};
vector<node> vec[T];

int main()
{
	int n,t,k,l,ts,mxt;
	scanf("%d",&ts);
	while(scanf("%d%d%d%d",&n,&t,&k,&l)+1,ts--)
	{
		mxt=0;
		for(int i=0; i<T; i++)
			vec[i].clear();
		for(int i=0; i<n; i++)
		{
			int l,r,v;
			scanf("%d%d%d",&l,&r,&v);
			mxt=max(mxt,r);
			vec[l].push_back(node(r,v));
		}
		fill(dp[0],dp[T-1],-inf);
		dp[0][0]=0;
		int ret=-inf;
		for(int i=0; i<T; i++)
		{
			for(int j=1; j<=t+l&&j<=i; j++)
			{
				dp[i][j]=max(dp[i][j],dp[i-1][j-1]-max(j-t,0)*max(j-t,0)+max(j-1-t,0)*max(j-1-t,0));
			}
			for(int j=t; j<=t+l; j++)
			{
				int sl=k+(j-t);
				if(i-sl>=0)
					dp[i][0]=max(dp[i][0],dp[i-sl][j]);
			}
			for(int j=0; j<=t+l; j++)
			{
				if(j>i)
					continue;
				if(dp[i][j]<=-inf) continue;
				for(int u=0; u<vec[i].size(); u++)
				{
					node now=vec[i][u];
					int d=now.r-i;
					if(d<=t+l-j)
					{
						dp[i+d][j+d]=max(dp[i+d][j+d],dp[i][j]+now.v+max(j-t,0)*max(j-t,0)-max(j+d-t,0)*max(j+d-t,0));
					}
				}
			}
		}
		for(int i=0; i<T-1; i++)
			for(int j=0; j<=i&&j<=t+l; j++)
				ret=max(ret,dp[i][j]);
		printf("%d\n",ret);
	}
	return 0;
}
