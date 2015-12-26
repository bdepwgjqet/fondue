#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1000;

int n;
int d[N];
int vis[N];
int id[N];
int deep[N];
long long ans;
vector<int> rp;

void dfs(int now) {
    vis[now] = 1;
    int nx = d[now];
    if (id[nx] > 0) {
        return;
    }
    if (vis[nx] > 0) {
        int l = 1;
        for (int i=nx; i!=now; i=d[i]) {
            l = l + 1;
            id[i] = rp.size()+1;
        }
        id[now] = rp.size()+1;
        rp.push_back(l);
        return;
    }
    dfs(nx);
}

int dfs1(int now) {
    if(id[now] > 0) {
        return 0;
    }
    if(deep[now] > 0) {
        return deep[now];
    }
    deep[now] = dfs1(d[now])+1;
    return deep[now];
}

long long gcd(long long a,long long b) {
    if(b > 0) {
        return gcd(b,a%b);
    }
    return a;
}

long long cal(long long a,long long b) {
    return a*b/gcd(a,b);
}

int main() {
    while(scanf("%d",&n)+1) {
        for (int i=1; i<=n; i++) {
            scanf("%d",&d[i]);
        }
        ans = 1;
        rp.clear();
        memset(deep,0,sizeof(deep));
        memset(id,0,sizeof(id));
        for (int i=1; i<=n; i++) {
            memset(vis,0,sizeof(vis));
            dfs(i);
        }
        for (int i=1; i<=n; i++) {
            dfs1(i);
        }
        int mx = 0;
        for (int i=1; i<=n; i++) {
            mx =max(mx,deep[i]);
        }
        for (int i=0; i<rp.size(); i++) {
            ans = cal(ans,rp[i]);
        }
        if (mx > ans) {
            ans = ((mx-1)/ans + 1)*ans;
        }
        printf("%lld\n",ans);
    }
    return 0;
}

