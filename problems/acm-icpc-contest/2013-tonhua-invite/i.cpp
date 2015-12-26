#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <string>
#include <utility>
#include <vector>
#include <queue>

using namespace std;
const int N = 400;
const int inf = 0x3ffffff;

string mat[N];
int col[N],vis[N],loop,cnt[N],dis[N];
vector<pair<int,int> > gr[N];
queue<int> q;

void dfs(int now,int c,int n) {
	if(loop) return;
	vis[now]=1;
	col[now]=c;
	for(int i=0; i<n; i++)
		if(mat[now][i]=='1') {
			if(vis[i]) {
				if(col[i]==c) {
					loop=1;
					return;
				}
				continue;
			}
			dfs(i,1-c,n);
		}
}

int spfa(int st,int n) {
	memset(vis,0,sizeof(vis));
	memset(cnt,0,sizeof(cnt));
	for(; !q.empty();)
		q.pop();
	for(int i=0; i<=n; i++)
		dis[i]=inf;
	q.push(st);
	vis[st]=1;
	dis[st]=0;
	cnt[st]++;
	for(; !q.empty();) {
		int now=q.front();
		vis[now]=0;
		if(cnt[now]>n+1)
			return 0;
		q.pop();
		for(int i=0; i<gr[now].size(); i++) {
			int to=gr[now][i].first;
			int tl=gr[now][i].second;
			if(dis[to]>tl+dis[now]) {
				dis[to]=tl+dis[now];
				if(!vis[to]) {
					vis[to]=1;
					q.push(to);
					cnt[to]++;
				}
			}
		}
	}
	return 1;
}

int main() {
	int T;
	scanf("%d",&T);
	for(int ca=1; ca<=T; ca++) {
		int n;
		scanf("%d",&n);
		for(int i=0; i<n; i++) {
			cin>>mat[i];
		}
		memset(col,0,sizeof(col));
		memset(vis,0,sizeof(vis));
		loop=0;
		for(int i=0; i<n; i++) {
			if(mat[i][i]=='1')
				loop=1;
			if(!vis[i])
				dfs(i,0,n);
		}
		if(loop)
			puts("No");
		else {
			for(int i=0; i<=n; i++)
				gr[i].clear();
			for(int i=0; i<n; i++) {
				if(col[i]) {
					gr[0].push_back(make_pair(i+1,N-1));
					gr[i+1].push_back(make_pair(0,0));
				}
				else {
					gr[i+1].push_back(make_pair(0,N-1));
					gr[0].push_back(make_pair(i+1,0));
				}
			}
			for(int i=0; i<n; i++) {
				for(int j=i+1; j<n; j++) {
					if(mat[i][j]=='1') {
						if(col[i]) {
							gr[i+1].push_back(make_pair(j+1,-N));
						}
						else {
							gr[j+1].push_back(make_pair(i+1,-N));
						}
					}
					else {
						gr[i+1].push_back(make_pair(j+1,N-1));
						gr[j+1].push_back(make_pair(i+1,N-1));
					}
				}
			}
			if(spfa(0,n)) 
				puts("Yes");
			else 
				puts("No");
		}
	}
	return 0;
}
