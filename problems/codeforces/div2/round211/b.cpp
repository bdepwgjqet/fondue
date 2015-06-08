#include <cstdio>
const int N = 1000000;

int arr[N],sum[N];

int main() {
	int n,k;
	while(scanf("%d%d",&n,&k)+1) {
		for(int i=1; i<=n; i++) {
			scanf("%d",&arr[i]);
		}
		sum[1]=arr[1];
		sum[0]=0;
		for(int i=2; i<=n; i++)
			sum[i]=sum[i-1]+arr[i];
		int mi=sum[k],id=k;
		for(int i=k+1; i<=n; i++) {
			if(sum[i]-sum[i-k]<mi) {
				mi=sum[i]-sum[i-k];
				id=i;
			}
		}
		printf("%d\n",id-k+1);
	}
	return 0;
}
