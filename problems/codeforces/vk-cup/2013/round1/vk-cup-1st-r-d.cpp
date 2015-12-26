/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  03/11/2012 10:56:38 PM
 ***/

#include <cstring>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>
#define MAXN 51010
#define X 501
#define MAXM 1000010
#define MOD 1000000007

typedef long long LL;
using namespace std;

LL ret;

inline int L(int i){ return i<<1; }
inline int R(int i){ return (i<<1)|1; }
inline int max(int a,int b){ return a<b?b:a; }
inline int min(int a,int b){ return a<b?a:b; }
inline int abs(int x){ return x<0?-x:x; }

struct edge{ int f,t,n; }e[2*MAXN];

int list[MAXN],top,n,k,v[MAXN],len[MAXN][X];

void insert(int f,int t)
{
	e[top].f=f,e[top].t=t;
	e[top].n=list[f],list[f]=top++;
}

void dfs(int now)
{
	int i,j;
	v[now]=1;
	len[now][0]=1;
	for(i=list[now]; i!=-1; i=e[i].n)
		if(!v[e[i].t])
		{
			dfs(e[i].t);
			for(j=0; j+1<=k; j++)
			{
				ret+=len[now][j]*len[e[i].t][k-j-1];
		//		printf("%d %d %d=>\n",len[now][j],len[e[i].t][k-j-1],e[j].t);
			}
			for(j=1; j<X; j++)
				len[now][j]+=len[e[i].t][j-1];
		//	printf("%lld %d %d\n",ret,now,e[i].t);
		}
	v[now]=0;
}

int main()
{
	int i,x,y;
	while(cin>>n>>k)
	{
		memset(v,0,sizeof(v));
		memset(len,0,sizeof(len));
		for(top=i=0; i<n; i++)	list[i]=-1;
		for(i=0; i<n-1; i++)
		{
			cin>>x>>y;
			x--,y--;
			insert(x,y);
			insert(y,x);
		}
		ret=0;
		dfs(0);
		cout<<ret<<endl;
	}
	return 0;
}
