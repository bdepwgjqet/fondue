#include <cstdio>
#include <algorithm>
#define N 1011

using namespace std;

struct node{ int c,i; }no[N];

int cmp(node a,node b){ return a.c<b.c; }
int n;

int ok(int i)
{
	for(int j=i+1; j<n; j++)
		if(no[j].c<=i+2)
			return 0;
	return 1;
}

int main()
{
	while(scanf("%d",&n)+1)
	{
		for(int i=0; i<n; i++)
		{
			scanf("%d",&no[i].c);
			no[i].i=i+1;
		}
		sort(no,no+n,cmp);
		int ret=0;
		for(int i=0; i<n; i++)
		{
			if(no[i].c<=i+1)
			{
				if(ok(i))
					ret++;
			}
		}
		printf("%d\n",ret);
		for(int i=0; i<n; i++)
		{
			if(no[i].c<=i+1)
			{
				if(ok(i))
				{
					printf("%d",i+1);
					for(int j=0; j<=i; j++)
						printf(" %d",no[j].i);
					puts("");
				}
			}
		}
	}
	return 0;
}
