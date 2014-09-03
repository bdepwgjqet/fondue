#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

vector<int> tr[55];
int vis[55];

int dfs(int now) {
	vis[now]=1;
	int ret=1;
	for(int i=0; i<tr[now].size(); i++) {
		int to=tr[now][i];
		if(vis[to]) {
			continue;
		}
		ret=ret+dfs(to);
	}
	return ret;
}

int main() {
	int n,m;
	while(scanf("%d%d",&n,&m)+1) {
		for(int i=0; i<n; i++) {
			tr[i].clear();
		}
		for(int i=0; i<m; i++) {
			int x,y;
			scanf("%d%d",&x,&y);
			tr[x-1].push_back(y-1);
			tr[y-1].push_back(x-1);
		}
		int ans=0;
		memset(vis,0,sizeof(vis));
		for(int i=0; i<n; i++) {
			if(!vis[i]) {
				ans=ans+(dfs(i)-1);
			}
		}
		cout<<(1LL<<ans)<<endl;
	}
	return 0;
}
