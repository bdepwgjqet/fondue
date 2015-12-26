//dijkstra 邻接阵
#include <cstdio>
#include <cstring>

const int MAXN=1001;
const int inf=1000000000;
typedef int elem_i;
int min1[MAXN],min2[MAXN],mat[MAXN][MAXN];
//最短路径(单源 dijkstra 邻接阵) 
//单源最短路径,dijkstra算法,邻接阵形式,复杂度O(n^2) 
//求出源s到所有点的最短路经,传入图的顶点数n,(有向)邻接矩阵mat 
//返回到各点最短距离min[]和路径pre[],pre[i]记录 s到 i路径上i的父结点,pre[s]=-1 
//可更改路权类型,但必须非负!
void dijkstra(int n,elem_i mat[][MAXN],int s,elem_i min[],int pre[])    //pre[] to record the path
{		 
  	int v[MAXN],i,j,k;
  	for(i=0;i<n;i++)	v[i]=0,min[i]=inf,pre[i]=-1;		            //pre[i] records: pre[i] -> i ;
	for(min[s]=0,i=0;i<n;i++){
	for(k=-1,j=0;j<n;j++)
	if (!v[j]&&((k==-1)||min[j]<min[k]))
		k=j;
	for(v[k]=1,j=0;j<n;j++)
	if(!v[j] && min[k]+mat[k][j]<min[j])	
		min[j]=min[k]+mat[pre[j]=k][j];
	}
}




//dijkstra 优先队列
//AC 经poj 3268测试
#include <cstdio>
#include <queue>
#define MAXN 1000
#define MAXS 2000000
#define inf 100000000
using namespace std;
typedef int elem_t;
struct edge{ int f,t,n; elem_t l; }e[MAXS];
struct heap_t
{ 
	int v; elem_t l;
	friend bool operator<(heap_t a,heap_t b){ return a.l>b.l; }
}h_t;
int list[MAXN],top=0,v[MAXN],pre[MAXN];
elem_t min_l[MAXN];
priority_queue<heap_t> q;

void insert(int f,int t,elem_t l)
{
	e[top].f=f,e[top].t=t,e[top].l=l;
	e[top].n=list[f],list[f]=top++;
}

void dijkstra(int n,int s)
{
	int i;
	for(i=0; i<n; i++)	v[i]=0,min_l[i]=inf,pre[i]=-1;
	min_l[h_t.v=s]=h_t.l=0; q.push(h_t);
	for(; !q.empty();)
	{
		h_t=q.top(),q.pop();
		if(!v[h_t.v])
			for(v[h_t.v]=1,i=list[h_t.v]; i!=-1; i=e[i].n)
				if(!v[e[i].t]&&min_l[e[i].f]+e[i].l<min_l[e[i].t])
					pre[e[i].t]=e[i].f,min_l[h_t.v=e[i].t]=h_t.l=min_l[e[i].f]+e[i].l,q.push(h_t);
	}
}


/////////////////////////////////////////////////////////////////////////////////////////////
/* poj 3268
#include <cstdio>
#include <queue>
#define MAXN 1001
#define MAXS 200001
#define inf 100000000
using namespace std;
typedef int elem_t;
struct edge{ int f,t,n; elem_t l; }e[MAXS];
struct heap_t
{ 
	int v; elem_t l;
	friend bool operator<(heap_t a,heap_t b){ return a.l>b.l; }
}h_t;
int list[MAXN],top=0,v[MAXN],pre[MAXN],x[MAXS],y[MAXS];
elem_t min_l1[MAXN],min_l2[MAXN],ll[MAXS];
priority_queue<heap_t> q;

void insert(int f,int t,elem_t l)
{
	e[top].f=f,e[top].t=t,e[top].l=l;
	e[top].n=list[f],list[f]=top++;
}

void dijkstra(int n,int s,int min_l[])
{
	int i;
	for(i=0; i<n; i++)	v[i]=0,min_l[i]=inf,pre[i]=-1;
	min_l[h_t.v=s]=h_t.l=0; q.push(h_t);
	for(; !q.empty();)
	{
		h_t=q.top(),q.pop();
		if(!v[h_t.v])
			for(v[h_t.v]=1,i=list[h_t.v]; i!=-1; i=e[i].n)
				if(!v[e[i].t]&&min_l[e[i].f]+e[i].l<min_l[e[i].t])
					pre[e[i].t]=e[i].f,min_l[h_t.v=e[i].t]=h_t.l=min_l[e[i].f]+e[i].l,q.push(h_t);
	}
}

int main()
{
	int ret,n,m,i,j,s;
	scanf("%d%d%d",&n,&m,&s);
	for(top=i=0; i<n; i++)	list[i]=-1;
	for(i=0; i<m; i++)
	{
		scanf("%d%d%d",&x[i],&y[i],&ll[i]);
		insert(x[i]-1,y[i]-1,ll[i]);
	}
	dijkstra(n,s-1,min_l1);
	for(i=0; i<n; i++)	list[i]=-1;
	for(top=i=0; i<m; i++)
		insert(y[i]-1,x[i]-1,ll[i]);
	dijkstra(n,s-1,min_l2);
	for(ret=i=0; i<n; i++)//printf("%d %d \n",min_l1[i-1],min_l2[i-1]))
		if(ret<min_l1[i]+min_l2[i])	ret=min_l1[i]+min_l2[i];
	printf("%d\n",ret);
	return 0;
}
*/
