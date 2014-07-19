#include <cstdio>

int n;

char s[30][30];

int gao(int x,int y) {
	int ux=n,uy=n;
	for(int i=x; i<n; i++)
		if(s[i][y]!='#') {
			ux=i;
			break;
		}
	for(int i=y; i<n; i++) {
		if(s[x][i]!='#') {
			uy=i;
			break;
		}
	}
	if(ux-x!=uy-y)
		return 0;
	for(int i=x; i<ux; i++)
		for(int j=y; j<uy; j++) {
			if(s[i][j]!='#')
				return 0;
			s[i][j]='.';
		}
	return 1;
}

int ok() {
	int tag=1,exi=0;
	for(int i=0; i<n&&tag; i++) {
		for(int j=0; j<n&&tag; j++) {
			if(s[i][j]=='#') {
				if(gao(i,j))
					tag=0,exi=1;
				else
					return 0;
			}
		}
	}
	if(exi==0) return 0;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(s[i][j]=='#')
				return 0;
		}
	}
	return 1;
}

int main() {
	int T;
	scanf("%d",&T);
	for(int ca=1; ca<=T; ca++) {
		scanf("%d",&n);
		printf("Case #%d: ",ca);
		for(int i=0; i<n; i++)
			scanf("%s",s[i]);
		if(ok())
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
