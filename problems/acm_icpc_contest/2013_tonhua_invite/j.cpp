#include <cstdio>

const int MOD = 2011;

int f(int a,int b) {
	if(b<0) return 0;
	int ret=1;
	for(; b;) {
		if(b&1)
			ret=ret*a%MOD;
		b>>=1;
		a=a*a%MOD;
	}
	return ret;
}

int minus(int a,int b) {
	return ((a-b)%MOD+MOD)%MOD;
}

int main() {
	int n;
	while(scanf("%d",&n)+1) {
		if(n==0) break;
		printf("%d %d\n",(minus(f(6,n-1),1)*f(5,MOD-2)+1)%MOD,minus(f(6,n),1)*f(5,MOD-2)%MOD);
	}
	return 0;
}
