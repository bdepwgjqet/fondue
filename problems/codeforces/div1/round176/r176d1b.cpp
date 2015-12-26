#include <cstdio>
#define N 2000101

int ans[N];
int n;

int main()
{
	while(scanf("%d",&n)+1)
	{
		for(int i=1; i<=n; i++)
			ans[i]=i;
		for(int i=2; i<=n; i++)
		{
			int d=n%i;
			if(d==0) d=i;
			ans[n+i-1]=ans[n+i-1-d];
			for(int j=n+i-1-d; j-i>=i-1; j-=i)
				ans[j]=ans[j-i];
		}
		for(int i=n; i<=n+n-1; i++)
			printf("%d ",ans[i]);
		puts("");
	}
	return 0;
}
