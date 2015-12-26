#include <cstdio>
#include <map>
#define N 20001
using namespace std;

struct ufind
{
	int p[N],sum[N];
	void init()
	{
		for(int i=0; i<N; i++)
			p[i]=i,sum[i]=0;
	}
	int pa(int x)
	{
		if(x==p[x])
			return x;
		int ret=pa(p[x]);
		sum[x]=(sum[x]+sum[p[x]])&1;
		p[x]=ret;
		return ret;
	}
}uf;

map<int,int> mp;
int top;

int main()
{
	int l,n;
	scanf("%d%d",&l,&n);
	top=0;
	mp.clear();
	uf.init();
	int ret=-1;
	char s[10];
	for(int i=0; i<n; i++)
	{
		int x,y,xx,yy,px,py,z;
		scanf("%d%d%s",&x,&y,s);
		if(ret>=0) continue;
		x--;
		if(s[0]=='o')
			z=1;
		else
			z=0;
		if(mp.find(x)==mp.end())
			mp[x]=top++;
		if(mp.find(y)==mp.end())
			mp[y]=top++;
		xx=mp[x],yy=mp[y];
		px=uf.pa(xx);
		py=uf.pa(yy);
		if(px==py)
		{
			if(z!=((uf.sum[xx]+uf.sum[yy])&1))
				ret=i;
		}
		else
		{
			uf.p[px]=py;
			uf.sum[px]=(uf.sum[xx]+uf.sum[yy]+z)&1;
		}
	}
	if(ret<0) ret=n;
	printf("%d\n",ret);
	return 0;
}
