#include <cstdio>
#define N 100101

int ans[N];

int main()
{
	int n;
	while(scanf("%d",&n)+1)
	{
		if((n%4==1)||(n%4==0))
		{
			int m=0,l=1,r=n;
			for(; l<r;)
			{
				ans[l]=l+1;
				ans[l+1]=n-m;
				ans[r]=n-m-1;
				ans[r-1]=m+1;
				l+=2,r-=2;
				m+=2;
			}
			if(l==r)
				ans[l]=l;
			for(int i=1; i<=n; i++)
				printf("%d ",ans[i]);
			puts("");
		}
		else
			puts("-1");
	}
	return 0;
}
