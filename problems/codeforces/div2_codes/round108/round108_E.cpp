/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  05/10/2012 09:02:14 PM
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
#include <fstream>
#include <functional>
#include <iostream>
#include <algorithm>
#define N 211   
#define X 128       
#define S 1000100
#define eps 1e-8
#define inf 0x3ffffff
#define MOD 1000000007
#define PB push_back
#define MP make_pair
#define SZ(a) ((int)((a).size()))
#define ALL(a) (a).begin(),(a).end()
#define CLR(a,x) memset(a,x,sizeof(a))

typedef long long LL;
using namespace std;

inline int L(int i){ return i<<1; }
inline int R(int i){ return (i<<1)|1; }
inline int B(int i){ return 1<<i; }
inline int low_bit(int x){ return x&(-x); }

struct node{ int x,y; }pre[X][N];

int n,m,k,dp[X][N],st,mn,q[S],top,val[N],v[N];
char mat[N][N];
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

void dfs(int state,int id)
{
    int x=id/n,y=id%n,u=pre[state][id].x,v=pre[state][id].y;
    mat[x][y]='X';
    if(u) dfs(u,v);
    if(u&&u!=state)
       dfs(u^state,v);
}

int inboard(int x,int y)
{
    return 0<=x&&x<m&&0<=y&&y<n;
}

void spfa()
{
    for(int i=1; i<=st; i++)
    {
        for(int u=0; u<mn; u++)
            for(int v=i&(i-1); v; v=i&(v-1))
            {
                int vv=dp[v][u]+dp[i^v][u]-val[u];
                if(vv<dp[i][u])
                    dp[i][u]=vv,pre[i][u].x=v,pre[i][u].y=u;
            }
        top=mn;
        for(int j=0; j<mn; j++)
            q[j]=j,v[j]=1;
        for(int j=0; j<top; j++)
        {
            int now=q[j],to,vv;
            v[now]=0;
            for(int u=0; u<4; u++)
            {
                int x=now/n+dir[u][0],y=now%n+dir[u][1];
                if(inboard(x,y))
                {
                    to=x*n+y;
                    vv=dp[i][now]+val[to];
                    if(vv<dp[i][to])
                    {
                        dp[i][to]=vv,pre[i][to].x=i,pre[i][to].y=now;
                        if(!v[to])  
                        {
                            q[top++]=to;
                            v[to]=1;
                        }
                    }
                }
            }
        }
     //   printf("%d\n",top);
    }
}

int main()
{
    int x,y;
    for(; ~scanf("%d%d%d",&m,&n,&k); )
    {
        st=(1<<k)-1;
        mn=n*m;
        memset(pre,0,sizeof(pre));
        memset(dp,0x3f,sizeof(dp));
        for(int i=0; i<mn; i++)
            scanf("%d",&val[i]);
        for(int i=0; i<k; i++)
        {
            scanf("%d%d",&x,&y);
            --x,--y;
            int t=x*n+y;
            dp[1<<i][t]=val[t];
        }
        spfa();
        int ret=inf,id;
        for(int i=0; i<mn; i++)
        {
            if(ret>dp[st][i])
                ret=dp[st][i],id=i;
        }
        printf("%d\n",ret);
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                mat[i][j]='.';
        dfs(st,id);
        for(int i=0; i<m; i++,puts(""))
            for(int j=0; j<n; j++)
                printf("%c",mat[i][j]);
    }
    return 0;
}
