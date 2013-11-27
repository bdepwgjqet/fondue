#include <cstdio>
#include <algorithm>
#define MOD 1000
#define N 20011
using namespace std;

struct ufind
{
	int p[N],c[N],st[N],top;
	void init(int n)
	{
		for(int i=0; i<n; i++)
			p[i]=i,c[i]=0;
	}
	void run(int &x)
	{
		int y,l,pre;
		top=-1;
		for(; p[x]!=x; st[++top]=x,x=p[x]);
		l=0;
		for(; top>=0; top--)
		{
			y=st[top];
			l+=c[y];
			p[y]=x;
			c[y]=l;
		}
	}
	int query(int x)
	{
		int y=x;
		run(x);
		return c[y];
	}
	void setfriend(int i,int j)
	{
		p[i]=j;
		c[i]=abs(i-j)%MOD;
	}
}uf;

int main()
{
	int t,n;
	scanf("%d",&t);
	for(; t--;)
	{
		scanf("%d",&n);
		uf.init(n);
		char s[10];
		for(; scanf("%s",s);)
		{
			if(s[0]=='O')
				break;
			if(s[0]=='E')
			{
				int x;
				scanf("%d",&x);
				printf("%d\n",uf.query(x-1));
			}
			else
			{
				int x,y;
				scanf("%d%d",&x,&y);
				uf.setfriend(x-1,y-1);
			}
		}
	}
	return 0;
}
