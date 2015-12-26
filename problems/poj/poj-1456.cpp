#include <cstdio>
#include <algorithm>
#define N 10001
using std::sort;

struct ufind
{
	int p[N];
	void init(){ for(int i=0; i<N; i++) p[i]=i; }
	void run(int &x)
	{
		int y=x;
		for(; p[x]!=x; x=p[x]);
		for(; p[y]!=x; p[y]=x,y=p[y]);
	}
	void setfriend(int i,int j)
	{
		run(i);
		run(j);
		p[i]=j;
	}
	int isfriend(int i,int j)
	{
		run(i);
		run(j);
		return i==j;
	}
}uf;
struct node{ int v,d; }no[N];
int cmp(node a,node b){ return a.v>b.v; }

int main()
{
	int n,ret=0;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0; i<n; i++)
			scanf("%d%d",&no[i].v,&no[i].d);
		sort(no,no+n,cmp);
		uf.init();
		ret=0;
		for(int i=0; i<n; i++)
		{
			int x=no[i].d;
			uf.run(x);
			if(x<=0)
				continue;
			ret+=no[i].v;
			uf.setfriend(x,x-1);
		}
		printf("%d\n",ret);
	}
	return 0;
}
