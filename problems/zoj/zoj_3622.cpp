#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long LL;
LL B(int i){ return 1LL<<i; }
LL five[40];

int cal(int n)
{
	int ret=0;
	for(int i=0; five[i]<=n; i++)
	{
		for(int j=max(i-3,0); j<=i+1; j++)
		{
			if(five[i]*B(j)<=n)
				ret++;
			else
				break;
		}
	}
	return ret;
}

int main()
{
	five[0]=1;
	for(int i=1; i<40; i++)
		five[i]=5*five[i-1];
	int l,r;
	while(scanf("%d%d",&l,&r)+1)
		printf("%d\n",cal(r)-cal(l-1));
	return 0;
}
