#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

double geth(double a,double b,double c)
{
	double cosa=(b*b+c*c-a*a)/(2*b*c);
	return c*sqrt(1-cosa*cosa);
}

double gao(double a,double b,double c)
{
	double h=geth(a,b,c);
	double d1=sqrt(a*a-h*h);
	double ret=0;
	double s=b*h;
	if(d1>b*0.5)
		s*0.75;
	else
		return s-d1*h-(b*0.5-d1)*h;
}

int main()
{
	int T;
	scanf("%d",&T);
	for(int ca=1; ca<=T; ca++)
	{
		int l1,l2,l3,l4,l5;
		scanf("%d%d%d%d%d",&l1,&l2,&l3,&l4,&l5);
		double ret;
		ret=gao(l1,l2,l5);
		ret=min(ret,gao(l2,l1,l5));
		printf("%.4lf\n",ret);
	}
	return 0;
}
