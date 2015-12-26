#include <cstdio>
#include <cstring>
#include <algorithm>

typedef long long LL;
using namespace std;

int ans[2][2];
int sig(int x){ return x<0?1:0; }

int gcd(int a,int b,LL &x,LL &y)
{
	if(!b) return x=1,y=0,a;
	int g=gcd(b,a%b,y,x);
	y-=a/b*x;
	return g;
}

int main()
{
	int a,b,p,k;
	scanf("%d%d%d%d",&a,&b,&p,&k);
	LL x,y,z,r1,r2;
	int g=gcd(a,b,x,y);
	if(p%g)
	{
		puts("NO");
		return 0;
	}
	p/=g,a/=g,b/=g;
	r1=x*p,r2=y*p;
	int tag=0;
	if(a<b)
	{
		tag=1;
		swap(a,b);
		swap(r1,r2);
	}
	LL t=r2/a;
	r1=r1+t*b;
	r2=r2-t*a;
	int fd=0;
	for(int i=-10; i<=10; i++)
	{
		x=r1+i*b;
		y=r2-i*a;
		z=abs(x)+abs(y);
		if((z<=k)&&((k-z)&1)==0)
		{
			fd=1;
			break;
		}
	}
	if(fd)
	{
		if(tag)
			swap(x,y);
		puts("YES");
		memset(ans,0,sizeof(ans));
		ans[0][sig(x)]=(int)abs(x);
		ans[1][sig(y)]=(int)abs(y);
		ans[0][0]+=(k-z)/2,ans[0][1]+=(k-z)/2;
		printf("%d %d %d %d\n",ans[0][0],ans[0][1],ans[1][0],ans[1][1]);
	}
	else
		puts("NO");
	return 0;
}
