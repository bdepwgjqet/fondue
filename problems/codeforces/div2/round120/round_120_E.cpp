/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  05/17/2012 06:55:24 PM
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
#define N 601000
#define M 2000010
#define S 2000100
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

inline int L(int i){ return i<<1; }
inline int R(int i){ return (i<<1)|1; }
inline int B(int i){ return 1<<i; }
inline int low_bit(int x){ return x&(-x); }

struct edge{ int f,t,n; }e[S];
set<int> st;
vector<int> ans[N];
set<int>::iterator p;
int ret,top,list[N],q[N],v[N],use[N],ese[N];

void insert(int f,int t)
{
	e[top].f=f,e[top].t=t;
	e[top].n=list[f],list[f]=top++;
}

void solve(int n)
{
	int l,r,cnt,lay=1;
	memset(use,0,sizeof(use));
	for(cnt=0; cnt<n; ret++)
	{
		int x=*st.begin();
		st.erase(x);
		q[l=r=0]=x;
		for(; l<=r;)
		{
			int num=0;
			x=q[l++];
			ans[ret].PB(x);
			cnt++;
			for(int i=list[x]; i!=-1; i=e[i].n)
				use[e[i].t]=lay;
			for(p=st.begin(); p!=st.end(); p++)
			{
				int tmp=*p;
				if(use[tmp]==lay)
					continue;
				q[++r]=tmp;
				ese[num++]=tmp;
			}
			for(int i=0; i<num; i++)
				st.erase(ese[i]);
			lay++;
		}
	}
}

int main()
{
	int n,m,x,y;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		st.clear();
		top=0,ret=0;
		for(int i=0; i<n; i++)
		{
			st.insert(i);
			ans[i].clear();
		}
		for(int i=0; i<n; i++)
			list[i]=-1;
		for(int i=0; i<m; i++)
		{
			scanf("%d%d",&x,&y);
			x--,y--;
			insert(x,y);
			insert(y,x);
		}
		solve(n);
		printf("%d\n",ret);
		for(int i=0; i<ret; i++)
		{
			printf("%d",ans[i].size());
			for(int j=0; j<ans[i].size(); j++)
				printf(" %d",ans[i][j]+1);
			puts("");
		}
	}
	return 0;
}
