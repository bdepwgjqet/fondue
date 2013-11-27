#include <cstdio>

int main()
{
	int n;
	while(scanf("%d",&n)+1)
	{
		int ret=(1+n)*n/2;
		if(ret&1)
			puts("grimy");
		else
			puts("black");
	}
	return 0;
}
