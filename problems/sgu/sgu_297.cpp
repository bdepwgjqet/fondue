#include <cstdio>

int main()
{
	int s,n,m;
	while(scanf("%d%d",&n,&m)+1)
	{
		s=0;
		for(int i=0; i<m; i++)
		{
			int x;
			scanf("%d",&x);
			s+=x;
		}
		printf("%d\n",s%n);
	}
	return 0;
}
