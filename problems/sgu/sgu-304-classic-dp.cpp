#include <cstdio>
#include <cstring>
#include <vector> 
#define inf 0x3ffffff
#define N 1222

using namespace std;

int val[N],cnt[N],n,k,p;
int vv[N],cc[N],top,next[N];
vector<int> li[N];
vector<int> ans;
int dp[N][610],cho[N][610],id[N];

int dfs(int now,int lf)
{
	if(dp[now][lf]>=0) return dp[now][lf];
	if(lf==0)
		return dp[now][lf]=0;
	if(now==n+k)
		return dp[now][lf]=inf;
	int ret;
	int a=dfs(cc[now]>0?now+1:next[now],lf);
	int b=dfs(now+1,lf-cc[now])+vv[now];
	if(a>b)
		cho[now][lf]=1,ret=b;
	else
		cho[now][lf]=0,ret=a;
	return dp[now][lf]=ret;
}

void getid(int now)
{
	id[top]=now,vv[top]=val[now],cc[top++]=cnt[now];
	for(int i=0; i<li[now].size(); i++)
	{
		int to=li[now][i];
		getid(to);
	}
}

void getans(int now,int lf)
{
	if(lf==0||now==k+n) return;
	if(cho[now][lf]==1)
	{
		getans(now+1,lf-cc[now]);
		if(cc[now]>0)
			ans.push_back(now);
	}
	else
		getans(cc[now]>0?now+1:next[now],lf);
}

int main()
{
	scanf("%d%d%d",&n,&k,&p);
	memset(cnt,0,sizeof(cnt));
	for(int i=0; i<=n+k; i++)
		li[i].clear();
	for(int i=0; i<k; i++)
		scanf("%d",&val[i]);
	for(int i=0; i<n; i++)
	{
		int x;
		scanf("%d%d",&val[k+i],&x);
		cnt[k+i]=1;
		li[x-1].push_back(k+i);
	}
	memset(dp,-1,sizeof(dp));
	int pre=0;
	top=0;
	for(int i=0; i<k; i++)
	{
		getid(i);
		next[pre]=top;
		pre=top;
	}
	int ret=n+1;
	for(int i=1; i<=n; i++)
	{
		int now=dfs(0,i);
		if(now>p)
		{
			ret=i;
			break;
		}
	}
	ret--;
	printf("%d\n",ret);
	if(ret>0)
	{
		ans.clear();
		getans(0,ret);
		for(int i=0; i<ans.size()-1; i++)
			printf("%d ",id[ans[i]]-k+1);
		printf("%d\n",id[ans[ans.size()-1]]-k+1);
	}
	return 0;
}
