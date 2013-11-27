#include <cstdio>
#include <algorithm>
#include <set>
#define N 511

using namespace std;

multiset<int> st;
multiset<int>::iterator it;

int main()
{
	int n,x;
	while(scanf("%d%d",&n,&x)+1)
	{
		st.clear();
		for(int i=0; i<n; i++)
		{
			int x;
			scanf("%d",&x);
			st.insert(x);
		}
		for(;;)
		{
			it=upper_bound(st.begin(),st.end(),x);
			if(it!=st.end())
			{
				x+=2;
				st.erase(it);
			}
			else
				break;
		}
		printf("%d\n",x+st.size());
	}
	return 0;
}
