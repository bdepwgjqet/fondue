#include <cstdio>
#include <cmath>

#define N 10110
#define eps 1e-9

struct node{ double x,y; }no[N],ret[N];

int main()
{
	int n;
	while(scanf("%d",&n)+1)
	{
		for(int i=0; i<n; i++)
		{
			scanf("%lf%lf",&no[i].x,&no[i].y);
			no[i].x*=2;
			no[i].y*=2;
		}
		double x=0,y=0;
		for(int i=0; i<n; i++)
		{
			if(i&1)
				x-=no[i].x,y-=no[i].y;
			else
				x+=no[i].x,y+=no[i].y;
		}
		if(n&1)
		{
			ret[0].x=x/2.0;
			ret[0].y=y/2.0;
		}
		else
		{
			if(fabs(x)<eps&&fabs(y)<eps)
				ret[0].x=1,ret[0].y=1;
			else
			{
				puts("NO");
				continue;
			}
		}
		for(int i=1; i<n; i++)
		{
			ret[i].x=no[i-1].x-ret[i-1].x;
			ret[i].y=no[i-1].y-ret[i-1].y;
		}
		puts("YES");
		for(int i=0; i<n; i++)
			printf("%.6f %.6f\n",ret[i].x,ret[i].y);
	}
	return 0;
}
