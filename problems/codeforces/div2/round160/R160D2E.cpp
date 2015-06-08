#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>
#define N 50

using namespace std;
typedef long long LL;

vector<int> v;
LL dp[N][N][2];

int ok(LL x)
{
	int ret=0;
	for(; x>1;)
	{
		if(x&1)
			return 0;
		x>>=1;
		ret++;
	}
	return ret+1;
}

LL dfs(int id,int c,int tag,int need)
{
	if(dp[id][c][tag]>=0) return dp[id][c][tag];
	LL ret=0;
	if(id==v.size())
	{
		if(c==need) ret=1;
		else ret=0;
		return dp[id][c][tag]=ret;
	}
	if(tag)
	{
		ret+=dfs(id+1,c,tag,need);
		if(c<need)
			ret+=dfs(id+1,c+1,tag,need);
	}
	else
	{
		if(v[id]==1)
		{
			ret+=dfs(id+1,c,1,need);
			if(c<need)
				ret+=dfs(id+1,c+1,tag,need);
		}
		else
			ret+=dfs(id+1,c,tag,need);
	}
	return dp[id][c][tag]=ret;
}

void gao(int cnt,LL n)
{
	v.clear();
	for(; n; n>>=1)
		v.push_back(n&1);
	reverse(v.begin(),v.end());
	memset(dp,-1,sizeof(dp));
	cout<<dfs(0,0,0,cnt)-(cnt==1)<<endl;
}

int main()
{
	LL n,t;
	while(cin>>n>>t)
	{
		int cnt=ok(t);
		if(cnt)
		{
			gao(cnt,n+1);
		}
		else
			puts("0");
	}
	return 0;
}
