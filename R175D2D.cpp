#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#define X 65536
#define MOD 1000000007

using namespace std;
typedef long long LL;

/*
map<LL,LL> dp;
int n;

inline int B(int i){ return 1<<i; }

LL dfs(int id,int sa,int sb)
{
	LL st=1LL*id*X*X+1LL*sa*X+1LL*sb;
	if(dp.count(st)>0)
		return dp[st];
//	printf("%d %d %d=>\n",id,sa,sb);
	if(id==n) return dp[st]=1;
	LL ret=0;
	for(int i=0; i<n; i++)
	{
		if(sa&B(i))
			continue;
		int x=(id+i)%n;
		if(sb&B(x)) continue;
		ret=(ret+dfs(id+1,sa|B(i),sb|B(x)))%MOD;
	}
	return dp[st]=ret;
}
*/

LL p[16]={
	1,0,3,0,15,0,133,0,2025,0,37851,0,1030367,0,36362925,0
};

LL jie[17];

int main()
{
	jie[1]=1;
	for(int i=2; i<17; i++)
		jie[i]=jie[i-1]*i%MOD;
	int n;
	scanf("%d",&n);
	cout<<jie[n]*p[n-1]%MOD<<endl;
	return 0;
}
