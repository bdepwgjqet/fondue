#include <cstdio>
#include <algorithm>
#define inf 1000000
#define N 100010

using namespace std;

int dat[N];

int cmp(int a,int b){ return a>b; }

int main()
{
	int n,m,x;
	while(scanf("%d",&m)+1)
	{
		x=inf;
		for(int i=0; i<m; i++)
		{
			int y;
			scanf("%d",&y);
			x=min(x,y);
		}
		scanf("%d",&n);
		int ret=0;
		for(int i=0; i<n; i++)
			scanf("%d",&dat[i]);
		sort(dat,dat+n,cmp);
		for(int i=0; i<n; i++)
			if(i%(x+2)<x)
				ret+=dat[i];
		printf("%d\n",ret);
	}
	return 0;

}
