#include <cstdio>
#include <cmath>
#include <algorithm>
#define N 10011
using namespace std;

double dp[N];
const double fac=(1+sqrt(5.0))/2;
int c[N],ti[N];

int get(int x)
{
	return int(fac*x);
}

int main()
{
	int n,f,mx;
	while(scanf("%d%d",&n,&f)!=EOF)
	{
		mx=f;
		for(int i=0; i<n; i++)
		{
			scanf("%d",&c[i]);
			ti[i]=get(c[i]*c[i]);
			mx=max(mx,c[i]);
		}
		mx++;
		for(int i=mx; i>=f; i--)
		{
			dp[i]=0;
			for(int j=0; j<n; j++)
			{
				if(i>c[j])
					dp[i]+=ti[j];
				else
					dp[i]+=(1+dp[min(i+c[j],mx)]);
			}
			dp[i]/=n;
		}
		printf("%.3lf\n",dp[f]);
	}
	return 0;
}
