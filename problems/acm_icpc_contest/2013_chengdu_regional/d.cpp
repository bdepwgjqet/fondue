#include <cstdio>
#include <vector>

using namespace std;

const int N = 111;

int n,m,B,K,R,ttl;
int mat[7][N];
int dp[N][6][5][221];


struct edge {
	int to,ti,co;
	edge(){}
	edge(int to,int ti,int co):to(to),ti(ti),co(co){}
};

vector<edge> gr[N];

int dfs(int now,int k,int b,int t) {
	if(dp[now][k][b][t]>=-1)
		return dp[now][k][b][t];
	int ret=-1,tmp;

	if(now==0) {
		if(k==0 && b==0 && t>=0) {
			ret=max(ret,R);
		}
	}

	if(t>=1 && now!=n-1 && now!=0) {
		ret=max(ret,dfs(now,(k-1+K)%K,b,t-1));
		if(b+1<=B) {
			tmp=dfs(now,(k-1+K)%K,b+1,t-1);
			if(tmp>=0) {
				ret=max(ret,tmp+mat[k][now]);
			}
		}
		if(b>=1) {
			tmp=dfs(now,(k-1+K)%K,b-1,t-1);
			ret=max(ret,tmp-mat[k][now]);
		}
	}
	for(int i=0; i<gr[now].size(); i++) {
		int to=gr[now][i].to;
		int ti=gr[now][i].ti;
		int co=gr[now][i].co;
		if(to==n-1) continue;
		if(t-ti<0) continue;
		ret=max(ret,dfs(to,k,b,t-ti)-co);
		if(b>=1 && now!=n-1 && now!=0) {
			ret=max(ret,dfs(to,k,b-1,t-ti)-co-mat[k][now]);
		}
		if(b+1<=B && now!=n-1 && now!=0) {
			tmp=dfs(to,k,b+1,t-ti);
			if(tmp>=0) {
				ret=max(ret,tmp-co+mat[k][now]);
			}
		}
	}
	if(ret<0) ret=-1;
	return dp[now][k][b][t]=ret;
}

int main() {
	int T;
	scanf("%d",&T);
	for(int ca=1; ca<=T; ca++) {
		printf("Case #%d: ",ca);
		scanf("%d%d%d%d%d%d",&n,&m,&B,&K,&R,&ttl);
		for(int i=0; i<K; i++) {
			for(int j=0; j<n; j++)
				scanf("%d",&mat[i][j]);
		}
		for(int i=0; i<n; i++)
			gr[i].clear();
		for(int i=0; i<m; i++) {
			int x,y,u,v;
			scanf("%d%d%d%d",&x,&y,&u,&v);
			gr[y-1].push_back(edge(x-1,u,v));
		}
		for(int i=0; i<n; i++)
			for(int j=0; j<=K; j++)
				for(int u=0; u<=B; u++)
					for(int v=0; v<=ttl; v++)
						dp[i][j][u][v]=-2;
		int ret=dfs(n-1,0,0,ttl);
		if(ret<0)
			puts("Forever Alone");
		else
			printf("%d\n",ret);
	}
	return 0;
}
