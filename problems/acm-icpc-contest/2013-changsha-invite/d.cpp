#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

const int N = 222;
const int inf = 0x3ffffff;

struct node {
	int x,y,d;
	node(){}
	node(int x,int y,int d):x(x),y(y),d(d){}
	bool operator<(const node &a) const{
		return d>a.d;
	}
};

int val[N][N],dis[N][N],id[N][N],vis[N][N],goodcnt,midis[N][N];
vector<pair<int,int> > po;
vector<pair<int,int> > gr[N];
queue<node> q;
int m,n;

int dir[4][2]={{-1,0},{0,-1},{1,0},{0,1}};

int inboard(int x,int y) {
	return 0<=x&&x<m&&0<=y&&y<n;
}

int gid(int x,int y) {
	if(inboard(x,y))
		return id[x][y];
	return 0;
}

void solve(int nid,int x,int y) {
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			vis[i][j]=0;
			midis[i][j]=inf;
		}
	}
	for(; !q.empty();)
		q.pop();
	dis[nid][nid]=val[nid][nid];
	midis[x][y]=val[x][y];
	q.push(node(x,y,val[x][y]));
	vis[x][y]=1;
	for(; !q.empty();) {
		node now=q.front();
		q.pop();
		vis[now.x][now.y]=0;
		for(int i=0; i<4; i++) {
			int xx=now.x+dir[i][0],yy=now.y+dir[i][1];
			int nxid=gid(xx,yy);
			if(nxid==-1) {
				if(midis[xx][yy]>midis[now.x][now.y]+val[xx][yy] && val[xx][yy]>=0) {
					midis[xx][yy]=midis[now.x][now.y]+val[xx][yy];
					if(!vis[xx][yy]) {
						vis[xx][yy]=1;
						q.push(node(xx,yy,midis[now.x][now.y]+val[xx][yy]));
					}
				}
			} else if(nxid==0) {
				dis[nid][0]=min(dis[nid][0],midis[now.x][now.y]);
				dis[0][nid]=dis[nid][0];
			} else {
				if(midis[xx][yy]>midis[now.x][now.y]+val[xx][yy] && val[xx][yy]>=0) {
					midis[xx][yy]=midis[now.x][now.y]+val[xx][yy];
					dis[nid][nxid]=dis[nxid][nid]=min(dis[nid][nxid],midis[xx][yy]);
					if(!vis[xx][yy]) {
						vis[xx][yy]=1;
						q.push(node(xx,yy,midis[now.x][now.y]+val[xx][yy]));
					}
				}
			}
		}
	}
}

int dp[15][1<<14];

inline int B(int i){ 
	return 1<<i;
}

int dfs(int now,int st) {
	if(dp[now][st]>=0)
		return dp[now][st];
	int sub=0;
	if(now>=1)
		sub=val[po[now-1].first][po[now-1].second];
	if(st==B(goodcnt+1)-1) {
		return dp[now][st]=dis[now][0]-sub;
	}
	int ret=inf;
	for(int i=0; i<gr[now].size(); i++) {
		int to=gr[now][i].first;
		if((st&B(to))==0) {
			ret=min(dfs(to,st|B(to))+gr[now][i].second-sub,ret);
		}
	}
	return dp[now][st]=ret;
}

int main() {
	int T;
	scanf("%d",&T);
	for(int ca=1; ca<=T; ca++) {
		scanf("%d%d",&m,&n);
		for(int i=0; i<m; i++) {
			for(int j=0; j<n; j++) {
				scanf("%d",&val[i][j]);
			}
		}
		scanf("%d",&goodcnt);
		int now=1;
		memset(id,-1,sizeof(id));
		po.clear();
		for(int i=0; i<goodcnt; i++) {
			int x,y;
			scanf("%d%d",&x,&y);
			po.push_back(make_pair(x,y));
			id[x][y]=now++;
		}
		for(int i=0; i<20; i++) {
			for(int j=0; j<20; j++) {
				dis[i][j]=inf;
			}
		}
		dis[0][0]=0;
		for(int i=0; i<po.size(); i++) {
			int x=po[i].first,y=po[i].second;
			if(val[x][y]<0) continue;
			solve(id[x][y],x,y);
		}
		for(int i=0; i<N; i++)
			gr[i].clear();
		for(int i=0; i<now; i++) {
			for(int j=i+1; j<now; j++) {
				if(dis[i][j]<inf) {
					gr[i].push_back(make_pair(j,dis[i][j]));
					gr[j].push_back(make_pair(i,dis[i][j]));
				}
			}
		}
		memset(dp,-1,sizeof(dp));
		dfs(0,1);
		if(dp[0][1]>=0 && dp[0][1]<inf)
			printf("%d\n",dp[0][1]);
		else
			puts("0");
	}
	return 0;
}
