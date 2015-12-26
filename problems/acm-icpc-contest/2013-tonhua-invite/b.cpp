#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <utility>

using namespace std;
const int N = 460;
const int inf = 0x3fffffff;

struct edge {
	int to,cost,flow,anti;
	edge(){}
	edge(int t,int c,int f,int a):to(t),cost(c),flow(f),anti(a){}
};

vector<edge> gr[N+2];
queue<int> q;
pair<int,int> pre[N];
int dis[N],vis[N],max_flow;

void insert(int f,int t,int c,int flow) {
	gr[f].push_back(edge(t,c,flow,gr[t].size()));
	gr[t].push_back(edge(f,-c,0,gr[f].size()-1));
}

int spfa(int n,int s,int t) {
	for(; !q.empty(); ) {
		q.pop();
	}
	for(int i=0; i<n; i++) {
		dis[i]=inf,vis[i]=0;
		pre[i]=make_pair(-1,-1);
	}
	q.push(s);
	dis[s]=0,vis[s]=1;
	for(; !q.empty();) {
		int now=q.front();
		q.pop();
		vis[now]=0;
		for(int i=0; i<gr[now].size(); i++) {
			int to=gr[now][i].to;
			if(gr[now][i].flow>0 && dis[to]>dis[now]+gr[now][i].cost) {
				dis[to]=dis[now]+gr[now][i].cost;
				pre[to]=make_pair(now,i);
				if(!vis[to]) {
					vis[to]=1;
					q.push(to);
				}
			}
		}
	}
	return pre[t].first>=0;
}

int mcmf(int n,int s,int t) {
	int ret=0;
	max_flow=0;
	for(; spfa(n,s,t);) {
		int now_flow=inf;
		for(int i=t; pre[i].first != -1; i=pre[i].first) {
			int x=pre[i].first,y=pre[i].second;
			now_flow=min(now_flow,gr[x][y].flow);
		}
		for(int i=t; pre[i].first != -1; i=pre[i].first) {
			int x=pre[i].first,y=pre[i].second;
			int to=gr[x][y].to;
			gr[x][y].flow-=now_flow;
			gr[to][gr[x][y].anti].flow+=now_flow;
		}
		max_flow+=now_flow;
		ret+=now_flow*dis[t];
	}
	return ret;
}

double len[N][N];

struct node {
	int x,y,b,p;
	vector<int> gp;
	void init() {
		gp.clear();
	}
}no[N];

double cal(double x,double y) {
	return sqrt(x*x+y*y);
}

int main() {
	int T;
	scanf("%d",&T);
	for(int ca=1; ca<=T; ca++) {
		int n,m;
		scanf("%d%d",&n,&m);
		scanf("%d%d",&no[0].x,&no[0].y);
		for(int i=1; i<n; i++) {
			no[i].init();
			scanf("%d%d%d%d",&no[i].x,&no[i].y,&no[i].b,&no[i].p);
			for(int j=0; j<m; j++) {
				int x;
				scanf("%d",&x);
				no[i].gp.push_back(x);
			}
		}
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				len[i][j]=cal(no[i].x-no[j].x,no[i].y-no[j].y);
			}
		}
		int ret=0;
		for(int k=0; k<m; k++) {
			for(int i=0; i<=3*n+1; i++) {
				gr[i].clear();
			}
			for(int i=1; i<n; i++) {
				insert(0,i,1,no[i].gp[k]);
				insert(i,n+i,0,no[i].gp[k]);
				insert(n+i,3*n,0,no[i].gp[k]);
				insert(0,2*n+i,0,no[i].gp[k]);
				for(int j=1; j<n; j++) {
					if(i==j) continue;
					if(no[i].b+no[i].p+len[i][j]<=no[j].b) {
						insert(2*n+i,n+j,0,no[i].gp[k]);
					}
				}
			}
			ret+=mcmf(3*n+1,0,3*n);
		}
		printf("%d\n",ret);
	}
	return 0;
}
