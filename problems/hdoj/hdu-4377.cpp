#include <cstdio>
#include <cmath>
#define N 100011

int ret[N];

void solve(int n)
{
	if(n==1)
	{
		ret[1]=1;
		return;
	}
	else if(n==2)
	{
		ret[1]=1,ret[2]=2;
		return;
	}
	int a=(int)sqrt(1.0*n),b,cnt,id,now,sum;
	if(a*a==n)
		b=a;
	else
		b=a+1;
	sum=n/b;
	if(sum*b==n&&sum<b)
		sum--;
	id=n-b+1,now=n;
	for(cnt=0; cnt<sum; cnt++)
	{
		for(int i=0; i<b; i++)
			ret[id+i]=now-i;
		now-=b;
		id-=b;
	}
	int y=b-sum,z=n-sum*b;
	for(int i=1; i<=y-1; i++)
		ret[i]=i;
	int j=0;
	for(int i=y; i<=z; i++,j++)
		ret[i]=z-j;
}

void show(int n)
{
	printf("%d",ret[1]);
	for(int i=2; i<=n; i++)
		printf(" %d",ret[i]);
	puts("");
}

int main()
{
	int n,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		solve(n);
		show(n);
	}
	return 0;
}
