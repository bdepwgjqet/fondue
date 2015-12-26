/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  09/27/2012 10:49:24 AM
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
#define N 100010
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

char s[N];
struct node{ int v,i;
	friend int operator < (node a,node b){ return a.v==b.v?a.i<b.i:a.v<b.v; }
}no[N];
multiset<node> st;
multiset<node>::iterator it;

int main()
{
	int len,cnt;
	while(scanf("%s",s)+1)
	{
		st.clear();
		LL ret=0;
		len=strlen(s);
		cnt=0;
		for(int i=0; i<len; i++)
			if(s[i]=='?')
			{
				cnt++;
			}
		for(int i=0; i<cnt; i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			no[i].v=x-y;
			ret+=y;
		}
		int tag=0,top=0;
		int num=0;
		for(int i=0; i<len&&tag==0; i++)
		{
			if(s[i]=='(')
			{
				num++;
			}
			else
			{
				num--;
				if(s[i]=='?')
				{
					s[i]=')';
					no[top].i=i;
					st.insert(no[top]);
					top++;
				}
			}
			for(; num<0; )
			{
				if(st.size()<=0)
				{
					tag=1;
					break;
				}
				it=st.begin();
				ret+=it->v;
				s[it->i]='(';
				num+=2;
				st.erase(it);
			}
		}
		if(tag==1||num>0)
			puts("-1");
		else
			printf("%I64d\n%s\n",ret,s);
	}
	return 0;
}
