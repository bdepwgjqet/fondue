#include <cstdio>
#include <algorithm>
#include <cstring>
#define N 3012501
#define M 500001
using namespace std;

int vis[N],ret[N];

void init()
{
	int val=0;
	ret[0]=0;
	vis[0]=1;
	memset(vis,0,sizeof(vis));
	int x;
	for(int i=1; i<M; i++)
	{
		x=ret[i-1]-i;
		if(x>0&&!vis[x])
			vis[x]=1,ret[i]=x;
		else
			x=ret[i-1]+i,ret[i]=x,vis[x]=1;
		val=max(val,x);
	}
}

int main()
{
	int n;
	init();
	while(scanf("%d",&n))
	{
		if(n<0)
			break;
		printf("%d\n",ret[n]);
	}
	return 0;
}
