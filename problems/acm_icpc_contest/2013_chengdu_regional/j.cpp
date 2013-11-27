#include <cstdio>
#include <iostream>

using namespace std;
typedef long long LL;

LL p,m;

LL gcd(LL a,LL b) {
	return b?gcd(b,a%b):a;
}

LL f(LL a,LL b) {
	if(a<0||b<0) return 0;
	if(a+b<p) return 0;
	LL ret=(a/m)*(b/m)*m;
	LL ma=a%m,mb=b%m;
	ret+=(ma+1)*(b/m)+(mb+1)*(a/m);
	if(ma>p) {
		ret+=min(p+1,mb+1);
		LL tmp=(p+m-ma)%m;
		if(tmp<=mb)
			ret+=mb-tmp+1;
	}
	else {
		LL tmp=(p+m-ma)%m;
		if(tmp<=mb)
			ret+=min(p-tmp+1,mb-tmp+1);
	}
	return ret;
}

int main() {
	LL a,b,c,d;
	int T;
	scanf("%d",&T);
	for(int ca=1; ca<=T; ca++) {
		printf("Case #%d: ",ca);
		cin>>a>>b>>c>>d>>m>>p;
		LL ret=f(b,d)-f(b,c-1)-f(a-1,d)+f(a-1,c-1);
		LL fen=(1LL*b-a+1)*(1LL*d-c+1);
		LL g=gcd(ret,fen);
		cout<<ret/g<<"/"<<fen/g<<endl;
	}
}
