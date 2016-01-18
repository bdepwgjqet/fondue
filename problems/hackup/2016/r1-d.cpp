#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>

using namespace std;

const int N = 1<<4;
int n;
int dp[1<<N][N];
int mat[N][N];
int apair[N][2];
int blen[1<<N];
vector<int> cc[N+1];

inline int B(int i) {
    return 1<<i;
}

int getl(int x) {
    int ret = 0;
    for (int i=0; i<N; i++) {
        if (x&B(i)) {
            ret++;
        }
    }
    return ret;
}

void gen(int st, int id, int l,int mx) {
    if (id==N) {
        if (2*l >= mx && 2*l <= N) {
            cc[2*l].push_back(st);
        }
        return;
    }
    gen(st|B(id),id+1,l+1,id+1);
    gen(st,id+1,l,mx);
}

void init() {
    for (int i=0; i<=N; i++) {
        cc[i].clear();
    }
    gen(0,0,0,0);
    for (int i=0; i<(1<<N); i++) {
        blen[i] = getl(i);
    }
}

int gao(int st, int c) {
    int ret = 0, now = 0;
    for (int i=0; i<n; i++) {
        if (st & B(i)) {
            if (c&B(now)) {
                ret |= B(i);
            }
            now = now + 1;
        }
    }
    return ret;
}

int dfs(int st, int id, int l) {
    if (l == 1) {
        return dp[st][id] = 1;
    }
    if (dp[st][id]>=0) {
        return dp[st][id];
    }
    for(int i=0; i<n; i++) {
        if (id != i && (B(i)&st) && mat[id][i]) {
            if (l <= 2) {
                return dp[st][id] = 1;
            }
            int left = l-2;
            int lst = st^B(id);
            lst = lst^B(i);
            for (int j=0; j<cc[left].size(); j++) {
                int a = gao(lst,cc[left][j])|B(id);
                int b = st ^ a;
                if (dfs(a,id,l>>1) && dfs(b,i,l>>1)) {
                    return dp[st][id] = 1;
                }
            }
        }
    }
    return dp[st][id] = 0;
}

int main() {
    init();
    int cs;
    scanf("%d",&cs);
    for (int cas = 0; cas < cs; cas++) {
        scanf("%d",&n);
        memset(dp,-1,sizeof(dp));
        memset(apair,0,sizeof(apair));
        for(int i=0; i<n; i++) {
            int e = 1;
            for (int j=0; j<n; j++) {
                scanf("%d",&mat[i][j]);
                if (mat[i][j] == 0 && i!=j) {
                    e = 0;
                }
            }
            if (e) {
                apair[i][1] = 1;
            } else {
                apair[i][1] = (n>>1) + 1;
            }
            dp[1<<i][i] = 1;
        }
        for (int i=0; i<B(n); i++) {
            if (blen[blen[i]] == 1) {
                for (int j=0; j<n; j++) {
                    if (B(j)&i) {
                        dfs(i,j,blen[i]);
                    }
                }
            }
        }
        for (int i=0; i<n; i++) {
            for (int j=0; j<(1<<n); j++) {
                if (dp[j][i] == 1) {
                    apair[i][0] = max(apair[i][0],blen[j]);
                }
            }
        }
        printf("Case #%d:\n",cas+1);
        for (int i=0; i<n; i++) {
            printf("%d %d\n",(n/2/apair[i][0])+1,apair[i][1]);
        }
    }
    return 0;
}
