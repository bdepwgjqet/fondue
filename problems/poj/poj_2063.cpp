#include <cstdio>
#include <algorithm>
#define N 1000001
#define inf 0x3fffffff
using namespace std;

int dp[N];
struct node{ int v,x; }no[300];

int main()
{
	int t,val,y,n;
	int ret=0;
	scanf("%d",&t);
	for(; t--;)
	{
		for(int i=0; i<N; i++)
			dp[i]=0;
		scanf("%d%d",&val,&y);
		ret=val;
		val/=1000;
		scanf("%d",&n);
		for(int i=0; i<n; i++)
		{
			scanf("%d%d",&no[i].v,&no[i].x);
			no[i].v/=1000;
		}
		int now=val,pre=-1,id=0,nid,nnow;
		for(int i=0; i<y; i++)
		{
			for(int j=0; j<n; j++)
			{
				for(int k=pre+1; k<=now; k++)
				{
					if(k-no[j].v<0)
						continue;
					dp[k]=max(dp[k],dp[k-no[j].v]+no[j].x);
				}
			}
			nnow=ret+dp[id];
			nid=id;
			for(int j=pre+1; j<=now; j++)
			{
				if(nnow<ret+dp[j])
					nnow=ret+dp[j],nid=j;
			}
			id=nid;
			ret=nnow;
			pre=now,now=nnow/1000;
		}
		printf("%d\n",ret);
	}
}
