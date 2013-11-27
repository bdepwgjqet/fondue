#include <cstdio>
#include <set>
#include <algorithm>
#include <cstring>
#define N 10001
#define S 1000001
using namespace std;

int n,k,best,retc,retid;
int dp[N],TT;
short vis[N][1025];
struct node{ int x,d,p,c,st; }q[S];

inline int B(int i){ return 1<<i; }

void solve()
{
	int l,r,nowdp;
	for(int i=0; i<N; i++)
		dp[i]=11;
	retc=k+1;
	q[l=r=0].p=-1;
	q[0].c=0,q[0].x=0,q[0].d=0,q[0].st=0;
	for(; l<=r; l++)
	{
		node now=q[l],next;
		if(now.c>=retc)
			continue;
		if(now.c>dp[now.x])
			continue;
		if(now.x==0&&now.p!=-1)
			continue;
		for(int i=0; i<k; i++)
		{
			if(i==0&&now.p==-1)
				continue;
			next.x=(now.x*k+i)%n;
			next.d=i;
			next.p=l;
			if(now.st&B(i))
			{
				next.c=now.c;
				next.st=now.st;
			}
			else
			{
				next.c=now.c+1;
				next.st=now.st+B(i);
			}
			if(next.c>=retc)
				continue;
			if(next.c>dp[next.x])
				continue;
			if(vis[next.x][next.st]==TT)
				continue;
			vis[next.x][next.st]=TT;
			q[++r]=next;
			dp[next.x]=min(dp[next.x],next.c);
			if(next.x==0)
			{
				if(next.c<retc)
				{
					retc=next.c;
					retid=r;
				}
			}
		}
	}
}

void show(int i)
{
	if(q[i].p==-1)
		return;
	show(q[i].p);
	printf("%d",q[i].d);
}

int main()
{
	memset(vis,0,sizeof(vis));
	TT=0;
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		TT++;
		solve();
		show(retid);
		puts("");
	}
	return 0;
}
