#include <cstdio>

typedef long long LL;

int a[6],n,mod;

LL gmod(LL x,int MOD) {
	return (x%MOD+MOD)%MOD;
}

LL f(LL x,int MOD) {
	LL ret=0;
	for(int i=n; i>=0; i--) {
		LL now=1;
		for(int j=0; j<i; j++)
			now=gmod(now*x,MOD);
		ret=gmod(ret+gmod(now*a[i],MOD),MOD);
	}
	return ret;
}

int main() {
	int T;
	scanf("%d",&T);
	for(int ca=1; ca<=T; ca++) {
		printf("Case #%d: ",ca);
		scanf("%d",&n);
		for(int i=n; i>=0; i--)
			scanf("%d",&a[i]);
		scanf("%d",&mod);
		int tag=1;
		for(int i=0; i<mod&&tag; i++) {
			if(f(i,mod)==0) {
				for(int j=i; j<mod*mod&&tag; j+=mod) {
					if(f(j,mod*mod)==0) {
						printf("%d\n",j);
						tag=0;
					}
				}
			}
		}
		if(tag)
			puts("No solution!");
	}
	return 0;
}
