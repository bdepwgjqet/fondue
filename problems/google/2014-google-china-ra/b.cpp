#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

typedef unsigned long long ULL;
using namespace std;

vector<int> bit;
ULL rp,rq;

void cr_bit(ULL n) {
	for(; n;) {
		bit.push_back(n&1);
		n>>=1;
	}
	reverse(bit.begin(),bit.end());
}

void dfs(int id,ULL p,ULL q) {
	if(id==bit.size()) {
		rp=p,rq=q;
		return;
	}
	if(bit[id]==0) {
		dfs(id+1,p,p+q);
	}
	else {
		dfs(id+1,p+q,q);
	}
}

ULL go(ULL p,ULL q) {
	if(p==1&&q==1) {
		return 1;
	}
	if(p>q) {
		return 1+2*go(p-q,q);
	}
	else {
		return 2*go(p,q-p);
	}
}

int main() {
	int T;
	scanf("%d",&T);
	for(int ca=1; ca<=T; ca++) {
		printf("Case #%d: ",ca);
		int tag;
		scanf("%d",&tag);
		if(tag==1) {
			ULL n;
			cin>>n;
			bit.clear();
			cr_bit(n);
			dfs(1,1,1);
			cout<<rp<<" "<<rq<<endl;
		}
		else {
			ULL p,q;
			cin>>p>>q;
			cout<<go(p,q)<<endl;
		}
	}
	return 0;
}
