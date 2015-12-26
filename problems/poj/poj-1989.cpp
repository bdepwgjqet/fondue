#include <cstdio>
#include <cstring>
#define N 10011

bool vis[N];

int main()
{
	int n,k,ret=0,c=0,x;
	scanf("%d%d",&n,&k);
	memset(vis,0,sizeof(vis));
	for(int i=0; i<n; i++)
	{
		scanf("%d",&x);
		if(vis[x])
			continue;
		else
		{
			vis[x]=1;
			c++;
			if(c==k)
			{
				ret++,c=0;
				for(int j=1; j<=k; j++)
					vis[j]=0;
			}
		}
	}
	printf("%d\n",ret+1);
	return 0;
}
