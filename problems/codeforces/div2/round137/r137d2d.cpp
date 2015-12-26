#include <cstdio>
#include <algorithm>
#include <set>
#define N 109001
using namespace std;

int da[N];
multiset<int> db;
multiset<int>:: iterator it;

int cmp(int a,int b){ return a>b; }

int main()
{
	int n,x;
	scanf("%d%d",&n,&x);
	for(int i=0; i<n; i++)
	{
		int tx;
		scanf("%d",&tx);
		da[i]=tx;
	}
	for(int i=0; i<n; i++)
	{
		int tx;
		scanf("%d",&tx);
		db.insert(tx);
	}
	printf("1 ");
	int ret=0;
	sort(da,da+n,cmp);
	for(int i=0; i<n; i++)
	{
		int y=x-da[i];
		it=db.lower_bound(y);
		if(it==db.end())
			 break;
		db.erase(it);
		ret++;
	}
	printf("%d\n",ret);
	return 0;
}
