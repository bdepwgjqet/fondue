#include <cstdio>
#include <algorithm>
#include <cstring>
#define N 4001
using namespace std;

int dp[N],n,a,b,c;

int dfs(int w)
{
    int ret=0;
    if(dp[w]!=-1)    return dp[w];
    if(w==0)        return dp[w]=0;
    if(w>=a)
    {
        int t=dfs(w-a);
        if(t>=0)
            ret=max(ret,t+1);
    }
    if(w>=b)
    {
        int t=dfs(w-b);
        if(t>=0)
            ret=max(ret,t+1);
    }
    if(w>=c)
    {
        int t=dfs(w-c);
        if(t>=0)
            ret=max(ret,t+1);
    }
    if(ret==0)
        return dp[w]=-N;
    return dp[w]=ret;
}

int main()
{
    while(scanf("%d%d%d%d",&n,&a,&b,&c)!=EOF)
    {
        memset(dp,-1,sizeof(dp));
        printf("%d\n",dfs(n));
    }
    return 0;
}
