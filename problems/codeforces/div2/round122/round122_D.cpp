/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  06/04/2012 12:31:15 AM
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
#define N 32
#define M 1000010
#define S 1000100
#define eps 1e-8
#define inf 0x3fffffffffffffLL
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

int n,u,r;
LL a[N],b[N],k[N],p[N],ret;

void dfs(int cnt,LL aa[],int tag)
{
	if(cnt==u)
	{
		LL s=0;
		for(int i=0; i<n; i++)
			s+=aa[i]*k[i];
		ret=max(ret,s);
		return;
	}
	if((u-cnt)%2==0)
	{
		LL s=0;
		for(int i=0; i<n; i++)
			s+=aa[i]*k[i];
		ret=max(ret,s);
	}
	LL na[N];
	if(!tag)
	{
		for(int i=0; i<n; i++)
			na[i]=aa[i]^b[i];
		dfs(cnt+1,na,1);
	}
	for(int i=0; i<n; i++)
		na[i]=aa[p[i]-1]+r;
	dfs(cnt+1,na,0);
}

int main()
{
	scanf("%d%d%d",&n,&u,&r);
	for(int i=0; i<n; i++)
		cin>>a[i];
	for(int i=0; i<n; i++)
		cin>>b[i];
	for(int i=0; i<n; i++)
		cin>>k[i];
	for(int i=0; i<n; i++)
		cin>>p[i];
	ret=-inf;
	dfs(0,a,0);
	cout<<ret<<endl;
	return 0;
}
