#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long LL;

const int X = 8;

vector<LL> vec[8][1<<8];

int st[10];

int count(LL x) {
	int ret=0;
	for(; x; x^=(x&(-x)))
		ret++;
	return ret;
}

inline int B(int i,int tag,int n) {
	if(tag) {
		if(i<0) return 0;
		if(i>=n) return 0;
	}
	return 1<<i; 
}

int press(int pre,int n) {
	int now=0;
	for(int i=0; i<n; i++) {
		if(pre&B(i,0,n)) {
			now^=B(i-1,1,n);
			now^=B(i+1,1,n);
			now^=B(i,1,n);
		}
	}
	return now;
}

void init() {
	for(int n=1; n<=8; n++) {
		LL step=0;
		int pre,now;
		for(int i=0; i<B(n,0,n); i++)
			vec[n-1][i].clear();
		for(int i=0; i<B(n,0,n); i++) {
			step=i;
			pre=press(i,n);
			now=i;
			for(int i=1; i<n; i++) {
				int tmp=now^press(pre,n);
				step=(step<<X)|pre;
				now=pre;
				pre=tmp;
			}
			vec[n-1][pre].push_back(step);
		}
	}
}

void solve(int n) {
	LL step=0;
	for(int i=1; i<n; i++) {
		step=(step<<X)|st[i-1];
		st[i]=st[i]^press(st[i-1],n);
		st[i+1]^=st[i-1];
	}
	int ret=1000;
	for(int i=0; i<vec[n-1][st[n-1]].size(); i++) {
		ret=min(ret,count(vec[n-1][st[n-1]][i]^step));
	}
	if(ret>=1000) {
		puts("-1");
	}
	else {
		printf("%d\n",ret);
	}
}

int main() {
	init();
	int T;
	scanf("%d",&T);
	for(int ca=1; ca<=T; ca++) {
		int n;
		scanf("%d",&n);
		for(int i=0; i<n; i++)
			scanf("%d",&st[i]);
		solve(n);
	}
	return 0;
}
