#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <string>
#define N 100001

using namespace std;

struct ufind
{
	int p[N],f;
	void init(int n)
	{
		for(int i=0; i<n; i++)
			p[i]=i;
	}
	void run(int &x)
	{
		int y=x,t;
		for(; x!=p[x]; x=p[x]);
		for(; p[t=y]!=x; y=p[y],p[t]=x);
	}
}uf;

char s[20],s1[20],s2[20];

int main()
{
	int n,peo;
	while(scanf("%d",&n)!=EOF)
	{
		set<int> inf[N];
		set<int>::iterator it;
		map<string,int> id;
		uf.init(n);
		peo=0;
		for(int i=0; i<n; i++)
		{
			scanf("%s",s);
			if(strcmp(s,"arrive")==0)
			{
				int m,x;
				scanf("%s%d",s1,&m);
				for(int j=0; j<m; j++)
				{
					scanf("%d",&x);
					inf[peo].insert(x);
				}
				id[string(s1)]=peo;
				peo++;
			}
			else if(strcmp(s,"share")==0)
			{
				scanf("%s%s",s1,s2);
				int i1=id[string(s1)],i2=id[string(s2)];
				uf.run(i1);
				uf.run(i2);
				if(i1==i2)
					continue;
				uf.p[i1]=i2;
				for(it=inf[i1].begin(); it!=inf[i1].end(); it++)
				{
					inf[i2].insert(*it);
					inf[i1].erase(it);
				}
			}
			else
			{
				scanf("%s",s);
				int ii=id[string(s)];
				uf.run(ii);
				printf("%d\n",inf[ii].size());
			}
		}
	}
	return 0; 
}
