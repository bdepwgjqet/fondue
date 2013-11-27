#include <cstdio>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1000;
const int MOD = 10;

struct Edge {
	int u, v, w;
	Edge() {}
	Edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
	bool operator < (const Edge &o) const {
		return w < o.w;
	}
};

struct Disjoint_Set {
	int fa[N];
	void init() { 
		for (int i = 0; i < N; i++) fa[i] = i;
	}
	int find(int x) {
		if (fa[x] == x) return x;
		return fa[x] = find(fa[x]);
	}
	int merge(int x, int y) {
		int fx = find(x), fy = find(y);
		if (fx == fy) return 0;
		fa[fx] = fy; return 1;
	}
}ds;

vector<Edge> vec;
vector<pair<int, int> > tree[N];

int main() {
	srand(time(NULL));
	int n = N, m = rand() % n + 1, d = rand() % n;
	printf("%d %d\n", n, MOD*5);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			int w = rand() % MOD + 1;
			vec.push_back(Edge(i, j, w));
		}
	}
	sort(vec.begin(), vec.end());
	ds.init();
	for (int i = 0; i < vec.size(); i++) {
		Edge e = vec[i];
		if (ds.merge(e.u, e.v)) {
			tree[e.u].push_back(make_pair(e.v, e.w));
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < tree[i].size(); j++) {
			pair<int, int> now = tree[i][j];
			printf("%d %d %d\n", i + 1, now.first + 1, now.second);
		}
	}
	return 0;
}

