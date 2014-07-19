#include <cstdio>
#include <algorithm>
#include <cstring>
#define N 1001000

using namespace std;

char s[N];
int f[N];
int flag[N];

int solve() {
	f[0]=-1;
	int l=strlen(s),p;
	for(int i=1; i<l; i++) {
		p=f[i-1];
		for(; p>=0&&s[p+1]!=s[i];) {
			p=f[p];
		}
		if(s[p+1]==s[i]) {
			f[i]=p+1;
		}
		else {
			f[i]=-1;
		}
	}
	/*
	for(int i=0; i<l; i++) {
		printf("%d ",f[i]);
	}
	puts("");
	*/
	memset(flag,0,sizeof(flag));
	p=l-1;
	for(; f[p]!=-1;) {
		flag[f[p]]=1;
		p=f[p];
	}
	int ret=0;
	for(int i=0; i<l; i++) {
		if(f[i]!=-1) {
			if(f[i]+f[i]<=i&&flag[f[i]]&&i+f[i]<l) {
				ret=max(ret,f[i]+1);
			}
		}
	}
	return ret;
}

int main() {
	int n;
	scanf("%d",&n);
	for(int i=0; i<n; i++) {
		scanf("%s",s);
		printf("%d\n",solve());
	}
	return 0;
}
