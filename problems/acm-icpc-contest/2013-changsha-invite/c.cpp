#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long LL;
const int N = 1000010;

int a[N],clo[N];
LL sum[N];

int main() {
	int n;
	int T=0;
	while(scanf("%d",&n)+1) {
		T++;
		for(int i=1; i<=n; i++)
			scanf("%d",&a[i]);
		if(T>=40) continue;
		sum[0]=0;
		for(int i=1; i<=n; i++)
			sum[i]=sum[i-1]+a[i];
		int id=1;
		for(int i=1; i<=n; i++)
			if(sum[i-1]+i-1<=a[i])
				id=i;
		LL ttl=0;
		clo[id]=0;
		for(int j=id+1; j<=n; j++) {
			clo[j]=clo[j-1]+(a[j-1]-clo[j-1]<=0);
			ttl+=max(0,a[j]-clo[j]);
		}
		ttl+=sum[id-1]+id-1;
		if(ttl<a[id])
			puts("Bad Rescue");
		else if(ttl==a[id])
			printf("%d\n",id);
		else
			puts("Unknown");
	}
	return 0;
}
