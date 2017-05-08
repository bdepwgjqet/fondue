#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110;
const int inf = 100000000;
int n,k;
int w[N][N];
int dp[N][N][N];
int sum[N][N];

int gao(int now, int pmx, int kl) {
    if (dp[now][pmx][kl] != -1) {
        return dp[now][pmx][kl];
    }
    if (now == n) {
        if (kl == 0) {
            return dp[now][pmx][kl] = 0;
        } else {
            return dp[now][pmx][kl] = -inf;
        }
    }

    if (kl == 0) {
        if (pmx > 1) {
            return dp[now][pmx][kl] = -inf;
        }
        return dp[now][pmx][kl] = 0;
    }
    int mxres = -inf;
    for (int i=max(pmx-1, 0); i<=n-now && i<=kl; i++) {
        mxres = max(mxres, gao(now+1, i, kl-i) + sum[now][i]);
    }
    if (mxres < -1) {
        mxres = -inf;
    }
    return dp[now][pmx][kl] = mxres;
}

int main() {
    while(scanf("%d%d", &n, &k) + 1) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<=i; j++) {
                int x = 0;
                scanf("%d", &x);
                w[i][j] = x;
            }

        }
        memset(sum,0,sizeof(sum));
        for (int i=0; i<n; i++) {
            for (int j=1; j<=n-i; j++) {
                sum[i][j] = sum[i][j-1] + w[n-j][i];
            }
        }
        memset(dp, -1, sizeof(dp));
        printf("%d\n", gao(0, 0, k));
    }
    return 0;
}
