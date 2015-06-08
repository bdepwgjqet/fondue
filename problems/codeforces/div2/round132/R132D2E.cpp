/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  08/06/2012 11:29:13 PM
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

LL dfs2(int n)
{
	LL ret=1LL<<(n-1);
	for(int i=1; i<n; i++)
	{
		if(n%i==0)
			ret-=dfs2(i);
	}
	return ret;
}

LL dfs1(LL n)
{
	if(n<=2) return 0;
	vector<int> b;
	LL x=n;
	for(; x;)
		b.push_back(x&1),x>>=1;
	reverse(b.begin(),b.end());
	LL ret=0;
	for(int i=1; i<=b.size(); i++)
	{
		if(b.size()%i==0)
		{
			int k=b.size()/i;
			if(k<2)
				break;
			LL now=0,rnow=0;
			for(int j=0; j<i; j++)
				now<<=1,now+=b[j];
			for(int j=0; j<k; j++)
				rnow<<=i,rnow+=now;
			if(rnow>n)
				now--;
			if(now&(1LL<<(i-1)))
				ret=ret+now-(1<<(i-1))+1-dfs1(now);
		}
	}
	return ret;
}

LL calc(LL n)
{
	if(n<3) return 0;
	vector<int> b;
	LL x=n;
	for(; x;)
		b.push_back(x&1),x>>=1;
	reverse(b.begin(),b.end());
	LL ret=0;
	for(int i=1; i<=b.size(); i++)
	{
		for(int k=2; k*i<=b.size(); k++)
		{
			if(k*i<b.size())
			{
				ret+=dfs2(i);
			}
			else
			{
				LL now=0,rnow=0;
				for(int j=0; j<i; j++)
					now<<=1,now+=b[j];
				for(int j=0; j<k; j++)
					rnow<<=i,rnow+=now;
				if(rnow>n)
					now--;
				if(now&(1LL<<(i-1)))
					ret=ret+now-(1<<(i-1))+1-dfs1(now);
			}
		}
	}
	return ret;
}

int main()
{
	LL l,r;
	while(cin>>l>>r)
	{
		cout<<calc(r)-calc(l-1)<<endl;
	}
	return 0;
}
