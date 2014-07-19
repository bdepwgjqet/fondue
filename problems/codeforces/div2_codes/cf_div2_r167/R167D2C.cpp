#include <cstdio>
#include <iostream>
#include <algorithm>
#define N 100100

typedef long long LL;
using namespace std;

int a[N];

int main() {
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; i++) {
		scanf("%d",&a[i]);
	}
	int m;
	LL now=0;
	scanf("%d",&m);
	for(int i=1; i<=m; i++) {
		int w,h;
		scanf("%d%d",&w,&h);
		LL ans=max(1LL*a[w],now);
		cout<<ans<<endl;
		now=ans+h;
	}
	return 0;
}
