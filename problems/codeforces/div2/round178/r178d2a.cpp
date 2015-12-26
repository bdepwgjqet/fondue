#include <cstdio>

int dat[111];

int main()
{
	int n,m;
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		scanf("%d",&dat[i]);
	scanf("%d",&m);
	for(int i=0; i<m; i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(x-1>0)
			dat[x-1]+=y-1;
		if(x+1<=n)
			dat[x+1]+=dat[x]-y;
		dat[x]=0;
	}
	for(int i=1; i<=n; i++)
		printf("%d\n",dat[i]);
	return 0;
}
