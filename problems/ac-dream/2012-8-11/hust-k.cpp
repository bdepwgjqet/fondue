#include <cstdio>
#include <iostream>
typedef long long LL;
using namespace std;
int main()
{
	LL n;
	//while(scanf("%lld",&n)!=EOF)
	while(cin>>n)
	{
		if(n==0)
			break;
		cout<<n*(n+1)*(2*n+1)/6<<endl;
	}
	return 0;
}
