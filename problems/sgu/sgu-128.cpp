#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 10010
#define X 20020

using namespace std;

struct node{ int x,y; }no[N];
struct ufind
{
	int p[N];
	void init(int n){ for(int i=0; i<=n; i++) p[i]=i; }
	int pa(int x)
	{
		int y=x,t;
		for(; p[x]!=x; x=p[x]);
		for(; p[t=y]!=x; y=p[y],p[t]=x);
		return x;
	}
}uf;

int cmp(node a,node b){ return a.x==b.x?a.y<b.y:a.x<b.x; }

int sum[X],cx[X],cy[X];

inline int low(int x){ return x&(-x); }

int cal(int x)
{
	int ret=0;
	for(; x>0; x-=low(x))
		ret+=sum[x];
	return ret;
}

void ins(int p,int x)
{
	for(; p<X; p+=low(p))
		sum[p]+=x;
}

int get(int i)
{
	int c=cal(no[i].y)-cal(no[i].y-1),ret=0;
	if(c>0)
	{
		int x=uf.pa(c),y=uf.pa(i);
		uf.p[x]=y;
		ins(no[i].y,-c);
		ret+=no[i].x-no[c].x;
	}
	else
		ins(no[i].y,i);
	return ret;
}

int gao(int n)
{
	int ret=0;
	memset(sum,0,sizeof(sum));
	memset(cx,0,sizeof(cx));
	memset(cy,0,sizeof(cy));
	for(int i=1; i<=n; i++)
		cx[no[i].x]++,cy[no[i].y]++;
	for(int i=0; i<X; i++)
		if((cx[i]&1)||(cy[i]&1))
			return 0;
	uf.init(n);
	for(int i=1; i<=n; i+=2)
	{
		int c=cal(no[i+1].y-1)-cal(no[i].y);
		if(c>0) return 0;
		int x=uf.pa(i),y=uf.pa(i+1);
		uf.p[x]=y;
		ret+=get(i);
		ret+=get(i+1);
		ret+=no[i+1].y-no[i].y;
	}
	int r=uf.pa(1);
	for(int i=2; i<=n; i++)
		if(uf.pa(i)!=r)
			return 0;
	return ret;
}

int main()
{
	int n;
	while(scanf("%d",&n)+1)
	{
		for(int i=1; i<=n; i++)
		{
			scanf("%d%d",&no[i].x,&no[i].y);
			no[i].x+=N,no[i].y+=N;
		}
		sort(no+1,no+n+1,cmp);
		int tp=1;
		for(int i=2; i<=n; i++)
		{
			if(no[i].x==no[tp].x&&no[i].y==no[tp].y)
				continue;
			no[++tp]=no[i];
		}
		n=tp;
		printf("%d\n",gao(n));
	}
	return 0;
}
