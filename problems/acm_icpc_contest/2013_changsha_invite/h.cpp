#include <cstdio>
int main() {
	int n,m;
	while(scanf("%d%d",&m,&n)+1) {
		int ret=0,k=0;
		for(int i=0; i<n; i+=2) {
			ret+=2*(m-k);
			if(i+1==n)
				ret-=m-k;
			k++;
		}
		printf("%d\n",ret);
	}
}
