#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN=555;

vector<int> tr[MAXN];
int vis[MAXN];
int deep[MAXN];
int mat[MAXN][MAXN];
int tag;

void dfs(int now,int p,int cnt) {
	vis[now]=1;
	deep[now]=cnt;
	for(int i=0; i<tr[now].size()&&tag; i++) {
		int to=tr[now][i];
		if(to==p) continue;
		if(vis[to]) {
			if(abs(deep[now]-deep[to]+1)&1) {
				tag=0;
				break;
			}
			continue;
		}
		dfs(to,now,cnt+1);
	}
}

void init(int n) {
	memset(deep,0,sizeof(deep));
	memset(vis,0,sizeof(vis));
	memset(mat,0,sizeof(mat));
	for(int i=0; i<n; i++) {
		tr[i].clear();
	}
	for(int i=0; i<n; i++) {
		for(int x; scanf("%d",&x)+1;) {
			if(x==0) break;
			mat[i][x-1]=1;
		}
	}
	for(int i=0; i<n; i++) {
		for(int j=i+1; j<n; j++) {
			if(mat[i][j]==0||mat[j][i]==0) {
				tr[i].push_back(j);
				tr[j].push_back(i);
			}
		}
	}
}

void solve(int n) {
	tag=1;
	for(int i=0; i<n&&tag; i++) {
		if(!vis[i]) {
			dfs(i,-1,0);
		}
	}
	if(tag) {
		cout<<"YES"<<endl;
	}
	else {
		cout<<"NO"<<endl;
	}
}

int main() {
	int n;
	while(scanf("%d",&n)+1) {
		init(n);
		solve(n);
	}
	return 0;
}
