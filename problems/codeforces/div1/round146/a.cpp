#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

int gcd(int a,int b)
{
	return b?gcd(b,a%b):a;
}

int main()
{
	int n;
	scanf("%d",&n);
	if(n<=2)
	{
		printf("%d\n",n);
		return 0;
	}
	if(n&1)
		cout<<1LL*n*(n-1)*(n-2)<<endl;
	else
	{
		LL ret=1LL*(n-2)*(n-1)*(n-3);
		for(int x=n-2; x>=n-3; x--)
		{
			ret=max(ret,1LL*n*(n-1)*x/gcd(x,n)/gcd(x,n-1));
		}
		cout<<ret<<endl;
	}
	return 0;
}
