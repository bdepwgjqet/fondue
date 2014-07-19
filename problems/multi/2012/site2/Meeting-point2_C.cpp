/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  07/26/2012 07:26:05 PM
 ***/

#include <cstring>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <sstream>
#include <cmath>
#include <functional>
#include <iostream>
#include <algorithm>
#define N 110001
#define M 1000010
#define S 1000100
#define eps 1e-8
#define inf 10000000000000000LL
#define MOD 1000000007
#define PB push_back
#define MP make_pair
#define SZ(a) ((int)((a).size()))
#define ALL(a) (a).begin(),(a).end()
#define CLR(a,x) memset(a,x,sizeof(a))

typedef long long LL;
using namespace std;

LL disx1[N],disy1[N],disx2[N],disy2[N],x[N],y[N];
int n;
struct node{ LL x,y; }no[N];

int cmp(LL a,LL b){ return a<b; }

int get_id(LL x,LL *arr)
{
    int l=0,r=n-1,mid;
    for(; l<=r;)
    {
        mid=(l+r)>>1;
        if(arr[mid]<x)
            l=mid+1;
        else if(arr[mid]>x)
            r=mid-1;
        else
            return mid;
    }
    return -1;
}

void init()
{
    disx1[0]=0;
    disy1[0]=0;
    for(int i=1; i<n; i++)
    {
        disx1[i]=disx1[i-1]+i*(x[i]-x[i-1]);
        disy1[i]=disy1[i-1]+i*(y[i]-y[i-1]);
    }
    disx2[n-1]=0;
    disy2[n-1]=0;
    for(int i=n-2; i>=0; i--)
    {
        disx2[i]=disx2[i+1]+(n-i-1)*(x[i+1]-x[i]);
        disy2[i]=disy2[i+1]+(n-i-1)*(y[i+1]-y[i]);
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(scanf("%d",&n),t--)
    {
        for(int i=0; i<n; i++)
        {
            int xx, yy;
            scanf("%d%d", &xx, &yy);
            no[i].x = xx+yy;
            no[i].y = yy-xx;
            x[i]=xx+yy;
            y[i]=yy-xx;
        }
        sort(x,x+n,cmp);
        sort(y,y+n,cmp);
        init();
        LL ret=inf,tmp;
        for(int i=0; i<n; i++)
        {
            int id=get_id(no[i].x,x);
            tmp=disx1[id]+disx2[id];
            id=get_id(no[i].y,y);
            tmp+=disy1[id]+disy2[id];
            ret=min(ret,tmp);
        }
        cout<<ret/2<<endl;
    }
    return 0;
}
