#include <cstdio>
#include <algorithm>
#define inf 0x3fffffff
#define N 210000
#define X 100000
using namespace std;

int now[N];

int sig(int i,int add,int ed)
{
	if(add>0)
		return i<=ed;
	else
		return i>=ed;
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int x,y;
		for(int i=0; i<N; i++)
			now[i]=-inf;
		now[X]=0;
		int st,add,ed,up=X,dn=X;
		for(int i=0; i<n; i++)
		{
			scanf("%d%d",&x,&y);
			if(x>=0)
				add=-1,st=up+x,ed=dn+x;
			else
				add=1,st=dn+x,ed=up+x;
			for(int j=st; sig(j,add,ed); j+=add)
			{
				if(now[j-x]>-inf)
				{
					now[j]=max(now[j],now[j-x]+y);
					up=max(up,j);
					dn=min(dn,j);
				}
			}
		}
		int ret=0;
		for(int i=X; i<N; i++)
			if(now[i]>=0)
				ret=max(ret,i-X+now[i]);
		printf("%d\n",ret);
	}
	return 0;
}
