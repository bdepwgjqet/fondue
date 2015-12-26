#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 100005;
struct node
{
	int first, last, sum, len;
	node()
	{
	}
	node(int _first, int _last, int _sum, int _len)
	{
		first = _first;
		last = _last;
		sum = _sum;
		len = _len;
	}
} seg[4 * MAX];
int f[MAX], n;
node merge(node a, node b)
{
	node ans;
	ans.sum = a.sum + b.sum - f[a.last] - f[b.first] + f[a.last + b.first];
	ans.len = a.len + b.len;
	ans.first = a.first;
	if (a.first == a.len)
		ans.first += b.first;
	ans.last = b.last;
	if (b.last == b.len)
		ans.last += a.last;
	return ans;
}
void build(int v = 1, int s = 0, int e = n)
{
	seg[v].first = seg[v].last = seg[v].sum = 0;
	seg[v].len = e - s;
	if (e - s < 2)
		return;
	int mid = (s + e) / 2;
	build(2 * v, s, mid);
	build(2 * v + 1, mid, e);
}
void add(int p, int v = 1, int s = 0, int e = n)
{
	if (e - s < 2)
	{
		seg[v].first = seg[v].last = 1;
		seg[v].sum = f[1];
		return;
	}
	int mid = (s + e) / 2;
	if (p < mid)
		add(p, 2 * v, s, mid);
	else
		add(p, 2 * v + 1, mid, e);
	seg[v] = merge(seg[2 * v], seg[2 * v + 1]);
}
node get(int l, int r, int v = 1, int s = 0, int e = n)
{
	if (l <= s && e <= r)
		return seg[v];
	if (e <= l || r <= s)
		return node(0, 0, 0, 0);
	int mid = (s + e) / 2;
	return merge(get(l, r, 2 * v, s, mid), get(l, r, 2 * v + 1, mid, e));
}
int size[MAX], par[17][MAX], d[MAX], len[MAX], head[MAX], length[MAX], start[MAX];
vector<int> adj[MAX];
void pre(int p, int v)
{
	par[0][v] = p;
	for (int i = 1; i < 17; i++)
		par[i][v] = par[i - 1][par[i - 1][v]];
	size[v] = 1;
	for (int i = 0; i < adj[v].size(); i++)
	{
		int u = adj[v][i];
		if (u != p)
		{
			d[u] = d[v] + 1;
			pre(v, u);
			size[v] += size[u];
		}
	}
}
void hld(int p, int v)
{
	if (head[v] != v)
		length[head[v]]++;
	int mx = -1;
	for (int i = 0; i < adj[v].size(); i++)
	{
		int u = adj[v][i];
		if (u == p)
			continue;
		if (mx == -1 || size[mx] < size[u])
			mx = u;
	}
	if (mx != -1)
		head[mx] = head[v];
	for (int i = 0; i < adj[v].size(); i++)
	{
		int u = adj[v][i];
		if (u != p)
			hld(v, u);
	}
}
int get_parent(int v, int k)
{
	for (int i = 0; i < 17; i++)
		if ((1 << i) & k)
			v = par[i][v];
	return v;
}
int lca(int u, int v)
{
	if (d[u] < d[v])
		swap(u, v);
	u = get_parent(u, d[u] - d[v]);
	if (u == v)
		return u;
	for (int i = 16; i >= 0; i--)
		if (par[i][u] != par[i][v])
		{
			u = par[i][u];
			v = par[i][v];
		}
	return par[0][v];
}
void active(int u, int v)
{
	if (d[u] < d[v])
		swap(u, v);
	if (head[u] != u)
		add(start[head[u]] + d[u] - d[head[u]] - 1);
	else
		len[u]++;
}
node get_path(int x, int y)
{
	node ans(0, 0, 0, 0);
	while (d[x] > d[y])
	{
		if (head[x] == x)
		{
			if (len[x])
				ans = merge(node(1, 1, f[1], 1), ans);
			else
				ans = merge(node(0, 0, 0, 1), ans);
			x = par[0][x];
		}
		else
		{
			int r = start[head[x]] + d[x] - d[head[x]];
			int l = start[head[x]];
			if (head[x] == head[y])
				l = start[head[y]] + d[y] - d[head[y]];
			ans = merge(get(l, r), ans);
			x = head[x];
		}
	}
	return ans;
}
vector<pair<int, pair<int, int> > > edges;
pair<int, pair<pair<int, int>, int> > qq[MAX];
int ans[MAX];
int main()
{
	ios::sync_with_stdio(false);
	for (int i = 0; i < MAX; i++)
		head[i] = i;
	int q;
	cin >> n >> q;
	build();
	for (int i = 1; i < n; i++)
		cin >> f[i];
	for (int i = 0; i < n - 1; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		u--;
		v--;
		edges.push_back(make_pair(w, make_pair(u, v)));
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	pre(0, 0);
	hld(0, 0);
	int cnt = 0;
	for (int i = 0; i < n; i++)
		if (head[i] == i)
		{
			start[i] = cnt;
			cnt += length[i];
		}
	for (int i = 0; i < q; i++)
	{
		cin >> qq[i].second.first.first >> qq[i].second.first.second >> qq[i].first;
		qq[i].second.second = i;
	}
	sort(edges.begin(), edges.end());
	reverse(edges.begin(), edges.end());
	sort(qq, qq + q);
	reverse(qq, qq + q);
	int ptr = 0;
	for (int i = 0; i < q; i++)
	{
		while (ptr < edges.size() && edges[ptr].first >= qq[i].first)
		{
			active(edges[ptr].second.first, edges[ptr].second.second);
			ptr++;
		}
		int u = qq[i].second.first.first;
		int v = qq[i].second.first.second;
		u--;
		v--;
		int p = lca(u, v);
		if (u == p)
			swap(v, u);
		node res;
		node x = get_path(v, p);
		node y = get_path(u, p);
		swap(x.first, x.last);
		res = merge(x, y);
		ans[qq[i].second.second] = res.sum;
	}
	for (int i = 0; i < q; i++)
		cout << ans[i] << '\n';
	return 0;
}
