#include <cstdio>
#include <algorithm>
#include <cmath>
#define inf 1e15
#define N 100100

using namespace std;

double a[N],b[N],sum[N];
double da[N],db[N];

int main()
{
	int n;
	double x,y;
	while(scanf("%d%lf%lf",&n,&x,&y)+1)
	{
		for(int i=1; i<=n; i++)
			scanf("%lf%lf",&a[i],&b[i]);
		if(n==0)
		{
			printf("%.2lf\n",x);
			continue;
		}
		da[n]=max(1.0,1.0/a[n]*b[n]);
		db[n]=b[n];
		for(int i=n-1; i>=1; i--)
		{
			da[i]=max(1.0/a[i]*db[i+1]+1.0/a[i]*b[i]*da[i+1],da[i+1]);
			db[i]=db[i+1]+b[i]*da[i+1];
		}
		printf("%.2lf\n",x*da[1]+y*db[1]);
	}
	return 0;
}
