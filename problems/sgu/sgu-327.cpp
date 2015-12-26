#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
#define N 14
#define S 1<<14
#define inf 0x3fffffff

using namespace std;

string ts[N],s[N];
string ans;
int n,len[N][N][2][2],ST,dp[N][S][2],vis[N];
int next[N][S][2];

inline int B(int i){ return 1<<i; }

string reverse(string a)
{
	string ret=a;
	reverse(ret.begin(),ret.end());
	return ret;
}

void delrep(int tn)
{
	string tmp;
	memset(vis,0,sizeof(vis));
	for(int i=0; i<tn; i++)
	{
		int tag=0;
		tmp=reverse(ts[i]);
		for(int j=0; j<tn; j++)
		{
			if(vis[j]) continue;
			if(i==j) continue;
			if(ts[j].find(ts[i])!=string::npos)
			{
				tag=1;
				break;
			}
			if(ts[j].find(tmp)!=string::npos)
			{
				tag=1;
				break;
			}
		}
		if(tag)
			vis[i]=1;
	}
	n=0;
	for(int i=0; i<tn; i++)
		if(!vis[i])
			s[n++]=ts[i];
}

int get(string a,string b)
{
	int ret=0,l=min(b.length(),a.length());
	for(int i=1; i<=l; i++)
		if(a.substr(0,i)==b.substr(b.length()-i,i))
			ret=i;
	return ret;
}

void getlen()
{
	memset(len,0,sizeof(len));
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(i==j)
			{
				len[i][i][0][0]=2*s[i].length()-get(reverse(s[i]),s[i]);
				len[i][i][1][1]=2*s[i].length()-get(s[i],reverse(s[i]));
			}
			else
			{
				len[i][j][0][0]=2*s[j].length()-2*get(s[i],s[j]);
				len[i][j][0][1]=2*s[j].length()-2*get(s[i],reverse(s[j]));
				len[i][j][1][0]=2*s[j].length()-2*get(reverse(s[i]),s[j]);
				len[i][j][1][1]=2*s[j].length()-2*get(reverse(s[i]),reverse(s[j]));
			}
		}
	}
}

void dfs(int now,int st)
{
	if(dp[now][st][0]>=0)
		return;
	dp[now][st][0]=dp[now][st][1]=inf;
	if(st==ST)
	{
		dp[now][st][0]=0;
		dp[now][st][1]=0;
		return;
	}
	for(int i=0; i<n; i++)
	{
		if((st&B(i))==0)
		{
			dfs(i,st+B(i));
			int x=dp[i][st+B(i)][0]+len[now][i][0][0];
			if(x<dp[now][st][0])
			{
				dp[now][st][0]=x;
				next[now][st][0]=i;
			}
			x=dp[i][st+B(i)][1]+len[now][i][0][1];
			if(x<dp[now][st][0])
			{
				dp[now][st][0]=x;
				next[now][st][0]=i+n;
			}
			x=dp[i][st+B(i)][0]+len[now][i][1][0];
			if(x<dp[now][st][1])
			{
				dp[now][st][1]=x;
				next[now][st][1]=i;
			}
			x=dp[i][st+B(i)][1]+len[now][i][1][1];
			if(x<dp[now][st][1])
			{
				dp[now][st][1]=x;
				next[now][st][1]=n+i;
			}
		}
	}
}

string connect(string a,string b)
{
	string ret=a;
	int l=0,ml=min(a.length(),b.length());
	for(int i=1; i<=ml; i++)
		if(a.substr(a.length()-i,i)==b.substr(0,i))
			l=i;
	ret+=b.substr(l,b.length()-l);
	return ret;
}

void show(int now,int st,int tag)
{
	if(tag==0)
	{
		ans=connect(s[now],ans);
		ans=connect(ans,reverse(s[now]));
	}
	else
	{
		ans=connect(reverse(s[now]),ans);
		ans=connect(ans,s[now]);
	}
	if(st==ST)
		return;
	int nx=next[now][st][tag],nt;
	nt=nx/n,nx=nx%n;
	show(nx,st+B(nx),nt);
}

void gao()
{
	memset(dp,-1,sizeof(dp));

	for(int i=0; i<n; i++)
	{
		dfs(i,B(i));
		dp[i][0][0]=inf;
		int x=dp[i][B(i)][0]+len[i][i][0][0];
		if(x<dp[i][0][0])
		{
			dp[i][0][0]=x;
			next[i][0][0]=0;
		}
		x=dp[i][B(i)][1]+len[i][i][1][1];
		if(x<dp[i][0][0])
		{
			dp[i][0][0]=x;
			next[i][0][0]=1;
		}
	}
	int ret=inf,id=-1;
	for(int i=0; i<n; i++)
	{
		if(ret>dp[i][0][0])
			ret=dp[i][0][0],id=i;
	}
	ans=string("");
	show(id,B(id),next[id][0][0]);
	cout<<ans<<endl;
	if(ans.length()!=ret)
		for(;;);
}

int main()
{
	int tn;
	while(scanf("%d",&tn)+1)
	{
		for(int i=0; i<tn; i++)
			cin>>ts[i];
		delrep(tn);
		ST=B(n)-1;
		getlen();
		gao();
	}
	return 0;
}
