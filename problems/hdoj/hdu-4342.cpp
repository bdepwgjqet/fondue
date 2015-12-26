#include <cstdio>
#include <cmath>
#include <iostream>
typedef long long LL;
using namespace std;

const LL N=(1LL<<32LL);
LL dat[100000];

void init()
{
	dat[0]=0;
	for(LL i=1; i<100000; i++)
	{
		dat[i]=dat[i-1]+(2*i+1)*i;
	}
}

LL get(LL x)
{
	LL l=2,r=N,mid,tmp;
	for(; l<=r;)
	{
		mid=(l+r)>>1;
		tmp=(LL)sqrt(double(mid));
		if(mid-tmp>x)
			r=mid-1;
		else
			l=mid+1;
	}
	tmp=(LL)sqrt(double(r));
	if(tmp*tmp==r)
		return r-1;
	return r;
}

int main()
{
	int t;
	LL n,m;
	scanf("%d",&t);
	init();
	for(; t--;)
	{
		cin>>n;
		m=get(n);
		LL tmp=(LL)sqrt(double(m));
		LL x=tmp,y=m-tmp*tmp+1,ret=0;
		ret=x*y;
		x--;
		ret+=dat[x];
		cout<<m<<" "<<ret<<endl;
	}
	return 0;
}
