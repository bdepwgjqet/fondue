#include <cstdio>
#include <algorithm>
#define inf 1000000

using namespace std;

int main()
{
	int n,k,x,ret;
	while(scanf("%d%d",&n,&k)+1)
	{
		ret=0;
		x=inf;
		for(int i=0; i<n; i++)
		{
			int y;
			scanf("%d",&y);
			if(k>0)
			{
				if(y<0)
				{
					ret-=y,k--;
					x=min(x,-y);
				}
				else
				{
					ret+=y;
					x=min(x,y);
				}
			}
			else
				ret+=y;
		}
		if(k&1)
			ret-=2*x;
		printf("%d\n",ret);
	}
	return 0;
}
