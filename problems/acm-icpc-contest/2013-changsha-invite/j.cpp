#include <cstdio>
#include <vector>

using namespace std;
typedef long long LL;

const int inf = 1000000001;

int tag;
vector<int> vec;

LL pow(LL a,LL b) {
	LL ret=1;
	for(; b;) {
		if(a>=inf) return inf;
		if(b&1) {
			ret=ret*a;
			if(ret>=inf)
				return inf;
		}
		b>>=1;
		a=a*a;
	}
	return ret;
}

int dfs(int c,int a,int b,int l,int r,int k) {
	if(c==1) {
		if(l>r) return 0;
		int now=max(min(b,r)-max(a,l)+1,0);
		if(now>=k) {
			tag=1;
			vec.push_back(max(a,l)+k-1);
		}
		return now;
	}
	int ret=0;
	LL up=min(1LL*b,r/pow(a,c-1));
	LL down=max(1LL*a,l/pow(b,c-1));
	for(int i=down; i<=up&&(!tag); i++) {
		ret=ret+dfs(c-1,i,b,(l+i-1)/i,r/i,k-ret);
		if(tag) {
			vec.push_back(i);
		}
	}
	return ret;
}

int main() {
	int a,b,l,r,k,ca=1,T;
	scanf("%d",&T);
	for(int ca=1; ca<=T; ca++) {
		scanf("%d%d%d%d%d",&a,&b,&l,&r,&k);
		printf("Case #%d: ",ca);
		tag=0;
		vec.clear();
		for(int i=1; i<=30&&(!tag); i++) {
			int now=dfs(i,a,b,l,r,k);
			k-=now;
		}
		if(tag) {
			int ans=1;
			for(int i=0; i<vec.size(); i++)
				ans*=vec[i];
			printf("%d\n",ans);
			printf("%d",vec[vec.size()-1]);
			for(int i=vec.size()-2; i>=0; i--)
				printf(" %d",vec[i]);
			puts("");
		}
		else {
			puts("-1");
		}
	}
	return 0;
}
