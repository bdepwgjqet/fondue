#include <cstdio>
#include <vector>
#define inf 0x3fffffff

using namespace std;

vector<int> vec;

int dfs(int n)
{
	if(!(n&1))
		return inf;
	if(n==1)
		return 0;
	int ret=dfs(n/2)+1;
	if(ret<inf)
	{
		vec.push_back(2);
		return ret;
	}
	ret=dfs(n/2+1)+1;
	if(ret<inf)
	{
		vec.push_back(1);
		return ret;
	}
	return inf;
}

int main()
{
	int n;
	while(scanf("%d",&n)+1)
	{
		vec.clear();
		int ret=dfs(n);
		if(ret<inf)
		{
			printf("%d\n",ret);
			for(int i=0; i<vec.size(); i++)
			{
				printf("%d",vec[i]);
				if(i<vec.size()-1)
					printf(" ");
			}
			puts("");
		}
		else
			puts("No solution");
	}
}
