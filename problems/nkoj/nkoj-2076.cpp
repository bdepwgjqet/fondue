#include <cstdio>
#include <algorithm>
#include <cstring>
#define N 101

using namespace std;

char dp[N][N][9][1<<8];
int dat[N],tst;
int n,k;

inline int B(int i){ return 1<<i; }

inline int get(int x)
{
	int ret=0;
	for(int i=0; i<8; i++)
		if(tst&B(i))
			if((x&B(i))==0)
				ret++;
	return ret;
}

int dfs(int id,int tk,int pre,int st)
{
	if(dp[id][tk][pre][st]>=0) return dp[id][tk][pre][st];
	if(id==n)
		return dp[id][tk][pre][st]=get(st);
	int ret=N;
	if(tk==k)
		ret=dfs(id+1,tk,dat[id],st|B(dat[id]))+(dat[id]!=pre);
	else
	{
		ret=min(ret,dfs(id+1,tk,dat[id],st|B(dat[id]))+(dat[id]!=pre));
		ret=min(ret,dfs(id+1,tk+1,pre,st));
	}
	return dp[id][tk][pre][st]=ret;
}

int main()
{
	int ca=1;
	while(scanf("%d%d",&n,&k)+1)
	{
		if(n==0&&k==0) break;
		tst=0;
		for(int i=0; i<n; i++)
		{
			scanf("%d",&dat[i]);
			dat[i]-=25;
			tst|=B(dat[i]);
		}
		memset(dp,-1,sizeof(dp));
		printf("Case %d: %d\n\n",ca++,dfs(0,0,8,0));
	}
	return 0;
}
