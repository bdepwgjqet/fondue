#include <cstdio>
#include <cmath>

int main()
{
	double n,m,l,d; int t,ca=1;
	double s,a,b,c,dd;
	double pi=acos(-1);
	scanf("%d",&t);
	while(t--)
	{
		printf("Case %d:\n",ca++);
		scanf("%lf%lf%lf%lf",&m,&n,&l,&d);
		s=m*n*l*l;
		a=(l-d)*(l-d)*m*n+(m+n)*d*(l-d)+d*d;
		dd=(n-1)*(m-1)*pi*d*d/4;
		c=(n-1)*(m-1)*d*d-dd;
		a/=s,c/=s,dd/=s;
		b=1-a-c-dd;
		printf("Probability of covering 1 tile  = %.4f%\n",a*100);
		printf("Probability of covering 2 tiles = %.4f%\n",b*100);
		printf("Probability of covering 3 tiles = %.4f%\n",c*100);
		printf("Probability of covering 4 tiles = %.4f%\n",dd*100);
		if(t>0)
			puts("");
	}
	return 0;
}
