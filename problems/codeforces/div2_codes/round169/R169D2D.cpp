#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define N 70

using namespace std;
typedef long long LL;

LL dp[N][2][2][2];
int lx[N],rx[N],n;

inline LL B(int i){ return 1LL<<i; }

LL gao(int id,int a,int b,int c)
{
	if(dp[id][a][b][c]>=0)
		return dp[id][a][b][c];
	if(id==n) 
		return dp[id][a][b][c]=0;
	LL ret=0;
	if((a||lx[id]==0))
		ret=max(ret,gao(id+1,a,b,rx[id]==1?1:0));
	if((a||lx[id]==0)&&(c||rx[id]==1))
		ret=max(ret,gao(id+1,a,1,c)+B(n-id-1));
	if(b)
		ret=max(ret,gao(id+1,lx[id]==0?1:0,b,rx[id]==1?1:0)+B(n-id-1));
	if(c||rx[id]==1)
		ret=max(ret,gao(id+1,lx[id]==0?1:0,b,c));
	return dp[id][a][b][c]=ret;
}

int gen(LL x,int a[])
{
	int ret=0;
	for(; x; x>>=1)
		a[ret++]=x&1;
	return ret;
}

int main()
{
	LL l,r;
	memset(dp,-1,sizeof(dp));
	cin>>l>>r;
	n=gen(r,rx);
	reverse(rx,rx+n);
	for(int i=n-1; i>=0; i--)
		lx[i]=(l&1),l>>=1;
	cout<<gao(0,0,0,0)<<endl;
	return 0;
}
