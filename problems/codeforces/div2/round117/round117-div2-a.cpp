#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#define eps 1e-8
#define inf 0x3fffffff
#define N 1111
using namespace std;

struct segment{ double x1,y1,x2,y2,l; }seg[N];
struct heap_t{ int l,i;
    friend bool operator<(heap_t a,heap_t b){
        return a.l>b.l; 
    }
}ht;

double a,b,sx,sy,ex,ey;
int n,mm[N],v[N];
priority_queue<heap_t> q;

double len(double x1,double x2,double x3,double x4)
{
    if(x1>x3)
        swap(x1,x3),swap(x2,x4);
    return x3>x2?x3-x2:0;
}

double dist(int f,int t)
{
    double u=len(seg[f].x1,seg[f].x2,seg[t].x1,seg[t].x2);
    double v=len(seg[f].y1,seg[f].y2,seg[t].y1,seg[t].y2);
    return sqrt(u*u+v*v);
}

int ok(int f,int t)
{
    double ll=dist(f,t);
    if(ll>a+eps)
        return 0;
    seg[t].l=min(seg[t].l,ll+mm[f]*(a+b));
    if(mm[t]<=mm[f]+1)  return 0;
    mm[t]=mm[f]+1;
    return 1;
}

void dijkstra(int start)
{
    memset(v,0,sizeof(v));
    mm[start]=0;
    ht.i=start,ht.l=0;
    q.push(ht);
    for(; !q.empty(); )
    {
        ht=q.top();
        q.pop();
        int id=ht.i,l=ht.l;
        if(l!=mm[id])   continue;
        v[id]=1;
        for(int i=0; i<n; i++)
            if(ok(id,i)&&!v[i])
                ht.l=mm[i],ht.i=i,q.push(ht);
    }
}

int main()
{
    scanf("%lf%lf",&a,&b);
    scanf("%lf%lf%lf%lf",&sx,&sy,&ex,&ey);
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%lf%lf%lf%lf",&seg[i].x1,&seg[i].y1,&seg[i].x2,&seg[i].y2);
        seg[i].l=inf; mm[i]=N;
        if(seg[i].x1>seg[i].x2)
            swap(seg[i].x1,seg[i].x2);
        if(seg[i].y1>seg[i].y2)
            swap(seg[i].y1,seg[i].y2);
    }
    seg[n].x1=seg[n].x2=sx;
    seg[n].y1=seg[n].y2=sy;
    seg[n+1].x1=seg[n+1].x2=ex;
    seg[n+1].y1=seg[n+1].y2=ey;
    mm[n+1]=N,seg[n+1].l=inf;
    seg[n].l=0;
    n+=2;
    dijkstra(n-2);
    if(mm[n-1]<N)
        printf("%.10lf\n",seg[n-1].l);
    else
        puts("-1");
    return 0;
}
