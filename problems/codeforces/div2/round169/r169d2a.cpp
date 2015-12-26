#include <cstdio>
#include <algorithm>
#define inf 0x3fffffff

using namespace std;

int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	int ret=-inf;
	for(int i=0; i<n; i++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		if(r>k)
			ret=max(ret,l-(r-k));
		else
			ret=max(ret,l);
	}
	printf("%d\n",ret);
	return 0;
}
