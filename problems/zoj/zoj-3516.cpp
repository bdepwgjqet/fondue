#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#define N 10011

using namespace std;

int val[N];
vector<int> tr[N];

int dp[N][3],cnt[N],cc[N],q[10];
int cmp(int a,int b){ return a>b; }

void dfs(int now,int p)
{
	cnt[now]=cc[now]=1;
	dp[now][0]=val[now];
	for(int i=0; i<tr[now].size(); i++)
	{
		int to=tr[now][i];
		if(to==p) continue;
		dfs(to,now);
		cnt[now]+=cnt[to];
		int top=0;
		for(int j=0; j<cc[to]; j++)
			q[top++]=dp[to][j];
		for(int j=0; j<cc[now]; j++)
			q[top++]=dp[now][j];
		sort(q,q+top,cmp);
		for(int j=0; j<top&&j<3; j++)
			dp[now][j]=q[j];
		cc[now]=min(3,top);
	}
}

int main()
{
	int n;
	while(scanf("%d",&n)+1)
	{
		for(int i=0; i<n; i++)
			tr[i].clear();
		scanf("%d",&val[0]);
		for(int i=1; i<n; i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			val[i]=y;
			tr[i].push_back(x);
			tr[x].push_back(i);
		}
		memset(cnt,0,sizeof(cnt));
		memset(cc,0,sizeof(cc));
		dfs(0,-1);
		int m;
		scanf("%d",&m);
		for(int i=0; i<m; i++)
		{
			int x;
			scanf("%d",&x);
			if(cc[x]<3)
				puts("-1");
			else
			{
				printf("%d",dp[x][0]);
				for(int j=1; j<3; j++)
					printf(" %d",dp[x][j]);
				puts("");
			}
		}
	}
	return 0;
}
