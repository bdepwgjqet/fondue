/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  06/12/2012 08:59:26 PM
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
inline int B(int i){ return 1<<i; }
inline int low_bit(int x){ return x&(-x); }

int a[N],b[N];

int gcd(int a,int b){ return b?gcd(b,a%b):a; }

int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(int i=0; i<=n; i++)
			scanf("%d",&a[i]);
		for(int i=0; i<=m; i++)
			scanf("%d",&b[i]);
		if(n<m)
		{
			puts("0/1");
		}
		else if(n>m)
		{
			if(a[0]*b[0]>0)
				puts("Infinity");
			else
				puts("-Infinity");
		}
		else
		{
			int tag=(a[0]*b[0]>0?1:-1);
			int aa=abs(a[0]),bb=abs(b[0]);
			int g=gcd(aa,bb);
			aa/=g,bb/=g;
			printf("%d/%d\n",tag*aa,bb);
		}
	}
	return 0;
}
