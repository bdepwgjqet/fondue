/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  08/06/2012 11:28:49 PM
 ***/

#include <cstring>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <sstream>
#include <cmath>
#include <functional>
#include <iostream>
#include <algorithm>
#define N 6010
#define M 1000010
#define S 1000100
#define eps 1e-8
#define inf 0x3fffffff
#define MOD 1000000007
#define PB push_back
#define MP make_pair
#define SZ(a) ((int)((a).size()))
#define ALL(a) (a).begin(),(a).end()
#define CLR(a,x) memset(a,x,sizeof(a))

typedef long long LL;
using namespace std;

double x[N],y[N],z[N];

int main()
{
	int n,m,k;
	double r1;
	while(scanf("%d",&n)!=EOF)
	{
		r1=-1e10;
		for(int i=0; i<n; i++)
		{
			scanf("%lf",&x[i]);
			r1=max(r1,x[i]);
		}
		scanf("%d",&m);
		for(int i=0; i<m; i++)
			scanf("%lf",&y[i]);
		scanf("%d",&k);
		for(int i=0; i<k; i++)
			scanf("%lf",&z[i]);
		double a,b;
		scanf("%lf%lf",&a,&b);
		double r2=-1e10,tmp;
		for(int i=0; i<m; i++)
			for(int j=0; j<k; j++)
			{
				tmp=(b*y[i]*r1*r1)/(a*z[j]+b*y[i]);
				if(tmp>=r1*r1)
					continue;
				r2=max(r2,sqrt(tmp));
			}
		printf("%.12lf\n",r2);
	}
	return 0;
}
