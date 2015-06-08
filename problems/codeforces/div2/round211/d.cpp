#include <cstdio>
#include <iostream>
#include <algorithm>

const int N = 100111;
typedef long long LL;
using namespace std;

int b[N],p[N],ttl;
int n,m,use;

int ok(int k) {
	if(k>m) return 0;
	int tmp=ttl;
	use=0;
	for(int i=0; i<k; i++) {
		if(b[n-1-i]>=p[k-i-1]) {
			continue;
		}
		else {
			if(b[n-1-i]+tmp>=p[k-i-1]) {
				tmp-=p[k-i-1]-b[n-1-i];
				use+=p[k-i-1]-b[n-1-i];
			}
			else
				return 0;
		}
	}
	return 1;
}

int main() {
	while(scanf("%d%d%d",&n,&m,&ttl)+1) {
		int l=1,r=n;
		for(int i=0; i<n; i++) {
			scanf("%d",&b[i]);
		}
		for(int i=0; i<m; i++) {
			scanf("%d",&p[i]);
		}
		sort(b,b+n);
		sort(p,p+m);
		for(; l<=r;) {
			int mid=(l+r)>>1;
			if(ok(mid))
				l=mid+1;
			else
				r=mid-1;
		}
		ok(r);
		LL ret=0,r2=0;
		for(int i=0; i<r; i++) {
			ret+=p[i];
		}
		if(ret>=ttl)
			cout<<r<<" "<<ret-ttl<<endl;
		else
			cout<<r<<" "<<0<<endl;
	}
}
