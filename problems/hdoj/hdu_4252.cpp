#include <cstdio>
#include <set>
using namespace std;
#define N 100010

int st[N];

int main()
{
	int n,ret,x,ca=1,top;
	while(scanf("%d",&n)!=EOF)
	{
		printf("Case %d: ",ca++);
		top=0,ret=0;
		for(int i=0; i<n; i++)
		{
			scanf("%d",&x);
			if(x==0)
			{
				ret+=top;
				top=0;
				continue;
			}
			if(top==0)
			{
				st[top++]=x;
				continue;
			}
			if(st[top-1]>=x)
			{
				for(; top>0&&st[top-1]>=x; )
				{
					if(st[top-1]>x) ret++;
					top--;
				}
				st[top++]=x;
			}
			else
				st[top++]=x;
		}
		ret+=top;
		printf("%d\n",ret);
	}
	return 0;
}
