#include <cstdio>
#include <map>
#include <algorithm>
#define N 10000001

using namespace std;

int p[N],plist[N],top,da[100001],db[100001];
map<int,int> up,dn;
map<int,int>::iterator it;

void init()
{
	top=0;
	for(int i=0; i<N; i++)
		p[i]=i;
	for(int i=2; i<N; i++)
	{
		if(p[i]==i)
			plist[top++]=i;
		for(int j=0; j<top&&i*plist[j]<N; j++)
		{
			p[i*plist[j]]=plist[j];
			if(i%plist[j]==0)
				break;
		}
	}
}

int main()
{
	int n,m;
	init();
	scanf("%d%d",&n,&m);
	for(int i=0; i<n; i++)
	{
		int x,y,c;
		scanf("%d",&x);
		da[i]=x;
		for(; x>1;)
		{
			y=p[x],c=0;
			for(; x%y==0;)
				x/=y,c++;
			up[y]+=c;
		}
	}
	for(int i=0; i<m; i++)
	{
		int x,y,c;
		scanf("%d",&x);
		db[i]=x;
		for(; x>1;)
		{
			y=p[x],c=0;
			for(; x%y==0;)
				x/=y,c++;
			dn[y]+=c;
		}
	}
	printf("%d %d\n",n,m);
	for(int i=0; i<n; i++)
	{
		int x,y,c,z=1,cc;
		x=da[i];
		for(; x>1;)
		{
			y=p[x],c=0;
			for(; x%y==0;)
				x/=y,c++;
			cc=up[y]-dn[y];
			if(cc>0)
			{
				cc=min(cc,c);
				for(int j=0; j<cc; j++)
					z*=y;
				up[y]-=cc;
			}
		}
		printf("%d ",z);
	}
	puts("");
	for(int i=0; i<m; i++)
	{
		int x,y,c,z=1,cc;
		x=db[i];
		for(; x>1;)
		{
			y=p[x],c=0;
			for(; x%y==0;)
				x/=y,c++;
			cc=dn[y]-up[y];
			if(cc>0)
			{
				cc=min(cc,c);
				for(int j=0; j<cc; j++)
					z*=y;
				dn[y]-=cc;
			}
		}
		printf("%d ",z);
	}
	puts("");
	return 0;
}
