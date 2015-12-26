/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  04/14/2012 10:27:21 AM
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

inline int L(int i){ return i<<1; }
inline int R(int i){ return (i<<1)|1; }
//inline int B(int i){ return 1<<i; }
inline int low_bit(int x){ return x&(-x); }

int TEN[20],q[20];

void init()
{
	TEN[0]=1;
	for(int i=1; i<10; i++)
		TEN[i]=TEN[i-1]*10;
}

int ok(int x,int top)
{
	for(int i=0; i<top; i++)
		if(q[i]==x)
			return 0;
	return 1;
}

LL get_cnt(int x,int y)
{
	int i,l,t,a,b,top=0;
	LL ret=0;
	t=x;
	for(l=0; t; )
		t/=10,l++;
	for(int i=1; i<l; i++)
	{
		a=x;
		b=a%TEN[i];
		a/=TEN[i];
		a=a+b*TEN[l-i];
		if(a<=y&&a>x)
		{
			if(ok(a,top))
			{
				q[top++]=a;
				ret++;
			}
		}
	}
	return ret;
}

int main()
{
	int A,B,t,ca;
	LL ret;
	init();
	scanf("%d",&t);
	for(ca=1; ca<=t; ca++)
	{
		ret=0;
		printf("Caes #%d: ",ca);
		scanf("%d%d",&A,&B);
		for(int i=A; i<B; i++)
			ret+=get_cnt(i,B);
		printf("%lld\n",ret);
	}
	return 0;
}
