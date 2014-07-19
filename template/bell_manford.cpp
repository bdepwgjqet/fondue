//bellman_ford 邻接阵
#include <cstdio>

#define MAXN 200
#define inf  1000000000
typedef int  elem_i;

//最短路径 (单源bellman_ford邻接阵)
//单源最短路径,bellman_ford算法,邻接阵形式,复杂度O(n^3)
//求出源s到所有点的最短路经,传入图的大小n和邻接阵 mat
//返回到各点最短距离min[]和路径pre[],pre[i]记录 s到 i路径上i的父结点,pre[s]=-1
//可更改路权类型,路权可为负,若图包含负环则求解失败,返回 0
//优化:先删去负边使用dijkstra 求出上界,加速迭代过程
int bellman_ford(int n,elem_i mat[][MAXN],int s,elem_i *min,int *pre)
{
    int v[MAXN],i,j,k,tag;
    for(i=0; i<n; i++)  min[i]=inf,v[i]=0,pre[i]=-1;
    for(min[s]=0,j=0; j<n; j++)     //dijkstra
    {
        for(k=-1,i=0; i<n; i++)
            if(!v[i] && (k==-1||min[i]<min[k]))
                k=i;
        for(v[k]=1,i=0; i<n; i++)
            if(!v[i] && mat[k][i]>=0 && min[k]+mat[k][i]<min[i])
                min[i]=min[k]+mat[pre[i]=k][i];
    }
    for(tag=1,j=0; tag&&j<=n; j++)
        for(tag=i=0; i<n; i++)
            for(k=0; k<n; k++)
                if(min[k]+mat[k][i]<min[i])
                    min[i]=min[k]+mat[pre[i]=k][i],tag=1;
    return j<=n;
}

//bellman_ford 邻接表 O(m*n)	ac poj 3259  
//可自行添加pre数组记录前一个点
#include <cstdio>
#define inf 1000000
#define MAXS 30000
#define MAXN 500
typedef int elem_t;

struct edge{ int f,t,n; elem_t l; }e[MAXS];
int list[MAXN],top;
elem_t min[MAXN];

void insert(int f,int t,elem_t l)
{
	e[top].f=f,e[top].t=t,e[top].l=l;
	e[top].n=list[f],list[f]=top++;
}

int bellman_ford(int n,int s)
{
	int i,tag,j;
	for(i=0; i<n; i++)	min[i]=inf;
	for(min[s]=i=0,tag=1; i<=n&&tag; i++)
	{
		for(tag=0,j=0; j<top; j++)
			if(min[e[j].f]+e[j].l<min[e[j].t])
				min[e[j].t]=min[e[j].f]+e[j].l,tag=1;
	}
	return i<=n;
}
