#include <cstdio>
#include <algorithm>
#define N 500

using namespace std;
double dat[N];

int cmp(double a,double b){ return a<b; }

int main()
{
	int n,ts;
	scanf("%d",&ts);
	for(; ts--;)
	{
		scanf("%d",&n);
		for(int i=0; i<n; i++)
			scanf("%lf",&dat[i]);
		sort(dat,dat+n,cmp);
		double ret;
		if(n&1)
			ret=dat[n/2];
		else
			ret=(dat[n/2]+dat[n/2-1])/2;
		printf("%.3lf\n",ret);
	}
	return 0;
}
