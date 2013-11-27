#include <cstdio>
#include <algorithm>
#include <map>
#define N 101

using namespace std;
typedef long long LL;

int n,x;
int w[N];
int cmp(int a,int b){ return a<b; }

map<LL,int> dp;

int gao(int id,LL nw)
{
	LL ha=nw*N+id;
	if(dp.count(ha)>0)
		return dp[ha];
	if(id==n) return dp[ha]=0;
	
	if(nw>w[id])
		return dp[ha]=gao(id+1,nw+w[id]);
	if(nw<=1)
		return dp[ha]=n-id;
	int ret=gao(id+1,nw)+1,c=0;
	LL nex=nw;
	for(; nex<=w[id]; c++)
	{
		nex+=nex-1;
	}
	ret=min(ret,gao(id+1,nex+w[id])+c);
	return dp[ha]=ret;
}

int main()
{
	int T;
	scanf("%d",&T);
	for(int ca=1; ca<=T; ca++)
	{
		printf("Case #%d: ",ca);
		scanf("%d%d",&x,&n);
		//printf("%d %d\n",x,n);
		for(int i=0; i<n; i++)
		{
			scanf("%d",&w[i]);
			//printf("%d ",w[i]);
		}
	//	puts("");
		sort(w,w+n,cmp);
		dp.clear();
		printf("%d\n",gao(0,x));
	}
	return 0;
}
