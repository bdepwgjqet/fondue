#include <cstdio>
#include <set>
#define N 100011

using namespace std;

int a[N];

int gcd(int a,int b){ return b?gcd(b,a%b):a; }

int main()
{
	int n;
	scanf("%d",&n);
	int x;
	scanf("%d",&a[0]);
	x=a[0];
	for(int i=1; i<n; i++)
	{
		scanf("%d",&a[i]);
		x=gcd(x,a[i]);
	}
	for(int i=0; i<n; i++)
		if(x%a[i]==0)
		{
			printf("%d\n",a[i]);
			return 0;
		}
	puts("-1");
	return 0;
}
