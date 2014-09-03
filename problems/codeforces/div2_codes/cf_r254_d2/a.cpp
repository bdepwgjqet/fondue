#include <cstdio>

char s[1001][1001],r[1001][1001];

int main() {
	int n,m;
	while(scanf("%d%d",&n,&m)+1) {
		for(int i=0; i<n; i++) {
			scanf("%s",s[i]);
		}
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				if(s[i][j]=='-') {
					r[i][j]='-';
				} else {
					if((i+j)&1) {
						r[i][j]='B';
					} else {
						r[i][j]='W';
					}
				}
			}
		}
		for(int i=0; i<n; i++,puts("")) {
			for(int j=0; j<m; j++) {
				printf("%c",r[i][j]);
			}
		}
	}
	return 0;
}
