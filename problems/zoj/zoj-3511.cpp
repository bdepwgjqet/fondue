#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#define N 10011
#define pii pair<int,int>

using namespace std;

pair<int,pii> seg[N];
int list[N];

int gao(int l,int r)
{
	int ret=1;
	for(; l!=r; )
		l=list[l],ret++;
	return ret;
}

int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)+1)
	{
		for(int i=0; i<n; i++)
			list[i]=i+1;
		list[n-1]=0;
		for(int i=0; i<m; i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			x--,y--;
			if(x>y) swap(x,y);
			seg[i].first=y-x;
			seg[i].second.first=x;
			seg[i].second.second=y;
			if(y-x>n+x-y)
			{
				seg[i].first=n+x-y;
				swap(seg[i].second.first,seg[i].second.second);
			}
		}

		sort(seg,seg+m);
		int ret=0,left=n,tmp;
		for(int i=0; i<m; i++)
		{
			ret=max(ret,tmp=gao(seg[i].second.first,seg[i].second.second));
			left-=tmp-2;
			list[seg[i].second.first]=seg[i].second.second;
		}
		printf("%d\n",max(ret,left));
	}
	return 0;
}
