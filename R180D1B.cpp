#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> a;
vector<int> b;

int cmp(int a,int b){ return a<b; }
int n,m;

int gao()
{
	if(n>m)
		return 1;
	for(int i=0; i<n; i++)
	{
		if(a[n-i-1]>b[m-i-1]) return 1;
	}
	return 0;
}

int main()
{
	int k;
	while(scanf("%d%d%d",&n,&m,&k)+1)
	{
		for(int i=0; i<n; i++)
		{
			int x;
			scanf("%d",&x);
			a.push_back(x);
		}
		for(int i=0; i<m; i++)
		{
			int x;
			scanf("%d",&x);
			b.push_back(x);
		}
		sort(a.begin(),a.end(),cmp);
		sort(b.begin(),b.end(),cmp);
		if(gao())
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
