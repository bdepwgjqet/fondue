#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

const int N = 100011;

int n,k;
int app[N];
int mxl[N];
int mxapp;
vector<int> tree[N];

void dfs(int now, int p) {
    int fmx=0, smx=0;
    for(int i=0; i<tree[now].size(); i++) {
        int to = tree[now][i];
        if(to == p) {
            continue;
        }
        dfs(to,now);
        if (fmx <= mxl[to]) {
            fmx = mxl[to];
            smx = fmx;
        } else if (smx <mxl[to]) {
            smx = mxl[to];
        }
    }
    mxapp = max(mxapp,fmx + smx + app[now]);
    mxl[now] = fmx + app[now];
}

int main () {
    while(scanf("%d%d",&n,&k)+1) {
        memset(app,0,sizeof(app));
        memset(mxl,0,sizeof(mxl));
        for (int i=0; i<N; i++) {
            tree[i].clear();
        }
        for (int i=0; i<k; i++) {
            int now;
            scanf("%d",&now);
            now--;
            app[now]=1;
        }
        for (int i=0; i<n-1; i++) {
            int x,y;
            scanf("%d%d",&x,&y);
            x--,y--;
            tree[x].push_back(y);
            tree[y].push_back(x);
        }
        mxapp = 0;
        dfs(0,-1);
        printf("%d\n",mxapp);
    }
    return 0;
}
