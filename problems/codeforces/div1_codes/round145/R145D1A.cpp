#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#define N 111

using  namespace std;

int vis[N];
struct node{ int z,l,n,p; }no[N];
char s[N];

int main()
{
	int n,k;
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	while(scanf("%d%d",&n,&k)+1)
	{
		memset(vis,0,sizeof(vis));
		for(int i=0; i<k; i++)
		{
			int x;
			scanf("%d",&x);
			vis[x]=1;
		}
		int m,mx=0,lm=0;
		scanf("%d",&m);
		for(int i=0; i<m; i++)
		{
			int x;
			scanf("%s%d",&s,&x);
			no[i].n=x;
			no[i].z=0,no[i].l=0;
			for(int j=0; j<x; j++)
			{
				int y;
				scanf("%d",&y);
				if(y==0)
					no[i].z++;
				else if(vis[y])
					no[i].l++;
			}
			no[i].p=min(k,no[i].l+no[i].z);
			int z=no[i].l;
			no[i].l=min(z+max(no[i].n-z-(n-k),0),k);
			mx=max(no[i].p,mx);
			lm=max(lm,no[i].l);
		}
		for(int i=0; i<m; i++)
		{
			if(no[i].l>no[i].p)
				for(;;);
			if(no[i].p<lm)
			{
				puts("1");
			}
			else
			{
				int mxx=0;
				for(int j=0; j<m; j++)
				{
					if(j==i) continue;
					mxx=max(mxx,no[j].p);
				}
				if(no[i].l>=mxx)
					puts("0");
				else
					puts("2");
			}
		}
	}
	return 0;
}
