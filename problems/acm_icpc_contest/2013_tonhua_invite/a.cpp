#include <cstdio>

int main() {
	int t;
	scanf("%d",&t);
	for(int i=1; i<=t; i++) {
		double ret=0;
		for(int j=0; j<12; j++) {
			double x;
			scanf("%lf",&x);
			ret+=x;
		}
		int y=int(ret/12*100+0.5);
		printf("$%d",y/100);
		if(y%100>0) {
			printf(".");
			int x=y%100;
			if(x%10>0) {
				if(x/10==0)
					printf("0%d\n",x);
				else
					printf("%d\n",x);
			}
			else
				printf("%d\n",x/10);
		}
		else
			puts("");
	}
	return 0;
}
