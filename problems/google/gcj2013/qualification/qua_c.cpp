#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

int isp(int x)
{
	vector<int> v;
	for(; x; x/=10)
		v.push_back(x%10);
	int n=v.size();
	for(int i=0; i<n; i++)
		if(v[i]!=v[n-i-1])
			return 0;
	return 1;
}

int ok(int x)
{
	if(!isp(x))
		return 0;
	int y=int(sqrt(1.0*x));
	if(x!=y*y) return 0;
	if(!isp(y))
		return 0;
	return 1;
}

int main()
{
	int t;
	scanf("%d",&t);
	for(int ca=1; ca<=t; ca++)
	{
		printf("Case #%d: ",ca);
		int l,r;
		scanf("%d%d",&l,&r);
		int ret=0;
		for(int i=l; i<=r; i++)
			if(ok(i))
				ret++;
		printf("%d\n",ret);
	}
	return 0;
}
