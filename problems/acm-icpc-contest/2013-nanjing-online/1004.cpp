#include <cstdio>
#include <vector>
#include <algorithm>
#define N 1001

using namespace std;

vector<int> gr[N];
int mat[N][N];
int vis[N];
int len[N];
int ret;

void dfs(int now,int p,int cnt) {
	vis[now]=1;
	len[now]=cnt;
	for(int i=0; i<gr[now].size()&&ret; i++) {
		int to=gr[now][i];
		if(to==p) continue;
		if(vis[to]) {
			if(abs(len[now]-len[to]+1)&1) {
				ret=0;
				break;
			}
			continue;
		}
		dfs(to,now,cnt+1);
	}
}

int main() {
	int n;
	while(scanf("%d",&n)+1) {
		for(int i=0; i<n; i++) {
			gr[i].clear();
		}
		for(int i=0; i<n; i++) {
			vis[i]=0;
			len[i]=0;
			for(int j=0; j<n; j++) {
				mat[i][j]=0;
			}
		}
		for(int i=0; i<n; i++) {
			int x;
			while(scanf("%d",&x)+1) {
				if(x==0) break;
				mat[i][x-1]=1;
			}
		}
		for(int i=0; i<n; i++) {
			for(int j=i+1; j<n; j++) {
				if(mat[i][j]==0||mat[j][i]==0) {
					gr[i].push_back(j);
					gr[j].push_back(i);
				}
			}
		}
		ret=1;
		for(int i=0; i<n&&ret; i++) {
			if(!vis[i]) {
				dfs(i,-1,0);
			}
		}
		if(ret)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
