#include <cstdio>
#include <algorithm>
#include <cstring>
#define N 200001
using namespace std;

int a[N],b[N],v[N],id[N];

int main()
{
    int n,ret=0,ans;
    while(scanf("%d",&n)!=EOF)
    {
        memset(v,0,sizeof(v));
        ret=0;
        ans=0;
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
            id[a[i]]=i;
        }
        for(int i=1; i<=n; i++)
            scanf("%d",&b[i]);
        int ai=n;
        for(int i=n; i>=1; )
        {
            int x=b[i];
            if(v[x])
            {
                i--;
                continue;
            }
            int j=id[x];
            ret+=ai-j+1;
            if(j!=ai)
                ans=max(ans,n-j);
            for(int k=j; k<=ai; k++)
                v[a[k]]=1;
            ai=j-1;
        }
        printf("%d\n",ans);
    }
    return 0;
}
