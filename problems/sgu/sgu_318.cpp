#include <cstdio>
#include <cstring>
#include <set>

using namespace std;

set<int> st[111];
int vv[111];

int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		memset(vv,0,sizeof(vv));
		for(int i=0; i<m; i++)
			st[i].clear();
		for(int i=0; i<m; i++)
		{
			int x,y;
			scanf("%d",&x);
			for(int j=0; j<x; j++)
			{
				scanf("%d",&y);
				y--;
				st[y].insert(i);
			}
		}
		int ret=0;
		for(int i=0; i<n; i++)
		{
			if(st[i].size()>0&&vv[i]==0)
			{
				vv[i]=1;
				for(int j=i+1; j<n; j++)
				{
					if(st[j]==st[i])
						vv[j]=1;
				}
				ret++;
			}
		}
		printf("%d\n",ret);
	}
	return 0;
}
