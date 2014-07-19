#include <cstdio>
#include <algorithm>
#include <cstring>
#define N 5011
using namespace std;

int dat[N<<1],bit[N];

inline int lowbit(int i){ return (-i)&i; }

void update(int x,int v)
{
	for(; x<N; x+=lowbit(x))
		bit[x]+=v;
}

int cal(int x)
{
	int ret=0;
	for(; x; x-=lowbit(x))
		ret+=bit[x];
	return ret;
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		memset(bit,0,sizeof(bit));
		for(int i=1; i<=n; i++)
		{
			scanf("%d",&dat[i]);
			dat[i]++;
		}
		int ret,cnt=0,pre;
		for(int i=n; i>=1; i--)
		{
			cnt+=cal(dat[i]);
			update(dat[i],1);
		}
		ret=pre=cnt;
		for(int i=1; i<n; i++)
		{
			cnt=pre;
			update(dat[i],-1);
			cnt-=cal(dat[i]);
			cnt+=cal(n)-cal(dat[i]);
			update(dat[i],1);
			pre=cnt;
			ret=min(ret,cnt);
		}
		printf("%d\n",ret);
	}
	return 0;
}
