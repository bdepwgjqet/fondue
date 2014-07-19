#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#define N 200011

using namespace std;
typedef long long LL;

int a[N],vis[N<<1],v[N<<1],T;
LL dp[N<<1];
int tag[N<<1],n;

vector<int> tr[N<<1];

inline int get(int i){ return i>n?i-n:i; }

void dfs(int now)
{
	vis[now]=1;
	v[now]=T;
	dp[now]=a[get(now)];
	for(int i=0; i<tr[now].size(); i++)
	{
		int to=tr[now][i];
		if(to==1||to==n+1)
		{
			tag[now]=1;
			continue;
		}
		if(vis[to])
		{
			if(v[to]==T)
			{
				tag[now]=1;
				continue;
			}
			tag[now]=max(tag[now],tag[to]);
			dp[now]+=dp[to];
			continue;
		}
		if(v[to]==T)
		{
			tag[now]=1;
			continue;
		}
		dfs(to);
		dp[now]+=dp[to];
		tag[now]=max(tag[now],tag[to]);
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=2; i<=n; i++)
		scanf("%d",&a[i]);
	for(int i=2; i<=n; i++)
	{
		if(a[i]+i>n) ;
		else
		{
//			printf("%d %d\n",i,n+a[i]+i);
			tr[i].push_back(n+a[i]+i);
		}
	}
	for(int i=n+2; i<=n+n; i++)
	{
		int ii=i-n;
		if(ii-a[ii]<=0);
		else
		{
//			printf("%d %d\n",i,ii-a[ii]);
			tr[i].push_back(ii-a[ii]);
		}
	}
	memset(tag,0,sizeof(tag));
	memset(dp,0,sizeof(dp));
	memset(vis,0,sizeof(vis));
	memset(v,0,sizeof(v));
	for(int i=1; i<=n+n; i++)
	{
		if(i==1||i==n+1) continue;
		if(!vis[i])
		{
			T=i;
			dfs(i);
			//puts("");
		}
	}
	for(int i=1; i<n; i++)
	{
//		printf("%d=>\n",n+i+1);
		if(tag[n+i+1]==1)
			puts("-1");
		else
			cout<<dp[n+i+1]+i<<endl;
	}
	return 0;
}
