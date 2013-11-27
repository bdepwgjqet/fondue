//ZhuLiu MST
#include <cstdio>
#include <cstring>
#define inf 1e8
#define S 1000001
#define N 1001

typedef int elem_t;

struct edge{ int f,t; elem_t l; }e[S];
int top,list[N],id[N],v[N],pre[N];
elem_t len[N];

elem_t ZL_MST(int r,int n)
{
	int nextn,f,t;
	elem_t ret=0;
	while(1)
	{
		memset(pre,-1,sizeof(pre));
		memset(v,-1,sizeof(v));
		memset(id,-1,sizeof(id));
		for(int i=0; i<n; i++)
			len[i]=inf;
		for(int i=0; i<top; i++)
		{
			f=e[i].f,t=e[i].t;
			if(f==t) continue;
			if(len[t]>e[i].l)
				len[t]=e[i].l,pre[t]=f;
		}
		for(int i=0; i<n; i++)
			if(pre[i]==-1&&i!=r)
				return -1;	//impossible to spanning a tree
		nextn=0;
		len[r]=0;
		for(int i=0; i<n; i++)
		{
			ret+=len[i];
			int now=i;
			for(; v[now]!=i&&id[now]==-1&&now!=r; )
			{
				v[now]=i;
				now=pre[now];
			}
			if(now!=r&&id[now]==-1)
			{
				for(int f=pre[now]; f!=now; f=pre[f])
					id[f]=nextn;
				id[now]=nextn++;
			}
		}
		if(nextn==0) break;	//no rings
		for(int i=0; i<n; i++)
			if(id[i]<0)
				id[i]=nextn++;
		for(int i=0; i<top; i++)
		{
			f=e[i].f,t=e[i].t;
			e[i].f=id[f];
			e[i].t=id[t];
			if(f==t) continue;
			e[i].l-=len[t];
		}
		n=nextn;
		r=id[r];
	}
	return ret;
}
