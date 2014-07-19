#include <cstdio>
#include <cstring>
#include <iostream>

#define MOD 1000000007
#define N 80011

using namespace std;
typedef long long LL;

int p[N],pl[N],mp[N],top;
int dp[N][2];

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
	memset(dp,0,sizeof(dp));
	for(int i=0; i<top; i++) {
		for(int j=0; j<=i&&pl[i]+pl[j]<N; j++) {
			dp[pl[i]+pl[j]][0]++;
		}
		for(int j=pl[i]; j<N; j++) {
			dp[j][1]=(dp[j][1]+dp[j-pl[i]][0])%MOD;
		}
	}
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
		/*
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
		*/
		ret=ret+dp[x][0]+dp[x][1];
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
