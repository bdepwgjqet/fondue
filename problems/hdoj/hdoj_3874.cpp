#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define N 51000
#define M 1100000
using namespace std;
typedef long long LL; 

LL sum[N],ret[M];
int id[M],n,m,num[N];

struct node{ int l,r,i; }no[M];
int cmp(node a,node b){ return a.r<b.r; }
inline int lowbit(int i){ return i&(-i); }

void add(int x,int id)
{
    for(int i=id; i<N; i+=lowbit(i))
        sum[i]+=x;
}

LL calc(int n)
{
    LL ret=0;
    for(int i=n; i; i-=lowbit(i))
        ret+=sum[i];
    return ret;
}

int main()
{
    int t,ca;
    scanf("%d",&t);
    for(ca=1; ca<=t; ca++)
    {
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
			scanf("%d",&num[i]);
        scanf("%d",&m);
        for(int i=0; i<m; i++)
        {
            scanf("%d%d",&no[i].l,&no[i].r);
			if(no[i].l>no[i].r)
				swap(no[i].l,no[i].r);
            no[i].i=i;
        }
        sort(no,no+m,cmp);
        memset(sum,0,sizeof(sum));
       // memset(id,-1,sizeof(id));
		memset(id,0,sizeof(id));
        int now=1;
        for(int i=0; i<m; i++)
        {
            int rr=no[i].r;
            for(; rr>=now; now++)
            {
                int x=num[now];
                if(id[x]>0)
                    add(-x,id[x]);
                id[x]=now;
                add(x,now);
            }
            ret[no[i].i]=calc(rr)-calc(no[i].l-1);
        }
        for(int i=0; i<m; i++)
			printf("%I64d\n",ret[i]);
    }
    return 0;
}
