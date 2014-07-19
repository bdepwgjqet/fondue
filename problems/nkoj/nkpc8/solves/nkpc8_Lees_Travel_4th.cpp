/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  03/10/2012 01:00:23 PM
 ***/

#include <cstring>
#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>
#define MAXN 1010
#define eps 1e-8
#define MAXM 1000010
#define MOD 1000000007

typedef long long LL;
using namespace std;

const double pi=acos(-1);

inline int L(int i){ return i<<1; }
//inline int R(int i){ return (i<<1)|1; }
inline double max(double a,double b){ return a<b?b:a; }
inline double min(double a,double b){ return a<b?a:b; }
inline double abs(double x){ return x<0?-x:x; }

double R,H,V,D[MAXN],NV,sita;
int n;

double cal(double h)
{
	double t=(H-h)/H*R;
	return 1.0/3*n*pi*(R*R*H-t*t*(H-h));
}

double first_f(double x,double d)
{
	double t=sqrt(1-d*d/(x*x));
	return 2*(1.0/3*x*x*x*acos(d/x)-1.0/6*d*(x*x*t+d*d*log(x*(t+1))));
}

double second_f(double x,double d)
{
	double t=sqrt(x*x-d*d);
	return d*(x*t-d*d*log(t+x));
}

double repeat(double h,int i)
{
	if(D[i]>=2*R)	return 0;
	double M=max(D[i]/2,(H-h)/H*R);
	double d=D[i]/2;
	double first=first_f(R,d)-first_f(M,d);
	double second=second_f(R,d)-second_f(M,d);
	return H/R*(first-second);
}

int too_low(double h)
{
	int i;
	NV=cal(h);
	for(i=0; i<n-1; i++)
		NV-=repeat(h,i);
	//printf("%lf====>\n",NV);
	return NV>V?0:1;
}

int main()
{
	int i;
	double l,r,m;
	while(scanf("%d",&n)!=EOF)
	{
		scanf("%lf%lf%lf",&R,&H,&V);
		for(i=0; i<n-1; i++)
			scanf("%lf",&D[i]);
		l=0,r=H;
		for(; r-l>=eps;)
		{
			m=(r+l)/2;
		//	printf("%lf=>\n",m);
			if(too_low(m))
				l=m;
			else
				r=m;
		}
		m=(l+r)/2;
		if((m>H-eps)&&too_low(m))
			puts("No way");
		else
			printf("%.3lf\n",m);
	}
	return 0;
}
