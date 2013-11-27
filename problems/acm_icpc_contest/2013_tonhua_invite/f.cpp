#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;
const int N = 60;

struct node {
	int a,b,k;
}li[N];

vector<double> vec;

int in_range(double x) {
	return 0<x && x<100;
}

double f(double x,int i) {
	return li[i].k*(x-li[i].a)*(x-li[i].a)+li[i].b;
}

void get_solve(int a,int b,int c) {
	if(a==0) {
		if(b==0) return;
		double x=-1.0*c/b;
		if(in_range(x))
			vec.push_back(x);
		return ;
	}
	int delta=b*b-4*a*c;
	if(delta<0) return;
	if(delta==0) {
		double x=-1.0*b/(2.0*a);
		if(in_range(x));
		vec.push_back(x);
		return ;
	}
	double x=(-1.0*b+sqrt(delta))/(2.0*a);
	if(in_range(x))
		vec.push_back(x);
	x=(-1.0*b-sqrt(delta))/(2.0*a);
	if(in_range(x))
		vec.push_back(x);
}

double ff(double x) {
	return 0.5*x*sqrt(1+x*x)+0.5*log(x+sqrt(1+x*x));
}

double integration(double l,double r) {
	return ff(r)-ff(l);
}

int main() {
	int T;
	scanf("%d",&T);
	for(int ca=1; ca<=T; ca++) {
		int n;
		vec.clear();
		vec.push_back(0);
		vec.push_back(100);
		scanf("%d",&n);
		li[0].a=0;
		li[0].b=100;
		li[0].k=0;
		for(int i=1; i<=n; i++) {
			scanf("%d%d%d",&li[i].k,&li[i].a,&li[i].b);
		}
		for(int i=0; i<=n; i++) {
			for(int j=i+1; j<=n; j++) {
				get_solve(li[i].k-li[j].k,2*(li[j].k*li[j].a-li[i].k*li[i].a),li[i].k*li[i].a*li[i].a-li[j].k*li[j].a*li[j].a+li[i].b-li[j].b);
			}
		}
		sort(vec.begin(),vec.end());
		double ret=0;
		for(int i=0; i<vec.size()-1; i++) {
			double mid=(vec[i]+vec[i+1])*0.5;
			int nowi=0;
			for(int j=1; j<=n; j++) {
				if(f(mid,j)<f(mid,nowi))
					nowi=j;
			}
			if(li[nowi].k==0) {
				ret+=vec[i+1]-vec[i];
			}
			else {
				ret+=1.0/(2*li[nowi].k)*integration(2*li[nowi].k*(vec[i]-li[nowi].a),2*li[nowi].k*(vec[i+1]-li[nowi].a));
			}
		}
		printf("%.2lf\n",ret);
	}
	return 0;
}
