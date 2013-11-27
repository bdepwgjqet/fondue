#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 300100

typedef long long LL;
using namespace std;

struct edge{ int f,t,n,c; }e[N<<1];
int val[N],top,list[N];
LL res;

int cmp(int a,int b){ return e[a].c<e[b].c; }

void insert(int f,int t,int c)
{
	e[top].f=f,e[top].t=t,e[top].c=c;
	e[top].n=list[f],list[f]=top++;
}

void dfs(int now,int p,int pc,LL &nowc,LL &nows)
{
	vector<int> es;
	vector<LL> cc,ss;
	for(int i=list[now]; i!=-1; i=e[i].n)
	{
		if(e[i].t==p)
			continue;
		es.push_back(i);
	}
	sort(es.begin(),es.end(),cmp);
	LL nextc,nexts,sum=0,cnt=0;
	nowc=0,nows=0;
	int pre=-1;
	for(int i=0; i<es.size(); i++)
	{
		int ii=es[i];
		int to=e[ii].t,c=e[ii].c;
		dfs(to,now,c,nextc,nexts);
		if(c!=pc)
			nowc+=nextc+1,nows+=nextc*val[now]+val[to]+val[now]+nexts;
		cnt+=nextc+1,sum+=nexts+val[to];
		if(c!=pre)
		{
			cc.push_back(nextc+1);
			ss.push_back(nexts+val[to]);
		}
		else
		{
			int n=cc.size();
			cc[n-1]+=nextc+1;
			ss[n-1]+=nexts+val[to];
		}
		pre=c;
	}
	LL r1=0,r2=0;
	for(int i=0; i<cc.size(); i++)
	{
		r1+=cc[i]*val[now]+ss[i];
		r2+=(cnt-cc[i])*ss[i]+cc[i]*(sum-ss[i])+(cnt-cc[i])*cc[i]*val[now];
	}
	res+=r1+r2/2;
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		top=0;
		for(int i=0; i<n; i++)
		{
			scanf("%d",&val[i]);
			list[i]=-1;
		}
		for(int i=0; i<n-1; i++)
		{
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			x--,y--;
			insert(x,y,z);
			insert(y,x,z);
		}
		LL cnt,sum;
		res=0;
		dfs(0,-1,-1,cnt,sum);
		//printf("%lld\n",res);
		printf("%I64d\n",res);
	}
	return 0;
}
