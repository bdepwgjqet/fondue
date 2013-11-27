#include <cstdio>

int c(int n)
{
	if(n<=1) return 0;
	return n*(n-1)/2;
}

int main()
{
	int n,tag,m;
	while(scanf("%d%d",&n,&m)+1)
	{
		tag=0;
		for(int i=0; i<n; i++)
		{
			int x;
			scanf("%d",&x);
			if(x==1)
				tag=1;
		}
		int ret=0;
		if(m<n/3)
			ret=0;
		else if(tag)
		{
			if(m==n/3)
				ret=c(n-m);
			else if(m==n/3+1)
				ret=c(n-1)-c(m-1);
			else
				ret=c(n-1);
		}
		else
		{
			if(m==n/3)
				ret=m*(n-m-1);
			else
				ret=c(n-1)-c(n-m-1);
		}
		printf("%d\n",ret);
	}
	return 0;
}
