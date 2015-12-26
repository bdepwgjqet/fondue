/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  04/07/2012 04:26:03 PM
 ***/

#include <cstring>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cmath>
#include <iostream>
#include <algorithm>
#define N 200010
#define M 1000010
#define S 1000100
#define eps 1e-8
#define inf 0x3fffffff
#define MOD 1000000007
#define PB push_back
#define SZ(a) ((int)((a).size()))
#define ALL(a) (a).begin(),(a).end()
#define CLR(a,x) memset(a,x,sizeof(a))

typedef long long LL;
using namespace std;

inline int L(int i){ return i<<1; }
inline int R(int i){ return (i<<1)|1; }
inline int B(int i){ return 1<<i; }
inline int low_bit(int x){ return x&(-x); }

struct node{ int x,i; 
	friend int operator<(node a,node b){ return a.x<b.x; }
}tmp,dat[N];
priority_queue<node> q;
int ret[N][2],top;

int solve()
{
	for(; !q.empty();)
	{
		tmp=q.top(),q.pop();
		int i;
		for(i=0; i<tmp.x&&(!q.empty()); i++)
		{
			dat[i]=q.top();
			q.pop();
			dat[i].x--;
			ret[top][0]=tmp.i;
			ret[top++][1]=dat[i].i;
		}
		if(i<tmp.x)
			return 0;
		for(i=0; i<tmp.x; i++)
			if(dat[i].x>0)
				q.push(dat[i]);
	}
	return 1;
}

int main()
{
	int n,s,x;
	top=0;
	scanf("%d%d",&n,&s);
	for(int i=1; i<=n; i++)
	{
		scanf("%d",&x);
		tmp.x=x,tmp.i=i;
		if(tmp.x>0)
			q.push(tmp);
	}
	if(solve())
	{
		puts("Yes");
		printf("%d\n",top);
		for(int i=0; i<top; i++)
			printf("%d %d\n",ret[i][0],ret[i][1]);
	}
	else
		puts("No");
	return 0;
}


