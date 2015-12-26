#include <cstdio>
#define N 100011

int dat[N],n,q[N];

int solve()
{
	int l,r,ret=0,mid;
	for(int i=1; i<=n; i++)
	{
		l=1,r=ret;
		for(; l<=r; )
		{
			mid=(l+r)>>1;
			if(q[mid]>dat[i])
				l=mid+1;
			else
				r=mid-1;
		}
		if(l>ret)
			ret++;
		q[l]=dat[i];
	}
	return ret;
}

int main()
{
	int x,ca=1;
	while(scanf("%d",&x)!=EOF)
	{
		if(x==-1)
			break;
		if(ca>1)
			puts("");
		printf("Test #%d:\n",ca++); 
		dat[n=1]=x;
		for(; scanf("%d",&x); )
		{
			if(x==-1)
				break;
			dat[++n]=x;
		}
		printf("  maximum possible interceptions: %d\n",solve());

	}
	return 0;
}
