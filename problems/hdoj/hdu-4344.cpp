#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <map>
#define N 1001
typedef long long LL;
using namespace std;

LL list[N];
int top;

LL mulmod(LL a,LL b,LL n)
{
	LL ret=0;
	a=a%n;
	for(; b; )
	{
		if(b&1)
		{
			ret=ret+a;
			if(ret>n) ret-=n;
		}
		a<<=1;
		if(a>n)
			a-=n;
		b>>=1;
	}
	return ret;
}

LL expmod(LL a,LL b,LL n)
{
	LL ret=1;
	for(; b;)
	{
		if(b&1)
			ret=mulmod(ret,a,n);
		a=mulmod(a,a,n);
		b>>=1;
	}
	return ret;
}

int miller_rabbin(LL n,int times=8)
{
	if(n==2) return 1;
	if((n&1)==0||n<2) return 0;
	LL m=n-1,x,y;
	int k=0;
	for(; (m&1)==0; m>>=1,k++);
	for(int i=0; i<times; i++)
	{
		x=rand()%(n-2)+2;
		y=x=expmod(x,m,n);
		if(x==1) continue;
		for(int j=0; j<k; j++)
		{
			y=mulmod(x,x,n);
			if(y==1&&x!=n-1&&x!=1) return 0;
			x=y;
		}
		if(y!=1) return 0;
	}
	return 1;
}

LL gcd(LL a,LL b){ return b?gcd(b,a%b):a; }

LL pollar_rho(LL n,int c)
{
	LL x,y,p;
	int i=1,k=2;
	y=x=rand()%(n-1)+1;
	for(;;)
	{
		i++;
		x=(mulmod(x,x,n)+c)%n;
		if(x==y) return n;
		p=gcd(x-y,n);
		if(1<p&&p<n) return p;
		if(i==k)
		{
			k<<=1;
			y=x;
		}
	}
}


void find_fac(LL n,int c)
{
	if(n==1)
		return;
	if(miller_rabbin(n))
	{
		list[top++]=n;
		return;
	}
	LL x=n;
	int nc=c;
	for(; x>=n; )
		x=pollar_rho(n,nc--);
	find_fac(n/x,c);
	find_fac(x,c);
}

map<LL,int> mp;

LL get(LL a,int b)
{
	LL ret=1;
	for(; b;)
	{
		if(b&1)
			ret=ret*a;
		a*=a;
		b>>=1;
	}
	return ret;
}

int main()
{
	int t;
	LL n;
	srand(time(0));
	scanf("%d",&t);
	for(; t--; )
	{
		//cin>>n;
		scanf("%I64d",&n);
		top=0;
		find_fac(n,120);
		mp.clear();
		for(int i=0; i<top; i++)
			mp[list[i]]++;
		int s=mp.size();
		if(s==1)
		{
			//printf("%d %lld\n",s,n/list[0]);
			//cout<<s<<" "<<n/list[0]<<endl;
			printf("%d %I64d\n",s,n/list[0]);
		}
		else
		{
			LL ret=0;
			map<LL,int>::iterator it;
			for(it=mp.begin(); it!=mp.end(); it++)
			{
				ret+=get(it->first,it->second);
			}
			//printf("%d %lld\n",s,ret);
			//cout<<s<<" "<<ret<<endl;
			printf("%d %I64d\n",s,ret);
		}
	}
	return 0;
}
