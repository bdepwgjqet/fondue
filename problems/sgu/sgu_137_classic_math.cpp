#include <cstdio>
#include <cstring>

int ret[1011];

int main()
{
	int n,k;
	while(scanf("%d%d",&n,&k)+1)
	{
		int x=k/n;
		memset(ret,0,sizeof(ret));
		int p;
		for(p=1; (k*p%n)!=n-1; p++);
		for(int i=p; i!=n-1; i=(i+p)%n) ret[i]=1,k--;
		ret[n-1]=1,k--;
		printf("%d",k/n+ret[0]);
		for(int i=1; i<n; i++)
			printf(" %d",k/n+ret[i]);
		puts("");
	}
	return 0;
}
