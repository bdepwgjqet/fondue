//kruskal  优先队列＋并查集
//nkoj 2184 ac
#include <cstdio>
#include <cstring>
#include <queue>
#define MAXN 10010
#define MAXS 200020
#define inf 1000000000
typedef int elem_t;
using namespace std;

struct edge{ int f,t,n; elem_t l; 
	friend bool operator<(edge a,edge b){ return a.l>b.l; }
}e[MAXS],e_t;
struct ufind
{
	int p[MAXN],t;
	void ini(){ memset(p,0,sizeof(p)); }
	void run(int &x){ for(; p[t=x]; x=p[x],p[t]=(p[x]?p[x]:x));}
	int isfriend(int i,int j){ run(i); run(j); return i==j&&i; }
	void setfriend(int i,int j){ run(i); run(j); p[i]=(i==j)?0:j; }
}uf;
int top,list[MAXN];

void insert(int f,int t,elem_t l)
{
	e[top].f=f,e[top].t=t,e[top].l=l;
	e[top].n=list[f],list[f]=top++;
}

elem_t kruskal(int n)
{
	priority_queue<edge> q;
	uf.ini(); elem_t ret=0; 
	int i,j;
	for(i=0; i<n; i++)
		for(j=list[i]; j!=-1; j=e[j].n)
			q.push(e[j]);
	for(i=0; i<n-1&&!q.empty(); )
	{
		e_t=q.top(); q.pop();
		if(!uf.isfriend(e_t.f+1,e_t.t+1))
			ret+=e_t.l,uf.setfriend(e_t.f+1,e_t.t+1),i++;
	}
	return ret;
}

int main()
{
	int n,i,m,l,x,y; elem_t ret;
	scanf("%d%d",&n,&m);
	for(top=i=0; i<n; i++)	list[i]=-1;
	for(i=0; i<m; i++)
		scanf("%d%d%d",&x,&y,&l),insert(x-1,y-1,l),insert(y-1,x-1,l);
	//printf("%d\n",top);
	ret=kruskal(n);
	printf("%d\n",ret);
	return 0;
}
