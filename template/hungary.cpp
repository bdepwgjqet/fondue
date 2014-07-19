//hungary.c
//二分图最大匹配,hungary算法,邻接表形式,复杂度O(m*e)
//返回最大匹配数,传入二分图大小m,n和邻接表list(只需一边)__此模板为m个点这边
//match1,match2返回一个最大匹配,未匹配顶点match值为-1
#include <cstdio>
#define MAXN 220
#define MAXS 100000
typedef int elem_t;

struct edge{ int f,t,n; elem_t l; }e[MAXS];
int top,match1[MAXN],q[MAXS],match2[MAXN],list[MAXN],tmp2[MAXN];

void insert(int f,int t,elem_t l)
{
	e[top].f=f,e[top].t=t,e[top].l=l;
	e[top].n=list[f],list[f]=top++;
}

int hungary(int m,int n)
{
	int i,j,k,l,r,mx=(m>n)?m:n,ret=0,x,y,t;
	for(i=0; i<mx; i++)	match1[i]=match2[i]=-1;
	for(i=0; i<m; ret+=(match1[i++]>-1))
	{
		for(j=0; j<n; j++)	tmp2[j]=-1;
		for(q[l=r=0]=i; l<=r&&match1[i]<0; l++)
			for(k=q[l],j=list[k]; j!=-1&&match1[i]<0; j=e[j].n)
				if(tmp2[e[j].t]<0)
				{
					q[++r]=match2[e[j].t],tmp2[e[j].t]=k;
					if(q[r]<0)
						for(y=e[j].t; y>=0; y=t)	
							match2[y]=x=tmp2[y],t=match1[x],match1[x]=y;
				}
	}
	return ret;
}




//dfs
#include <cstdio>
#define N 1001
#define S 1000001

struct edge{ int f,t,n; }e[S];
int list[N],top,y[N],match[N];

int find(int now)
{
	for(int i=list[now]; i!=-1; i=e[i].n)
	{
		int to=e[i].t;
		if(!y[to])
		{
			y[to]=1;
			if(match[to]<0||find(match[to]))
			{
				match[to]=now;
				return 1;
			}
		}
	}
	return 0;
}

int hungary(int m,int n)
{
	int ret=0;
	memset(match,-1,sizeof(match));
	for(int i=0; i<m; i++)	
	{
		memset(y,0,sizeof(y));
		if(find(i))
			ret++;
	}
	return ret;
}

