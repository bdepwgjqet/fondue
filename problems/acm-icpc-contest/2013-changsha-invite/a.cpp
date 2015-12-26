#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;
typedef long long LL;

int MOD;

LL gmod(LL x) {
	return ((x%MOD)+MOD)%MOD;
}

struct node {
	LL a,b,c,d;
	node(){}
	node(LL a,LL b,LL c,LL d):a(a),b(b),c(c),d(d){}
	node operator*(node x) {
		return node(gmod(a*x.a+b*x.c),gmod(a*x.b+b*x.d),gmod(c*x.a+d*x.c),gmod(c*x.b+d*x.d));
	}
};

int f(int n,int a,int b) {
	node x=node(gmod(2*a),gmod(b-1LL*a*a),1,0);
	node ret=node(1,0,0,1);
	int k=n-1;
	for(; k;) {
		if(k&1)
			ret=ret*x;
		x=x*x;
		k>>=1;
	}
	return gmod(2LL*a*ret.a+ret.b*2LL);
}

int main() {
	int a,b,n;
	while(scanf("%d%d%d%d",&a,&b,&n,&MOD)+1) {
		cout<<f(n,a,b)<<endl;
	}
	return 0;
}
