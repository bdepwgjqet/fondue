#include <cstdio>
#include <cstring>
#define N 10011

int dat[N],vis[N];

int main()
{
	int n,s,l,r;
	while(scanf("%d",&n)!=EOF)
	{
		memset(vis,0,sizeof(vis));
		s=0;
		for(int i=1; i<=n; i++)
		{
			scanf("%d",&dat[i]);
			s=(s+dat[i])%n;
			if(vis[s]>0)
				l=vis[s]+1,r=i;
			vis[s]=i;
		}
		if(vis[0]>0)
		{
			printf("%d\n",vis[0]);
			for(int i=1; i<=vis[0]; i++)
				printf("%d\n",dat[i]);
		}
		else
		{
			printf("%d\n",r-l+1);
			for(int i=l; i<=r; i++)
				printf("%d\n",dat[i]);
		}
	}
	return 0;
}
