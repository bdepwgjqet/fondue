#include <cstdio>
#include <set>
#include <cstring>
#include <algorithm>
#define N 100010

using namespace std;

struct sol{ int x,tag,i,l; }no[N]; 
struct node{ int x,i;
	friend int operator <(node a,node b){ return a.x==b.x?a.i<b.i:a.x<b.x; }
};

int cmp(sol a,sol b){ return a.x==b.x?a.tag<b.tag:a.x<b.x; }
int top;
int vis[N];
set<node> st;
set<node>::iterator it;

void add(int x,int tag,int i)
{
	no[top].x=x,no[top].tag=tag,no[top].i=i;
	top++;
}

int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		top=0;
		memset(vis,0,sizeof(vis));
		st.clear();
		for(int i=0; i<n; i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			add(x,-1,i);
			no[top-1].l=y;
			add(y,1,i);
			no[top-1].l=x;
		}
		for(int i=0; i<m; i++)
		{
			int x;
			scanf("%d",&x);
			add(x,0,-1);
		}
		sort(no,no+top,cmp);
		int ret=0;

		for(int i=0; i<top; i++)
		{
			if(no[i].tag==0)
			{
				for(it=st.begin(); it!=st.end(); it++)
				{
					if(it->x<no[i].x)
						st.erase(it);
					else
						break;
				}
				if(st.size()==0)
					continue;
				it=st.begin();
				ret++;
				vis[it->i]=1;
				st.erase(it);
			}
			else if(no[i].tag==-1)
			{
				node now;
				now.i=no[i].i;
				now.x=no[i].l;
				st.insert(now);
			}
			else
			{
				if(vis[no[i].i])
					continue;
				node now;
				now.i=no[i].i;
				now.x=no[i].x;
				st.erase(now);
			}
		}
		printf("%d\n",ret);
	}
	return 0;
}
