//有向图强连通分支(tarjan算法),dfs邻接表形式,O(n+m)
//返回分支数,id[i]=j,点i所在分支为j   (j=1,2,3...)
//传入图的大小n,不相邻点边权l ( 可为0 )
#include <cstdio>
#include <cstring>
#define MAXN 5010
#define MAXS 100000
typedef int elem_t;

struct edge{ int f,t,n; elem_t l; }e[MAXS];
int v[MAXN],list[MAXN],id[MAXN],st[MAXN],dfn[MAXN],low[MAXN],cnt,top;

void insert(int f,int t,elem_t l)
{
	e[top].f=f,e[top].t=t,e[top].l=l;
	e[top].n=list[f],list[f]=top++;
}

void search(int n,int now,int &ret)
{
	int i;
	dfn[st[st[0]++]=now]=low[now]=++cnt; v[now]=1;
	for(i=list[now]; i!=-1; i=e[i].n)
		if(!dfn[e[i].t])
		{
			search(n,e[i].t,ret);
			if(low[e[i].t]<low[now])	low[now]=low[e[i].t];
		}
		else if(dfn[e[i].t]<dfn[now])
		{
			if(v[e[i].t]&&dfn[e[i].t]<low[now])
				low[now]=dfn[e[i].t];
		}
	if(low[now]==dfn[now])
		for(ret++; st[st[0]]!=now; id[st[--st[0]]]=ret,v[st[st[0]]]=0);
}

int find_components(int n)
{
	int ret=0,i;
	for(i=0; i<=n+1; i++)	st[i]=-1,dfn[i]=0;
	for(st[0]=1,cnt=i=0; i<n; i++)
		if(!dfn[i])
			search(n,i,ret);
	return ret;
}
