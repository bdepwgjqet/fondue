/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  04/15/2012 08:18:26 PM
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
#define N 101000
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

LL plist[N],p[N],top;

void init()
{
	top=0;
	for(LL i=0; i<N; i++)
		p[i]=i;
	for(int i=2; i<N; i++)
	{
		if(p[i]==i)
			plist[top++]=i;
		for(int j=0; j<top&&i*plist[j]<N; j++)
		{
			p[plist[j]*i]=plist[j];
			if(i%plist[j]==0)
				break;
		}
	}
}

LL get(LL id)
{
	LL x=id,cnt,ret=1;
    for(int i=0; i<top&&x>1; i++)
	{
		if(x%plist[i]==0)
		{
			cnt=1;
			for(; x%plist[i]==0; )
				cnt++,x/=plist[i];
			if(i==0)
				ret*=cnt-1;
			else
				ret*=cnt;
		}
	}
	return ret;
}

LL eular(LL n,LL id)
{
    LL ret=1;
	ret=get(id);
	ret*=get(id+1);
    return ret;
}

int over(LL g,LL &ret)
{
	LL i,eu,mx=0;
	for(i=0; ; i++)
	{
		ret=i*(i+1)/2;
		if(ret>1000000000LL)
		{
			return 1;
		}
		if(ret==0)
			eu=0;
		else if(ret==1)
			eu=1;
		else
			eu=eular(ret,i);
		if(eu>=g)
			return 0;
	}
	return 0;
}

int main()
{
	LL x,g,ret;
	init();
	while(cin>>g)
	{
		if(g>1024)
			puts("Mmm...");
		else
		{
			over(g,ret);
			cout<<ret<<endl;
		}
	}
	return 0;
}
