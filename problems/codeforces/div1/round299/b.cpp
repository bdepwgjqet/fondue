#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1000011; 
const long long mod = 1000000007;

int n, m;
int f[N];
int can[N];
char s[N];

int gao(long long a,long long b) {
    long long ans = 1;
    for (; b > 0;) {
        if (b & 1) {
            ans = ans * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return int(ans);
}

void gen() {
    int l = strlen(s);
    f[0] = 0;
    for (int i = 0; i < l; i++) {
        int now = f[i];
        for(; now && s[i] != s[now]; now = f[now]);
        if (i > 0 && s[i] == s[now]) {
            f[i+1] = now+1;
        } else {
            f[i+1] = 0;
        }
    }
    memset(can,0,sizeof(can));
    for (int now = l; now; now = f[now]) {
        can[l-now] = 1;
    }
}

int main () {

    while (scanf("%d%d",&n,&m) + 1) {
        scanf("%s",s);
        gen();
        int ans = 0;
        int pre = 0;
        int l = strlen(s);
        int flag = 1;
        for (int i = 0; i < m; i++) {
            int x;
            scanf("%d",&x);
            if (pre == 0 || x - pre >= l) {
                if (pre > 0) {
                    ans = ans + l;
                }
            } else {
                if (can[x-pre] > 0) {
                    ans = ans + x - pre;
                } else {
                    flag = 0;
                }
            }
            pre = x;
        }
        if (pre > 0) {
            ans = ans + min(l,n-pre+1);
        }
        if (flag > 0) {
            printf("%d\n",gao(26,n-ans));
        } else {
            puts("0");
        }
    }
    return 0;
}
