#include <cstdio>
#include <algorithm>
#define N 10001
using namespace std;
typedef long long LL;

LL dat[N];
int cmp(LL a,LL b){ return a<b; }

int main()
{
	int n;
	LL ret;
	while(scanf("%d",&n)!=EOF)
	{
		int x;
		for(int i=1; i<=n; i++)
		{
			scanf("%d",&x);
			dat[i]=x;
		}
		sort(dat+1,dat+n+1,cmp);
		dat[0]=dat[1];
		LL tmp=0;
		ret=0;
		int cnt=0;
		for(int i=1; i<=n; i++)
		{
			tmp+=cnt*(dat[i]-dat[i-1]);
			ret+=tmp;
			cnt++;
		}
		printf("%lld\n",ret<<1);
	}
	return 0;
}
