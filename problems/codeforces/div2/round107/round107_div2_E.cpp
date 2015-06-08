#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#define eps 1e-8
#define inf 0x3fffffff
#define N 200011
typedef long long LL;
using namespace std;

struct segtree{ int l,r; LL lx,rx,mx; }seg[N<<2],ret;
int n,m,c,x[N];
LL val[N],sum;

int L(int i){ return i<<1; }
int R(int i){ return i<<1|1; }

void build(int id,int l,int r)
{
    int m=(l+r)>>1;
    seg[id].l=l,seg[id].r=r;
    if(l==r)
    {
        seg[id].mx=seg[id].lx=seg[id].rx=max(0LL,val[l]-val[l-1]);
        return ;
    }
    build(L(id),l,m);
    build(R(id),m+1,r);
    seg[id].mx=max(max(seg[L(id)].mx,seg[R(id)].mx),seg[L(id)].rx+seg[R(id)].lx);
    seg[id].lx=max(seg[L(id)].lx,seg[R(id)].lx+val[m]-val[l-1]);
    seg[id].rx=max(seg[R(id)].rx,seg[L(id)].rx+val[r]-val[m]);
}

void query(int id,int ll,int rr)
{
    int l=seg[id].l,r=seg[id].r,m=(l+r)>>1;
    if(l>=ll&&r<=rr)
    {
        if(ret.mx==-1)
            ret=seg[id],sum=val[r]-val[l-1];
        else
        {
            ret.mx=max(ret.mx,max(seg[id].mx,seg[id].lx+ret.rx));
            ret.lx=max(ret.lx,sum+seg[id].lx);
            ret.rx=max(seg[id].rx,val[r]-val[l-1]+ret.rx);
            sum+=val[r]-val[l-1];
        }
        return;
    }
    if(m>=ll)
        query(L(id),ll,rr);
    if(m+1<=rr)
        query(R(id),ll,rr);
}

int main()
{
    int p;
    scanf("%d%d%d",&n,&m,&c);
    for(int i=0; i<n; i++)
        scanf("%d",&x[i]);
    val[0]=0;
    for(int i=1; i<n; i++)
    {
        scanf("%d",&p);
        val[i]=val[i-1]+(x[i]-x[i-1])*50LL-1LL*p*c;
    }
    /*
    for(int i=0; i<n; i++)
        printf("%lld ",x[i]);
    puts("");
    */
    build(1,1,n-1);
    int l,r;
    double rr=0;
    for(int i=0; i<m; i++)
    {
        scanf("%d%d",&l,&r);
        ret.mx=-1;
        sum=0;
        query(1,l,r-1);
        rr+=ret.mx;
    //    printf("%lf\n",rr);
    }
    printf("%.6lf\n",rr/100);
    return 0;
}
