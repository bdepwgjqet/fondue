#include <cstdio>
#define N 100101

int p[N];

int main()
{
	int s,t,n;
	scanf("%d%d%d",&n,&s,&t);
	for(int i=1; i<=n; i++)
		scanf("%d",&p[i]);
	int nw=s;
	if(s==t) 
		puts("0");
	else
	{
		int ret=1,nw=p[s];
		for(; nw!=t; nw=p[nw],ret++)
		{
			if(nw==s)
			{
				puts("-1");
				return 0;
			}
		}
		printf("%d\n",ret);
	}
	return 0;
}
