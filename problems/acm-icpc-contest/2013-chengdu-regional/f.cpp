#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 100111;

int f[N];

struct edge {
	int f,t,c;
}e[N];

struct ufind {
	int p[N];
	void init(int n) {
		for(int i=0; i<n; i++)
			p[i]=i;
	}
	int fa(int x) {
		int y=x,tmp;
		for(; p[x]!=x; x=p[x]);
		for(; p[tmp=y]!=y; y=p[y],p[tmp]=x);
		return x;
	}
	int isf(int x,int y) {
		return fa(x)==fa(y);
	}
	void setf(int x,int y) {
		p[fa(y)]=fa(x);
	}
}uf;

int cmp1(edge a,edge b) {
	return a.c>b.c;
}

int cmp2(edge a,edge b) {
	return a.c<b.c;
}

int main() {
	f[0]=1,f[1]=1;
	for(int i=2; f[i-1]<N; i++) {
		f[i]=f[i-1]+f[i-2];
	}
	int T;
	scanf("%d",&T);
	for(int ca=1; ca<=T; ca++) {
		printf("Case #%d: ",ca);
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=0; i<m; i++) {
			scanf("%d%d%d",&e[i].f,&e[i].t,&e[i].c);
			e[i].f--,e[i].t--;
		}
		sort(e,e+m,cmp1);
		uf.init(n);
		int L=0,R=0;
		for(int i=0; i<m; i++) {
			if(uf.isf(e[i].f,e[i].t)) {
				continue;
			}
			uf.setf(e[i].f,e[i].t);
			if(e[i].c)
				R++;
		}
		sort(e,e+m,cmp2);
		uf.init(n);
		int ok=0;
		for(int i=0; i<m; i++) {
			if(uf.isf(e[i].f,e[i].t)) {
				continue;
			}
			uf.setf(e[i].f,e[i].t);
			ok++;
			if(e[i].c)
				L++;
		}
		int ret=0;
		for(int i=1; f[i]<=R; i++) {
			if(f[i]>=L) {
				ret=1;
				break;
			}
		}
		if(ret&&(ok==n-1))
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}
