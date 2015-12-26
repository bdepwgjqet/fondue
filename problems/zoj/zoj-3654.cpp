#include <cstdio>
typedef long long LL;

int main()
{
	LL x,y;
	while(scanf("%lld",&x)+1)
	{
		char sig;
		for(;;)
		{
			sig=getchar();
			if(sig=='\n')
				break;
			else if(sig=='-')
			{
				scanf("%lld",&y);
				x-=y;
			}
			else
			{
				scanf("%lld",&y);
				x+=y;
			}
		}
		LL u,v;
		scanf("%lld%lld",&u,&v);
		if(u==9)
			puts("A");
		else if(v==9)
			puts("B");
		else if(x==u)
			puts("B");
		else
			puts("A");
	}
}
