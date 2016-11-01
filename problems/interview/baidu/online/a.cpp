#include<vector>

using namespace std;

void dfs(int now, int p,int app[],int mxl[], vector<int> tree[],int& mxapp) {
   // cout<<tree[0][0]<<endl;
	int fmx = 0, smx = 0;
    for(int i=0; i<tree[now].size(); i++) {
		int to = tree[now][i];
        if (to == p) {
            continue;
        }
        dfs(to, now,app,mxl,tree,mxapp);
        if (fmx <= mxl[to]) {
            fmx = mxl[to];
            smx = fmx;
        }
        else if (smx <mxl[to]) {
            smx = mxl[to];
        }
	}
	mxapp = max(mxapp, fmx + smx + app[now]);
	mxl[now] = fmx + app[now];
}

int collectApples(int N, int K, int* applesAtNodes, int** connectedNodes)        {
    int app[100011];
    int mxl[100011];
    vector<int> tree[100011];
    memset(app, 0, sizeof(app));
    memset(mxl, 0, sizeof(mxl));
    for (int i = 0; i<K; i++) {
        app[--applesAtNodes[i]] = 1;
    }
    for (int i = 0; i<N - 1; i++) {
	  int x, y;
	    //scanf("%d%d", &x, &y)
	    x=connectedNodes[i][0]-1, y=connectedNodes[i][1]-1;
	    tree[x].push_back(y);
	    tree[y].push_back(x);
    }
    int mxapp=0;
    dfs(0, -1,app,mxl,tree,mxapp);
    return mxapp;
}

int main() {
    return 0;
}
