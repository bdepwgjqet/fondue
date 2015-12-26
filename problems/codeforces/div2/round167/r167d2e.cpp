#include <cstdio>
#include <cstring>
#include <vector>
#define N 300101

using namespace std;

vector<int> gr[N];
int ret[N];

void dfs(int x) {
	int cnt=0;
	for(int i=0; i<gr[x].size(); i++)
		if(ret[gr[x][i]]==ret[x])
			cnt++;
	if(cnt>=2) {
		ret[x]^=1;
		for(int i=0; i<gr[x].size(); i++)
			if(ret[gr[x][i]]==ret[x])
				dfs(gr[x][i]);
	}
}

int main() {
	int n,m;
	memset(ret,0,sizeof(ret));
	scanf("%d%d",&n,&m);
	for(int i=0; i<m; i++) {
		int x,y;
		scanf("%d%d",&x,&y);
		x--,y--;
		gr[x].push_back(y);
		gr[y].push_back(x);
	}
	for(int i=0; i<n; i++)
		dfs(i);
	for(int i=0; i<n; i++)
		printf("%d",ret[i]);
	puts("");
	return 0;
}
