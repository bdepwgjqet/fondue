#include <cstdio>
#include <vector>
#include <map>
#define N 2001
#define X 1000001
#define MOD 1000000007

using namespace std;
typedef long long LL;

map<int,LL> mp;
vector<int> list[N];
int n,m,k;
int p[N];

int gcd(int a,int b){ return b?gcd(b,a%b):a; }

LL dfs(int now,LL pre)
{
	if(pre>k)
		return 0;
	int x=now*N+pre;
	if(mp.count(x)>0)
		return mp[x];
	int g=gcd(p[now],pre);
	LL nx=pre*p[now]/g;
	if(nx==pre)
		return mp[x]=0;
	if(now==n)
	{
		if(nx==k)
			return mp[x]=1;
		else 
			return mp[x]=0;
	}
	LL ret=0;
	for(int i=0; i<list[now].size(); i++)
	{
		int to=list[now][i];
		ret=(ret+dfs(to,nx))%MOD;
	}
	return mp[x]=ret;
}

int main()
{
	while(scanf("%d%d%d",&n,&m,&k)+1)
	{
		mp.clear();
		for(int i=0; i<=n; i++)
			list[i].clear();
		for(int i=0; i<m; i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			list[x].push_back(y);
		}
		for(int i=1; i<=n; i++)
			scanf("%d",&p[i]);
		LL ret=0;
		for(int i=0; i<list[1].size(); i++)
		{
			ret=(ret+dfs(list[1][i],p[1]))%MOD;
		}
		printf("%lld\n",ret);
	}
	return 0;
}
