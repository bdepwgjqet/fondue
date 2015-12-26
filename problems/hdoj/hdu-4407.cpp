#include <cstdio>
#include <map>
#include <vector>
#define N 400100

using namespace std;
typedef long long LL;

int p[N],plist[N],top;
vector<int> fac;
map<int,int> mp;
map<int,int>::iterator it;

void init()
{
	top=0;
	for(int i=0; i<N; i++)
		p[i]=i;
	for(int i=2; i<N; i++)
	{
		if(p[i]==i)
			plist[top++]=i;
		for(int j=0; j<top&&plist[j]*i<N; j++)
		{
			p[plist[j]*i]=plist[j];
			if(i%plist[j]==0)
				break;
		}
	}
}

LL f(int n)
{
	return 1LL*n*(n+1)/2;
}

void dfs(int id,int x,int n,int sz,LL &ret,int sig)
{
	if(id==sz)
	{
		ret+=sig*x*f(n/x);
		return;
	}
	dfs(id+1,x,n,sz,ret,sig);
	dfs(id+1,x*fac[id],n,sz,ret,-sig);
}

int gcd(int a,int b){ return b?gcd(b,a%b):a; }

LL solve(int n,int c)
{
	int cc=c;
	if(n==0)
		return 0;
	LL ret=0;
	fac.clear();
	for(; c>1; )
	{
		fac.push_back(p[c]);
		int x=p[c];
		for(; c%x==0;)
			c/=x;
	}
	dfs(0,1,n,fac.size(),ret,1);
	c=cc;
	for(it=mp.begin(); it!=mp.end(); it++)
	{
		if(it->first>n)
			break;
		int x=it->first,y=it->second;
		int g=gcd(y,c),g2=gcd(x,c);
	//	printf("%d %d %d %d %d\n",x,y,g,g2,c);

		if(g2>1)
			;
		else
			ret-=x;

		if(g>1)
			;
		else
			ret+=y;
	}
	return ret;
}

int main()
{
	int n,m,t;
	init();
	scanf("%d",&t);
	while(scanf("%d%d",&n,&m)!=EOF,t--)
	{
		mp.clear();
		for(int i=0; i<m; i++)
		{
			int tag,x,c,y;
			scanf("%d",&tag);
			if(tag==2)
			{
				scanf("%d%d",&x,&c);
				mp[x]=c;
			}
			else
			{
				scanf("%d%d%d",&x,&y,&c);
				printf("%I64d\n",solve(y,c)-solve(x-1,c));
				//printf("%lld\n",solve(y,c)-solve(x-1,c));
			}
		}
	}
	return 0;
}
