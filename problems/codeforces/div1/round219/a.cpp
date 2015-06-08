#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 601001;

int a[N];

int n;

int ok(int c) {
	if(c>n/2) return 0;
	for(int i=c-1; i>=0; i--) {
		if(a[i]+a[i]>a[n-1-(c-1-i)])
			return 0;
	}
	return 1;
}

int main() {
	while(scanf("%d",&n)+1) {
		for(int i=0; i<n; i++) {
			scanf("%d",&a[i]);
		}
		sort(a,a+n);
		int l=1,r=n;
		for(; l<=r;) {
			int mid=(l+r)>>1;
			if(ok(mid))
				l=mid+1;
			else
				r=mid-1;
		}
		printf("%d\n",n-r);
	}
	return 0;
}
