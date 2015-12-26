//min_cost_max_flow_mcmf
//style 1
#include <cstdio>
#define inf 1000000000
#define MAXN 200
#define MAXS 160000

struct edge{ int f,t,c,flow,n; }e[MAXS];
int list[MAXN],top,q[MAXS],v[MAXN],pre[MAXN],min[MAXN],max_flow;

void s_insert(int f,int t,int c,int flow)
{
	e[top].f=f,e[top].t=t,e[top].c=c,e[top].flow=flow;
	e[top].n=list[f],list[f]=top++;
}

void insert(int f,int t,int c,int flow)
{
	s_insert(f,t,c,flow);
	s_insert(t,f,-c,0);
}

int spfa(int n,int s,int t)
{
	int i,l,r,j;
	for(i=0; i<n; i++)	pre[i]=-1,min[i]=inf,v[i]=0;
	q[l=r=0]=s;
	min[s]=0,v[s]=1;
	for(; l<=r; )
	{
		i=q[l++];
		v[i]=0;
		for(j=list[i]; j!=-1; j=e[j].n)
			if(e[j].flow>0&&min[i]+e[j].c<min[e[j].t])
			{
				pre[e[j].t]=j;
				min[e[j].t]=min[i]+e[j].c;
				if(!v[e[j].t])
					v[e[j].t]=1,q[++r]=e[j].t;
			}
	}
	return min[t]!=inf;
}

int mcmf(int n,int s,int t)
{
	int ret=0,i,now_flow;
	max_flow=0;
	for(; spfa(n,s,t); )
	{
		now_flow=inf;
		for(i=pre[t]; i!=-1; i=pre[e[i].f])
			if(now_flow>e[i].flow)
				now_flow=e[i].flow;
		for(i=pre[t]; i!=-1; i=pre[e[i].f])
			e[i].flow-=now_flow,e[i^1].flow+=now_flow;
		max_flow+=now_flow;
		ret+=now_flow*min[t];
	}
	return ret;
}


//style 2
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
