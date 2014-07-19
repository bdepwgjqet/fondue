#include <cstdio>

void draw(int x) {
	if(x>=5) {
		x-=5;
		printf("-O|");
	}
	else {
		printf("O-|");
	}
	for(int i=0; i<x; i++)
		printf("O");
	printf("-");
	for(int i=0; i<4-x; i++)
		printf("O");
	puts("");
}

int main() {
	int n;
	while(scanf("%d",&n)+1) {
		if(n==0)
			puts("O-|-OOOO");
		for(; n;) {
			int x=n%10;
			draw(x);
			n/=10;
		}
	}
	return 0;
}
