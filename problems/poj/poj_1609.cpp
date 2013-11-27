#include <cstdio>
#include <algorithm>
#define N 10001
using namespace std;

struct node{ int x,y; }no[N];
int cmp(node a,node b){ return a.x==b.x?a.y<b.y:a.x<b.x; }
int id[N],top;

int solve(int n)
{
	top=0;
	int l,r,mid;
	for(int i=0; i<n; i++)
	{
		l=0,r=top-1;
		for(; l<=r;)
		{
			mid=(l+r)>>1;
			if(no[id[mid]].y<=no[i].y)
				l=mid+1;
			else
				r=mid-1;
		}
		id[l]=i;
		top=(l>=top)?l+1:top;
	}
	return top;
}

int main()
{
	int n;
	while(scanf("%d",&n)&&n)
	{
		for(int i=0; i<n; i++)
			scanf("%d%d",&no[i].x,&no[i].y);
		sort(no,no+n,cmp);
		printf("%d\n",solve(n));
	}
	puts("*");
	return 0;
}
