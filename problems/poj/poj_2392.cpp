#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 440
using namespace std;

struct node{ int h,c,a; }no[N];
int dp[42000];

int cmp(node a,node b){ return a.a<b.a; }

int main()
{
	int n,mx;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0; i<n; i++)
			scanf("%d%d%d",&no[i].h,&no[i].a,&no[i].c);
		sort(no,no+n,cmp);
		memset(dp,0,sizeof(dp));
		mx=0;
		dp[0]=1;
		for(int i=0; i<n; i++)
		{
			int now;
			for(int k=1; k-1<no[i].c; k<<=1) 
			{
				if(2*k-1<no[i].c)
					now=k*no[i].h;
				else
					now=(no[i].c-k+1)*no[i].h;
				for(int j=mx; j>=0; j--)
				{
					if(j+now>no[i].a)
						continue;
					if(dp[j])
					{
						dp[j+now]=1;
						mx=max(mx,j+now);
					}
				}
			}
		}
		printf("%d\n",mx);
	}
	return 0;
}
