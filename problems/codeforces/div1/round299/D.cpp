#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
#include <queue>
#include <functional>
#include <set>
#include <algorithm>

using namespace std;

const int N = 2022;
const long long inf = 1LL<<60;

int n,m,s,t;
int p[N];
vector<pair<int,int> > edge[N];
vector<pair<long long,int> > sortor;
long long mins[N],mint[N];
long long dp[N][N][2];
long long sum[N][N], cnt[N][N];
int si[N],ti[N];

void gao(int st, long long mv[], int mi[]) {
    for (int i=0; i < N; i++) {
        mv[i] = inf;
    }
    mv[st] = 0;
    set<pair<long long,int> > q;
    q.insert(make_pair(mv[st],st));
    while (q.size() > 0) {
        long long nowl = q.begin()->first;
        int nowp = q.begin()->second;
        q.erase(q.begin());
        for (int i=0; i<edge[nowp].size(); i++) {
            int to = edge[nowp][i].first;
            int len = edge[nowp][i].second;
            if (len + nowl < mv[to]) {
                mv[to] = len + nowl;
                q.insert(make_pair(mv[to],to));
            }
        }
    }
    sortor.clear();
    for (int i=0; i<n; i++) {
        sortor.push_back(make_pair(mv[i],i));
    }
    sort(sortor.begin(),sortor.end());
    for (int i=0; i<n ;i++) {
        mi[sortor[i].second] = i+1;
    }
}

int main() {
    while (scanf("%d%d%d%d",&n,&m,&s,&t)+1) {
        s--;
        t--;
        for (int i = 0; i < n; i++) {
            scanf("%d",&p[i]);
            edge[i].clear();
        }
        for (int i = 0; i < m; i++) {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            x--;
            y--;
            edge[x].push_back(make_pair(y,z));
            edge[y].push_back(make_pair(x,z));
        }
        gao(s,mins,si);
        gao(t,mint,ti);
        memset(dp,0,sizeof(dp));
        memset(sum,0,sizeof(sum));
        memset(cnt,0,sizeof(cnt));
        for (int i=0; i<n; i++) {
            cnt[si[i]][ti[i]]++;
            sum[si[i]][ti[i]] += p[i];
        }
        for (int i=1; i<=n+1; i++) {
            for (int j=1; j<=n+1; j++) {
                cnt[i][j] += cnt[i-1][j] + cnt[i][j-1] - cnt[i-1][j-1];
                sum[i][j] += sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
            }
        }
        for (int i=n; i>=0; i--) {
            for (int j=n; j>=0; j--) {
                if (cnt[i+1][n]-cnt[i][n] == cnt[i+1][j]-cnt[i][j]) {
                    dp[i][j][0] = dp[i+1][j][0];
                } else {
                    dp[i][j][0] = max(dp[i+1][j][0],dp[i+1][j][1])+sum[i+1][n]-sum[i][n]-(sum[i+1][j]-sum[i][j]);
                }

                if (cnt[n][j+1]-cnt[n][j] == cnt[i][j+1] - cnt[i][j]) {
                    dp[i][j][1] = dp[i][j+1][1];
                } else {
                    dp[i][j][1] = min(dp[i][j+1][1],dp[i][j+1][0])-(sum[n][j+1] - sum[n][j]) + (sum[i][j+1]-sum[i][j]);
                }
            }
        }
        if(dp[0][0][0] > 0) {
            puts("Break a heart");
        } else if(dp[0][0][0] == 0) {
            puts("Flowers");
        } else {
            puts("Cry");
        }
    }
    return 0;
}
