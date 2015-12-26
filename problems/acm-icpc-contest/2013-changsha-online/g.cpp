#include <cstdio>
#include <iostream>

#define MOD 1000000007
#define N 100001

using namespace std;
typedef long long LL;

int p[N],pl[N],mp[N],top;

void init() {
	for(int i=0; i<N; i++) {
		p[i]=i;
	}
	top=0;
	for(int i=2; i<N; i++) {
		if(p[i]==i) {
			pl[top++]=i;
		}
		for(int j=0; j<top&&pl[j]*i<N; j++) {
			p[pl[j]*i]=pl[j];
			if(i%pl[j]==0) {
				break;
			}
		}
	}
	/*
	for(int i=0; i<10; i++) {
		printf("%d ",pl[i]);
	}
	puts("");
	printf("%d\n",top);
	*/
}

int get_f(int x) {
	if(x<=1) { 
		return 0;
	}
	int ret=0;
	for(;x>1;) {
		x/=p[x];
		ret++;
	}
	return ret;
}

int main() {
	init();
	int x;
	while(scanf("%d",&x)+1) {
		LL ret=0;
		if(p[x]==x) {
			ret++;
		}
		for(int i=0; i<top&&x-pl[i]>=pl[i]; i++) {
			if(p[x-pl[i]]==x-pl[i]) {
				ret++;
			}
		}
		for(int i=0; i<top&&x-pl[i]>=pl[i]; i++) {
			for(int j=i; j<top&&x-pl[i]-pl[j]>=pl[j]; j++) {
				if(p[x-pl[i]-pl[j]]==x-pl[i]-pl[j]) {
					ret++;
				}
			}
		}
		int c=get_f(x);
		if(c==3) {
			ret++;
		}
		if(c==2) {
			ret++;
		}
		for(int i=0; i<top&&x-pl[i]>=2; i++) {
			c=get_f(x-pl[i]);
			if(c==2) {
				ret++;
			}
		}
		ret=ret%MOD;
		cout<<ret<<endl;
	}
	return 0;
}
