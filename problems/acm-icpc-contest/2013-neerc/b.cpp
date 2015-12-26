#include <cstdio>

int main() {
	int n,k;
	while(scanf("%d%d",&n,&k)+1) {
		int ra=0,rb=0;
		for(int i=0; i<n; i++) {
			int x;
			scanf("%d",&x);
			if(x>=k)
				ra+=x-k;
			else
				rb+=k-x;
		}
		printf("%d %d\n",ra,rb);
	}
	return 0;
}
