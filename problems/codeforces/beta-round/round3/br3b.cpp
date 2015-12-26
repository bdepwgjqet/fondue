/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  09/26/2012 09:55:33 PM
 ***/

#include <cstring>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <sstream>
#include <cmath>
#include <functional>
#include <iostream>
#include <algorithm>
#define N 1010
#define M 1000010
#define S 1000100
#define eps 1e-8
#define inf 0x3fffffff
#define MOD 1000000007
#define PB push_back
#define MP make_pair
#define SZ(a) ((int)((a).size()))
#define ALL(a) (a).begin(),(a).end()
#define CLR(a,x) memset(a,x,sizeof(a))

typedef long long LL;
using namespace std;

struct node{ int x,i;
	friend int operator<(node a,node b){ return a.x<b.x; }
}no;
multiset<node> st[2];
multiset<node>::iterator it;
set<int> ans;

int main()
{
	int n,v;
	while(scanf("%d%d",&n,&v)!=EOF)
	{
		st[0].clear();
		st[1].clear();
		ans.clear();
		for(int i=0; i<n; i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			no.x=y,no.i=i+1;
			st[x-1].insert(no);
		}
		int ret=0;
		if(v&1)
		{
			if(st[0].size()>0)
			{
				it=st[0].end();
				it--;
				ret+=it->x;
				ans.insert(it->i);
				st[0].erase(it);
				v--;
			}
		}
		for(;;)
		{
			int one=-1,ov=-1,tv=-1,two=-1;
			if(v>1&&st[1].size()>0)
			{
				it=st[1].end();
				it--;
				one=it->x;
				ov=2;
			}
			if(v>0&&st[0].size()>0)
			{
				it=st[0].end();
				it--;
				two=it->x;
				tv=1;
				if(v>1&&st[0].size()>1)
				{
					it--;
					tv++;
					two+=it->x;
				}
			}
			if(ov<0&&tv<0)
				break;
			if(one>=two)
			{
				ret+=one;
				it=st[1].end();
				it--;
				ans.insert(it->i);
				st[1].erase(it);
				v-=ov;
			}
			else
			{
				ret+=two;
				it=st[0].end();
				it--;
				v-=tv;
				for(int i=0; i<tv; i++)
				{
					ans.insert(it->i);
					st[0].erase(it);
					it--;
				}
			}
		}
		printf("%d\n",ret);
		set<int>::iterator sit;
		for(sit=ans.begin(); sit!=ans.end(); sit++)
			printf("%d ",*sit);
		puts("");
	}
	return 0;
}
