//prim  优先队列
//经nkoj 2184 ac
#include <cstdio>
#include <queue>
using namespace std;
#define MAXN 10010
#define MAXS 200020
#define inf 1000000000
typedef int elem_t;

struct edge{ int f,t,n; elem_t l; }e[MAXS];
struct heap_t{ int v; elem_t l; 
	friend bool operator<(heap_t a,heap_t b){ return a.l>b.l; }
}h_t;
int top,pre[MAXN],v[MAXN],list[MAXN];
elem_t min_l[MAXN];

void insert(int f,int t,elem_t l)
{
	e[top].f=f,e[top].t=t,e[top].l=l;
	e[top].n=list[f],list[f]=top++;
}

elem_t prim(int n)
{
	int i,j; elem_t ret=0;	
	priority_queue<heap_t> q;
	for(i=0; i<n; i++)	min_l[i]=inf,v[i]=0,pre[i]=-1;
	h_t.v=h_t.l=0; q.push(h_t);
	for(; !q.empty(); )
	{
		h_t=q.top(),q.pop(); i=h_t.v;
		if(!v[i])
			for(v[i]=1,ret+=h_t.l,j=list[i]; j!=-1; j=e[j].n)
				if(!v[e[j].t]&&min_l[e[j].t]>e[j].l)
					pre[e[j].t]=i,min_l[h_t.v=e[j].t]=h_t.l=e[j].l,q.push(h_t);
	}
	return ret;
}

int main()
{
	int n,m,l,i,x,y; elem_t ret;
	scanf("%d%d",&n,&m);
	for(top=i=0; i<n; i++)	list[i]=-1;
	for(i=0; i<m; i++)
	{
		scanf("%d%d%d",&x,&y,&l);
		insert(x-1,y-1,l);
		insert(y-1,x-1,l);
	}
	ret=prim(n);
	printf("%d\n",ret);
	return 0;
}

