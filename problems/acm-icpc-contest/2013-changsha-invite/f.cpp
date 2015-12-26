#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;
const int N = 70;
const LL inf = 0x7fffffffLL;

LL dp[N][N];
int cnt[N],n;

inline LL B(int i) {
	return 1LL<<i;
}

LL dfs(int id,int c) {
	if(dp[id][c]>=0)
		return dp[id][c];
	if(id==n) {
		return dp[id][c]=cnt[n-c]*B(c);
	}
	LL ret=inf;
	if(c<16)
		ret=min(ret,dfs(id+1,c+1));
	ret=min(ret,dfs(id+1,0)+B(c+1)*cnt[id-c]);
	return dp[id][c]=ret;
}

int main() {
	int T;
	scanf("%d",&T);
	for(int ca=1; ca<=T; ca++) {
		scanf("%d",&n);
		for(int i=0; i<n; i++)
			scanf("%d",&cnt[i]);
		memset(dp,-1,sizeof(dp));
		cout<<dfs(0,0)<<endl;
	}
	return 0;
}
