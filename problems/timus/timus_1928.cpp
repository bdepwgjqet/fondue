#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>

using namespace std;

enum {
    MAXN = 10010
};

typedef pair<int, int> pii;

int n, m, k;
pii f[MAXN][2];

pii dp(int x, int p)
{
    if (x == 0) return pii(0, 0);
    if (f[x][p].first != -1) return f[x][p];

    if (x - k < 0)
		f[x][p] = pii(m,0);

    for (int i = 1; i <= k&&i<=x; i++) {
        pii r = dp(x - i, p ^ 1);
        if (r.second + i > f[x][p].first) {
            f[x][p] = pii(r.second + i, r.first);
        } else if (r.second + i == f[x][p].first && r.first < f[x][p].second) {
            f[x][p] = pii(r.second + i, r.first);
        }
    }

    return f[x][p];
}

int main()
{
    while (~scanf("%d%d%d", &n, &m, &k)) {
        memset(f, 0xff, sizeof f);
        pii r = dp(n, 0);
        printf("%d %d\n", r.first, r.second);
    }

    return 0;
}
