#include <cstdio>
#include <cmath>
#include <algorithm>
#define N 100101
typedef long long LL;
using namespace std;

LL sum[N];
int q[N];

int main()
{
	int n,f;
	while(scanf("%d%d",&n,&f)!=EOF)
	{
		int x;
		sum[0]=0;
		for(int i=1; i<=n; i++)
		{
			scanf("%d",&x);
			x*=1000;
			sum[i]=sum[i-1]+x;
		}
		LL ret=0;
		int l,r,next;
		q[l=r=0]=0;
		for(int i=f; i<=n; i++)
		{
			for(; l<r; )
			{
				if((sum[i]-sum[q[l+1]])*(i-q[l])>(sum[i]-sum[q[l]])*(i-q[l+1]))
					l++;
				else
					break;
			}
			ret=max(ret,(sum[i]-sum[q[l]])/(i-q[l]));
			next=i-f+1;
			for(; l<r; )
			{
				if((sum[next]-sum[q[r]])*(q[r]-q[r-1])<=(next-q[r])*(sum[q[r]]-sum[q[r-1]]))
					r--;
				else
					break;
			}
			q[++r]=next;
		}
		printf("%lld\n",ret);
	}
	return 0;
}
