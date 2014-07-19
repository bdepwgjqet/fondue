#include <cstdio>
#include <algorithm>
#define inf 0x3fffffff
using namespace std;

struct node{ int i,c,p; }no[6];
struct barg{ int n,p; node b[6]; }bg[100];
int n,m,dp[7777];
int id[1001],six[10];

int get(int j,int i)
{
	int n=bg[i].n,del=0;
	for(int k=0; k<n; k++)
		del+=bg[i].b[k].c*six[id[bg[i].b[k].i]];
	return j-del;
}

int cal(int x)
{
	int ret=0;
	for(int i=0; i<n; i++)
		ret+=no[i].p*(x%6),x/=6;
	return ret;
}

int main()
{
	six[0]=1;
	for(int i=1; i<10; i++)
		six[i]=six[i-1]*6;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0; i<n; i++)
		{
			scanf("%d%d%d",&no[i].i,&no[i].c,&no[i].p);
			id[no[i].i]=i;
		}
		scanf("%d",&m);
		for(int i=0; i<m; i++)
		{
			scanf("%d",&bg[i].n);
			for(int j=0; j<bg[i].n; j++)

				scanf("%d%d",&bg[i].b[j].i,&bg[i].b[j].c);
			scanf("%d",&bg[i].p);
		}
		for(int i=0; i<six[n]; i++)
		{
			dp[i]=cal(i);
//			printf("%d %d\n",i,dp[i]);
		}
		dp[0]=0;
		for(int i=0; i<m; i++)
		{
			for(int j=0; j<six[n]; j++)
			{
				int pre=get(j,i);
				if(pre<0)
					continue;
				dp[j]=min(dp[j],dp[pre]+bg[i].p);
			}
		}
		int ans=0;
		for(int i=0; i<n; i++)
			ans+=six[i]*no[i].c;
		printf("%d\n",dp[ans]);
	}
	return 0;
}
