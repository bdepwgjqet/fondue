#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
typedef long long LL;
#define N 111001
using namespace std;

struct edge{ int f,t,l; }e[N];
int cmp(edge a,edge b){ return a.l>b.l; }

int tag[N];

struct ufind
{
    int p[N],t;
    void init()
    {
        for(int i=0; i<N; i++)
            p[i]=i;
    }
    void run(int &x)
    {
        int y=x;
        for(; p[t=x]!=x; x=p[x],p[t]=p[x]);
        for(; p[t=y]!=x; p[t]=x,y=p[y]);
    }
    void setfriend(int i,int j)
    {
        run(i);
        run(j);
        p[i]=j;
    }
    int isfriend(int i,int j)
    {
        run(i);
        run(j);
        return i==j;
    }
}uf;

int main()
{
    int t,n,m;
    scanf("%d",&t);
    while(t--)
    {
        uf.init();
        memset(tag,0,sizeof(tag));
        scanf("%d%d",&n,&m);
        for(int i=0; i<n-1; i++)
            scanf("%d%d%d",&e[i].f,&e[i].t,&e[i].l);
        for(int i=0; i<m; i++)
        {
            int x;
            scanf("%d",&x);
            tag[x]=1;
        }
        sort(e,e+n-1,cmp);
        LL ret=0;
        for(int i=0; i<n-1; i++)
        {
            int x=e[i].f,y=e[i].t;
            uf.run(x),uf.run(y);
            if(tag[x]&&tag[y])
                ret+=e[i].l;
            else
            {
                uf.setfriend(x,y);
                if(tag[x]||tag[y])
                    tag[y]=tag[x]=1;
            }
        }
        cout<<ret<<endl;
    }
    return 0;
}
