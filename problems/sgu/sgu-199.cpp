#include <cstdio>
#include <vector>
#include <algorithm>
#define inf 0x7fffffff
#define N 100011

using namespace std;

struct node{ int x,y,i; }no[N];

int dat[N],top,pre[N],hash[N];
int cmp(node a,node b){ return a.x==b.x?a.y>b.y:a.x<b.x; }

vector<int> li;
vector<int> id;
vector<int> ans;

void dfs(int now)
{
	if(now==-1) return;
	ans.push_back(hash[now]+1);
	dfs(pre[now]);
}

int hugao()
{
	li.clear();
	id.clear();
	for(int i=0; i<top; i++)
	{
		int ii=lower_bound(li.begin(),li.end(),dat[i])-li.begin(),now=-1;
		if(ii==li.size())
		{
			li.push_back(dat[i]);
			if(id.size()>0)
				now=id[id.size()-1];
			id.push_back(i);
		}
		else
		{
			li[ii]=dat[i];
			id[ii]=i;
			if(ii>0)
				now=id[ii-1];
		}
		pre[i]=now;
	}
	ans.clear();
	dfs(id[id.size()-1]);
	return li.size();
}

int main()
{
	int n;
	while(scanf("%d",&n)+1)
	{
		for(int i=0; i<n; i++)
		{
			scanf("%d%d",&no[i].x,&no[i].y);
			no[i].i=i;
		}
		top=0;
		sort(no,no+n,cmp);
		int pre=inf;
		for(int i=0; i<n; i++)
		{
			if(pre!=no[i].y)
			{
				hash[top]=no[i].i;
				dat[top++]=no[i].y;
			}
			pre=no[i].y;
		}
		printf("%d\n",hugao());
		printf("%d",ans[0]);
		for(int i=1; i<ans.size(); i++)
			printf(" %d",ans[i]);
		puts("");
	}
	return 0;
}
