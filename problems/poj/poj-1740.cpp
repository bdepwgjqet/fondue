#include <cstdio>
#include <cstring>
#define N 111

int vis[N];

int main()
{
	int n,ret,x;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			break;
		memset(vis,0,sizeof(vis));
		for(int i=0; i<n; i++)
		{
			scanf("%d",&x);
			vis[x]++;
		}
		ret=0;
		for(int i=0; i<N; i++)
			if(vis[i]&1)
				ret=1;
		printf("%d\n",ret);
	}
	return 0;
}
