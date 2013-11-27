#include <cstdio>
#include <algorithm>
#include <iostream>
#include <set>
#define N 10001
#define MOD 100000007
typedef long long LL;
using namespace std;

set<pair<int,int> > st;
LL cnt[N];

void init()
{
	cnt[2]=1,cnt[1]=1;
	cnt[0]=0;
	for(int i=3; i<N; i++)
		cnt[i]=cnt[i-2]+(i+1)/2;
}

int ok(int x,int y,int n)
{
	int t,nx=x,ny=n-y+1;
	for(int i=0; i<4; i++)
	{
		if(st.count(make_pair(x,y))>0)
			return 1;
		t=x,x=y,y=n-t+1;
	}
	for(int i=0; i<4; i++)
	{
		if(st.count(make_pair(nx,ny))>0)
			return 1;
		t=nx,nx=ny,ny=n-t+1;
	}
	return 0;
}

LL solve(LL b,LL a)
{
	LL ret=1;
	for(; b;)
	{
		if(b&1)
			ret=(ret*a)%MOD;
		a=(a*a)%MOD;
		b>>=1;
	}
	return ret;
}

int main()
{
	int n,m,k,x,y;
	init();
	while(scanf("%d%d%d",&n,&m,&k)!=EOF)
	{
		st.clear();
		for(int i=0; i<m; i++)
		{
			scanf("%d%d",&x,&y);
			x++,y++;
			if(ok(x,y,n))
				continue;
			else
				st.insert(make_pair(x,y));
		}
		cout<<solve(cnt[n]-st.size(),(LL)k)<<endl;
	}
	return 0;
}
