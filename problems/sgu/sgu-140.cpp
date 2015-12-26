#include <cstdio>
#include <iostream>
#define N 222

typedef long long LL;
using namespace std;

LL dat[N];
LL rx[N];

LL gcd(LL a,LL b,LL &x,LL &y)
{
	if(b==0)
	{
		x=1,y=0;
		return a;
	}
	LL g=gcd(b,a%b,y,x);
	y-=a/b*x;
	return g;
}

int main()
{
	LL n,p,b;
	while(cin>>n>>p>>b)
	{
		for(int i=0; i<n; i++)
		{
			if(i>=N)
				for(;;);
			LL x;
			cin>>x;
			dat[i]=x%p;
			if(dat[i]==0) dat[i]=p;
		}
		dat[n]=p;
		LL pre;
		pre=gcd(dat[0],dat[1],rx[0],rx[1]);
		for(int i=2; i<=n; i++)
		{
			LL x;
			pre=gcd(pre,dat[i],x,rx[i]);
			for(int j=0; j<i; j++)
				rx[j]=(rx[j]*x%p+p)%p;
		}
		if(b%pre)
			puts("NO");
		else
		{
			puts("YES");
			LL y=b/pre;
			for(int i=0; i<n; i++)
				rx[i]=(rx[i]*y%p+p)%p;
			cout<<rx[0];
			for(int i=1; i<n; i++)
				cout<<" "<<rx[i];
			puts("");
		}
	}
	return 0;
}
