#include <cstdio>
#include <map>

using namespace std;

map<int,int> mp;
map<int,int>::iterator it;

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0; i<n; i++)
	{
		int x;
		scanf("%d",&x);
		mp[x]++;
	}
	int ret=0,cnt=0;
	for(it=mp.begin(); it!=mp.end(); it++)
	{
		if(it->first==0) continue;
		if(it->second>2)
		{
			puts("-1");
			return 0;
		}
		ret+=(it->second==2);
	}
	printf("%d\n",ret);
	return 0;
}
