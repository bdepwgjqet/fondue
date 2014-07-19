#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
#define N 1001

using namespace std;

struct node{ int x,y; }no[N];
vector<pair<int,int> > ans;

int tx[N],ty[N],ri[N];

int main()
{
	int n;
	while(scanf("%d",&n)+1)
	{
		ans.clear();
		memset(tx,0,sizeof(tx));
		memset(ty,0,sizeof(ty));
		for(int i=0; i<n-1; i++)
		{
			scanf("%d%d",&no[i].x,&no[i].y);
			tx[no[i].x]=ty[no[i].y]=1;
		}
		for(int i=n; i>0; i--)
		{
			ri[i]=0;
			if(ty[i]==1)
			{
				for(int j=1; j<i; j++)
					if(ty[j]==0)
					{
						ty[i]=0;
						ty[j]=1;
						ans.push_back(make_pair(2,N*i+j));
						for(int u=0; u<n; u++)
							if(no[u].y==i)
								no[u].y=j;
						break;
					}
			}
		}
		for(int i=0; i<n-1; i++)
		{
			ri[no[i].x]=max(ri[no[i].x],no[i].y);
		}
		int now;
		for(int i=1; i<=n; i++)
		{
			now=i;
			for(int j=i+1; j<=n; j++)
				if(ri[j]<ri[now])
				{
					now=j;
				}
			if(now!=i)
			{
				ans.push_back(make_pair(1,i*N+now));
				swap(ri[now],ri[i]);
			}
		}
		printf("%d\n",ans.size());
		for(int i=0; i<ans.size(); i++)
		{
			printf("%d %d %d\n",ans[i].first,ans[i].second/N,ans[i].second%N);
		}
	}
	return 0;
}
