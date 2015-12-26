#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int inf = 10000000;
const int N = 110;
int n,m,ttl,st,ed;

int cost[N],sa[N],dis[N][N],dp[N][333],isto[N][333],visst;

int dfs(int now,int rest) {
	if(dp[now][rest]>=0)
		return dp[now][rest];
	if(now==n+1) {
		isto[now][rest]=1;
		return dp[now][rest]=0;
	}
	int ret=0,it=0;
	for(int i=0; i<n+2; i++) {
		if((sa[i]>sa[now]||i==n+1) && rest>=dis[now][i]+cost[i]) {
			int nextv=dfs(i,rest-dis[now][i]-cost[i]);
			if(isto[i][rest-dis[now][i]-cost[i]]) {
				it=1;
				ret=max(ret,nextv+sa[i]);
			}
		}
	}
	isto[now][rest]=it;
	return dp[now][rest]=ret;
}

int main() {
	int T;
	scanf("%d",&T);
	for(int ca=1; ca<=T; ca++) {
		printf("Case #%d:\n",ca);
		scanf("%d%d%d%d%d",&n,&m,&ttl,&st,&ed);
		for(int i=0; i<n; i++)
			scanf("%d",&cost[i]);
		cost[n]=cost[n+1]=0;
		for(int i=0; i<n; i++)
			scanf("%d",&sa[i]);
		sa[n]=sa[n+1]=0;
		for(int i=0; i<n+2; i++) {
			for(int j=0; j<n+2; j++)
				dis[i][j]=inf;
			dis[i][i]=0;
		}
		for(int i=0; i<m; i++) {
			int u,v,l;
			scanf("%d%d%d",&u,&v,&l);
			dis[u][v]=dis[v][u]=min(dis[u][v],l);
		}
		dis[n][st]=dis[st][n]=0;
		dis[n+1][ed]=dis[ed][n+1]=0;
		for(int k=0; k<n+2; k++)
			for(int i=0; i<n+2; i++)
				for(int j=0; j<n+2; j++)
					dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
		memset(isto,0,sizeof(isto));
		memset(dp,-1,sizeof(dp));
		printf("%d\n",dfs(n,ttl));
	}
	return 0;
}
