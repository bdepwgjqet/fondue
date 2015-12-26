#include <cstdio>
#include <algorithm>
#include <set>
#define N 40

using namespace std;

set<int> nst;
set<int> tst;
set<int>::iterator it;
int dat[N];
int sum[N];

int cmp(int a,int b){ return a>b; }

int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)+1)
	{
		nst.clear();
		tst.clear();
		for(int i=0; i<n; i++)
			scanf("%d",&dat[i]);
		sort(dat,dat+n,cmp);
		sum[n-1]=dat[n-1];
		for(int i=n-2; i>=0; i--)
			sum[i]=sum[i+1]+dat[i];
		if(sum[0]<=m)
		{
			printf("%d\n",sum[0]);
			continue;
		}
		for(int i=0; i<n; i++)
		{
			if(nst.size()>0)
			{
				it=nst.end();
				it--;
				int x=*it;
				if(x==m)
					break;
				if(sum[i]+x<=m)
				{
					nst.insert(sum[i]+x);
					break;
				}
				for(it=nst.begin(); it!=nst.end(); it++)
				{
					if(*it+sum[i]<=x)
					{
						nst.erase(it);
						tst.erase(*it);
					}
					else break;
				}
			}
			if(dat[i]<=m)
			{
				tst.insert(dat[i]);
				for(it=nst.begin(); it!=nst.end(); it++)
					if(*it+dat[i]<=m)
						tst.insert(*it+dat[i]);
				nst=tst;
			}
		}
		if(nst.size()==0)
			printf("%d\n",0);
		else
		{
			it=nst.end();
			it--;
			printf("%d\n",*it);
		}
	}
	return 0;
}
