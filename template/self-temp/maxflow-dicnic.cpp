//max_flow_dicnic
//anti(int ind) 求ind的反向边
#include <cstdio>
#define MAXN 20100
#define MAXS 880100
#define inf 0x7fffffff
typedef int elem_t;

struct edge{ int f,t,n; elem_t w; }e[MAXS];
int list[MAXN],top,q[MAXS],lay[MAXN];

void insert(int f,int t,elem_t w)
{
    e[top].f=f,e[top].t=t,e[top].w=w;
    e[top].n=list[f],list[f]=top++;
}

inline int anti(int ind){ return ind^1; }
inline int min(int a,int b){ return a<b?a:b; }

int bfs(int s,int t,int n)
{
    int l,r,i,j;
    for(i=0; i<n; i++)  lay[i]=-1;
    q[l=r=0]=s; lay[s]=0;
    for(; l<=r; )
    {
        i=q[l++];
        for(j=list[i]; j!=-1; j=e[j].n)
        {
            if(lay[e[j].t]<0&&e[j].w>0)
                lay[e[j].t]=lay[i]+1,q[++r]=e[j].t;
        }
    }
    return lay[t]>=0;
}

elem_t dfs(int now,int t,elem_t now_flow)
{
    int ttl=0,single,i,j;
    if(now==t)  return now_flow;
    for(i=list[now]; i!=-1&&ttl<now_flow; i=e[i].n)
        if(lay[e[i].t]==lay[now]+1&&e[i].w>0&&(single=dfs(e[i].t,t,min(e[i].w,now_flow-ttl))))
        {
            e[i].w-=single;
            e[anti(i)].w+=single;
            ttl+=single;
        }
    if(ttl==0)  lay[now]=-1;
    return ttl;
}

elem_t dicnic(int s,int t,int n)
{
    elem_t ret=0;
    while(bfs(s,t,n))
        ret+=dfs(s,t,inf);
    return ret;
}
