/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  03/25/2012 01:10:25 PM
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
#define inf 1e10
#define N 101000
#define M 1000010
#define S 1000100
#define MOD 1000000007

typedef long long LL;
using namespace std;

inline int L(int i){ return i<<1; }
inline int R(int i){ return (i<<1)|1; }
inline int B(int i){ return 1<<i; }
inline int low_bit(int x){ return x&(-x); }

struct tree{ LL a,b; }ts[N],q[N];

int cmp_a(tree a,tree b){ return a.a>b.a; }
int top=0;
double xx[N];
LL ret[N];

double calx(tree a,tree b)
{
	return double((b.a-a.a))/(a.b-b.b);
}

int main()
{
	int n,m,x;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(int i=0; i<n; i++)
			cin>>ts[i].a>>ts[i].b;
		sort(ts,ts+n,cmp_a);
		top=0;
		q[top++]=ts[0];
		for(int i=1; i<n; i++)
		{
			if(ts[i].b<=q[top-1].b)
				continue;
			for(; top>=2; )
			{
				if(calx(ts[i],q[top-2])<=calx(q[top-1],q[top-2]))
					top--;
				else
					break;
			}

			q[top++]=ts[i];
		}
		for(int i=0; i<top-1; i++)
			xx[i]=calx(q[i],q[i+1]);
		xx[top-1]=inf;
		int now=0;
		for(int i=0; i<=N; i++)
		{
			for(; double(i)>xx[now]&&now<top; )
				now++;
			ret[i]=q[now].a+q[now].b*i;
		}
		for(int i=0; i<m; i++)
		{
			scanf("%d",&x);
			cout<<ret[x]<<endl;
		}
	}
	return 0;
}
