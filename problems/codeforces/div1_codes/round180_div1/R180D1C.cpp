#include <cstdio>
#define N 100010

struct node{ int v,i; }no[N];
int a[N],b[N],tag[N];

int cmp(node a,node b){ return a.v<b.v; }

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0; i<n; i++)
	{
		scanf("%d",&no[i].v);
		no[i].i=i;
	}
	sort(no,no+n,cmp);
	for(int i=1; i<n; i++)
	{
		if(no[i].v==no[i-1].v+1)
			tag[i]=1;
	}
	int ai=-1,bi=-1;
	for(int i=0; i<n; i++)
	{
		int x=no[i].v,id=no[i].i;
		if(tag[i]) 
		{
		}
		else 
		{
			if(ai==-1)
			{
				ai=x/2;
				bi=x-ai;
			}
			else
				ai++,bi-x-ai;
			a[id]=ai;
			b[id]=bi;
		}
	}
	return 0;
}
