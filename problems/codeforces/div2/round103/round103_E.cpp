/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  04/12/2012 07:17:37 PM
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

inline int L(int i){ return i<<1; }
inline int R(int i){ return (i<<1)|1; }
inline int B(int i){ return 1<<i; }
inline int low_bit(int x){ return x&(-x); }

struct node
{
	int x,y,i;
	friend int operator<(node a,node b)
	{
		return a.y>b.y;
	}
}p[N];
priority_queue<node> q;
int cho[N],n,m;

int cmp(node a,node b) 
{ 
	return a.x>b.x;
}

int main()
{
	int x,y,l,r,ret;
	scanf("%d%d",&n,&m);
	memset(cho,0,sizeof(0));
	for(int i=0; i<m; i++)
	{
		scanf("%d%d",&x,&y);
		p[i].x=x,p[i].y=y;
		p[i].i=i+1;
	}
	sort(p,p+m,cmp);
	int j=0;
	for(int i=1; i<=n; i++)
	{
		for(; n+1-p[j].x<=i&&j<m; j++)
			q.push(p[j]);
		for(; !q.empty()&&q.top().y<i; )
			q.pop();
		if(!q.empty())
		{
			cho[q.top().i]=1;
			q.pop();
		}
	}
	ret=0;
	for(int i=1; i<=m; i++)
		if(cho[i])
			ret++;
	printf("%d\n",ret);
	for(int i=1; i<=m; i++)
		if(cho[i])
			printf("%d ",i);
	puts("");
	return 0;
}
