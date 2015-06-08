#include <cstdio>

int main()
{
	int n;
	while(scanf("%d",&n)+1)
	{
		int s=0;
		for(int i=0; i<n; i++)
		{
			int x;
			scanf("%d",&x);
			s+=x;
		}
		int ret=0;
		for(int i=1; i<=5; i++)
		{
			if((s+i)%(n+1)!=1)
				ret++;
		}
		printf("%d\n",ret);
	}
	return 0;
}
