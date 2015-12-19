#include <cstdio>

const int X = 32;
const long long MOD = 1e9+7;

class matrix {
public:
    int sz;
    long long e[X][X];

    matrix(){}
    matrix(int sz):sz(sz){
        for (int i=0; i<sz; i++) {
            for (int j=0; j<sz; j++) {
                e[i][j] = 0;
                if (i==j) {
                    e[i][j] = 1;
                }
            }
        }
    }

    matrix operator*(const matrix &o) {
        matrix ans(sz);
        for (int i=0; i<sz; i++) {
            for (int j=0; j<sz; j++) {
                long long val = 0;
                for (int k=0; k<sz; k++) {
                    val = (val + e[i][k]*o.e[k][j]%MOD)%MOD;
                }
                ans.e[i][j] = val;
            }
        }
        return ans;
    }
};

matrix A[X][X<<1],P[X],S[X];
int bit[X<<1];

long long n;
int k;

void init_matrix(int m) {
    for (int u=0; u<k; u++) {
        A[u][0].sz = k+1;
        S[u].sz = k+1;
        P[u].sz = k+1;
        for(int i=0; i<=k; i++) {
            for(int j=0; j<=k; j++) {
                if (i == j) {
                    A[u][0].e[i][j] = 1;
                } else {
                    if (u == j) {
                        A[u][0].e[i][j] = 1;
                    } else {
                        A[u][0].e[i][j] = 0;
                    }
                }
                if (j == k && i<k) {
                    A[u][0].e[i][j] = 0;
                }
            }
        }
    }

    for (int i=0; i<=k; i++) {
        for (int j=0; j<=k; j++) {
            S[0].e[i][j] = 0;
            P[k].e[i][j] = 0;
            if (i == j) {
                S[0].e[i][j] = 1;
                P[k].e[i][j] = 1;
            }
        }
    }

    for (int u=1; u<k; u++) {
        S[u] = S[u-1]*A[u-1][0];
    }
    for (int u=k-1; u>=0; u--) {
        P[u] = A[u][0]*P[u+1];
    }

    for (int v=1; v<m; v++) {
        for (int u=0; u<k; u++) {
            //A[u][v] = A[u][v-1]*A[(u+1)%k][v-1]..*A[(u+k-1)%k][v-1];
            A[u][v] = P[u]*S[u];
        }
        for (int u=1; u<k; u++) {
            S[u] = S[u-1]*A[u-1][v];
        }
        for (int u=k-1; u>=0; u--) {
            P[u] = A[u][v]*P[u+1];
        }
    }
}

void show(int x) {
    for (int i=0; i<=k; i++,puts("")) {
        for (int j=0; j<=k; j++) {
            printf("%lld ",A[x][0].e[i][j]);
        }
    }
}

int main() {
    while(scanf("%lld%d",&n,&k)+1) {
        int m = 0;
        long long e = n;
        for(; e; e/=k) {
            bit[m++] = e%k;
        }
        init_matrix(m);
        matrix ans(k+1);
        int off = 0;
        for (int i=m-1; i>=0; i--) {
            int x = bit[i];
            for (int j=0; j<x; j++) {
                ans = ans*A[(j+off)%k][i];
            }
            off = (off+x)%k;
        }
        long long res = 0;
        for (int i=0; i<ans.sz; i++) {
            res = (res+ans.e[ans.sz-1][i])%MOD;
        }
        printf("%lld\n",res);
    }
    return 0;
}
