#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>

using namespace std;

const int N = 2010;

vector<int> adj[N];
int t[N], d[N];
int a, b, n;
int vis[N], link[N];

int check(int l, int r) {
	int now = t[r] - t[l];
	return now >= a || now <= b;
}

int dfs(int u) {
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (!vis[v]) {
			vis[v] = 1;
			if (link[v] == -1 || dfs(link[v])) {
				link[v] = u;
				link[u] = v;
				return 1;
			}
		}
	}
	return 0;
}

void init() {
	for (int i = 0; i < N; i++) {
		adj[i].clear();
	}
	memset(link, 0xff, sizeof link);
}

int main() {
	while (~scanf("%d%d", &a, &b)) {
		init();
		scanf("%d", &n);
		int c0=0;
		for (int i = 0; i < n; i++) {
			scanf("%d%d", t + i, d + i);
			if(d[i]==0)
				c0++;
		}
		for (int i = 0; i < n; i++) {
			if(d[i]==1) continue;
			for (int j = 0; j < n; j++) {
				if(d[j]==0) continue;
				if (!check(i, j)) continue;
				adj[i].push_back(j + n);
			}
		}
		int ret = 0;
		for (int i = 0; i < n; i++) {
			if(d[i]) continue;
			memset(vis, 0, sizeof vis);
			if (dfs(i)) ret++;
		}
		if (ret != c0) {
			puts("Liar");
		} else {
			puts("No reason");
			for (int i = 0; i < n; i++) {
				if (d[i]) continue;
				printf("%d %d\n", t[i], t[link[i] - n]);
			}
		}
	}
	return 0;
}
