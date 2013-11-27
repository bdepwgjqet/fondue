#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

vector<int> list[30];
char s[30],ss[30];
int n;

void find(int &a,int &b,int x)
{
	for(int i=0; i<n; i++)
		for(int j=0; j<list[i].size(); j++)
			if(list[i][j]==x)
			{
				a=i,b=j;
				return;
			}
}

int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0; i<30; i++)
		{
			list[i].clear();
			list[i].push_back(i);
		}
		int x,y,a,b,u,v;
		while(scanf("%s",s))
		{
			if(strcmp(s,"quit")==0)
				break;
			scanf("%d%s%d",&x,ss,&y);
			find(a,b,x);
			find(u,v,y);
			if(a==u)
				continue;
			if(strcmp(s,"move")==0)
			{
				if(strcmp(ss,"onto")==0)
				{
					list[a].erase(list[a].begin()+b,list[a].begin()+b+1);
					list[u].insert(list[u].begin()+v+1,x);
				}
				else
				{
					list[a].erase(list[a].begin()+b,list[a].begin()+b+1);
					list[u].push_back(x);
				}
			}
			else
			{
				if(strcmp(ss,"onto")==0)
				{
					list[u].insert(list[u].begin()+v+1,list[a].begin()+b,list[a].end());
					list[a].erase(list[a].begin()+b,list[a].end());
				}
				else
				{
					list[u].insert(list[u].end(),list[a].begin()+b,list[a].end());
					list[a].erase(list[a].begin()+b,list[a].end());
				}
			}
		}
		for(int i=0; i<n; i++)
		{
			printf("%d:",i);
			for(int j=0; j<list[i].size(); j++)
				printf(" %d",list[i][j]);
			puts("");
		}
	}
	return 0;
}
