#include <cstdio>
#define N 1001

int a[N];

int get(int x)
{
	int ret=0;
	for(; x; x/=10)
		if(x%10==4||x%10==7)
			ret++;
	return ret;
}

int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=0; i<n; i++)
		scanf("%d",&a[i]);
	int ret=0;
	for(int i=0; i<n; i++)
		if(get(a[i])<=k)
			ret++;
	printf("%d\n",ret);
	return 0;
}
