#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 23;
const int inf = 2000200;

int dp[N][N][N][N];
int a[N];
int b[N];
int n;

int dfs(int al,int ar,int bl,int br) {
	if(dp[al][ar][bl][br]>=0)
		return dp[al][ar][bl][br];
	int c=2*n-(ar-al+1+br-bl+1);
	if(c==2*n)
		return dp[al][ar][bl][br]=0;
	int ret;
	if(c&1)
		ret=inf;
	else
		ret=0;
	if(ar>=al) {
		if(c&1) { 
			ret=min(ret,dfs(al+1,ar,bl,br));
			ret=min(ret,dfs(al,ar-1,bl,br));
		}
		else { 
			ret=max(ret,dfs(al+1,ar,bl,br)+a[al]);
			ret=max(ret,dfs(al,ar-1,bl,br)+a[ar]);
		}
	}
	if(br>=bl) {
		if(c&1) { 
			ret=min(ret,dfs(al,ar,bl+1,br));
			ret=min(ret,dfs(al,ar,bl,br-1));
		}
		else { 
			ret=max(ret,dfs(al,ar,bl+1,br)+b[bl]);
			ret=max(ret,dfs(al,ar,bl,br-1)+b[br]);
		}
	}
	return dp[al][ar][bl][br]=ret;
}

int main() {
	int T;
	scanf("%d",&T);
	for(int ca=1; ca<=T; ca++) {
		scanf("%d",&n);
		if(n<=0) {
			puts("0");
			continue;
		}
		for(int i=1; i<=n; i++)
			scanf("%d",&a[i]);
		for(int i=1; i<=n; i++)
			scanf("%d",&b[i]);
		memset(dp,-1,sizeof(dp));
		printf("%d\n",dfs(1,n,1,n));
	}
	return 0;
}
