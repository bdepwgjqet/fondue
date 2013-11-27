#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
#define N 511
using namespace std;

map<int,int> mp;
map<int,int>::iterator it;

int dp[N];

struct node{ int l,r,c; }qu[N];
int cmp(node a,node b){ return a.r==b.r?a.l<b.l:a.r<b.r; }

int main()
{
	int ret=0,n;
	while(scanf("%d",&n)!=EOF)
	{
		int a,b,l,r;
		mp.clear();
		for(int i=0; i<n; i++)
		{
			scanf("%d%d",&a,&b);
			l=a+1;
			r=n-b;
			if(l>r) 
				continue;
			mp[l*N+r]++;
		}
		int top=0;
		for(it=mp.begin(); it!=mp.end(); it++)
		{
			l=it->first/N,r=it->first%N;
			qu[top].l=l,qu[top].r=r;
			qu[top].c=(r-l+1)>(it->second)?it->second:r-l+1;
			top++;
		}
		sort(qu,qu+top,cmp);
		memset(dp,0,sizeof(dp));
		for(int i=0; i<top; i++)
		{
			dp[qu[i].r]=max(dp[qu[i].r],dp[qu[i].l-1]+qu[i].c);
			for(int j=qu[i].r; j<=n; j++)
				dp[j]=max(dp[j],dp[qu[i].r]);
		}
		printf("%d\n",dp[n]);
	}
	return 0;
}
