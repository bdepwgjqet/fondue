#include <cstdio>
#define N 50011

inline int low_bit(int i){ return i&(-i); }
int dat[N];
int ans[N];

int get(int x)
{
	int ret=0;
	for(; x; x^=low_bit(x))
		ret+=dat[x];
	return ret;
}

void update(int x,int tag)
{
	for(; x<N; x+=low_bit(x))
		dat[x]+=tag;
}

int main()
{
	int n;
	while(scanf("%d",&n)+1)
	{
		for(int i=1; i<=n; i++)
			update(i,1);
		for(int i=1; i<=n; i++)
		{
			int x,l,r,mid;
			scanf("%d",&x);
			l=1,r=n;
			for(; l<=r;)
			{
				mid=(l+r)>>1;
				if(get(mid)>=x)
					r=mid-1;
				else
					l=mid+1;
			}
			update(l,-1);
			ans[i]=l;
		}
		int m;
		scanf("%d",&m);
		for(int i=0; i<m; i++)
		{
			int x;
			scanf("%d",&x);
			printf("%d",ans[x]);
			if(i+1<m)
				printf(" ");
		}
		puts("");
	}
	return 0;
}
