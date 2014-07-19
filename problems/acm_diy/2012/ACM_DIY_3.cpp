//unsolved
/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  05/26/2012 04:25:12 PM
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
LL n;
int bit[N],top,tmp[N],tp,nn,mm;
int a,st,ed;
struct ans{ int x,y,z; }ret[N];

int main()
{
	int t;
	scanf("%d",&t);
	for(; t--;)
	{
		cin>>n;
		top=0;
		for(; n; n>>=1)
		{
			if(n&1)
				tmp[top]=1;
			else
				tmp[top]=0;
			top++;
		}
		tp=0;
		for(int i=0; i<top; i++)
			if(tmp[i])
				bit[tp++]=i;
		memset(mat,-1,sizeof(mat));
		a=bit[tp-1];
		nn=tp+bit[tp-1];
		mm=2*bit[tp-1]+4*(tp-1);
		st=1,ed=2;
		if(nn>100||mm>300||a>100)
			puts("NO");
		else
		{
			top=0;
			if(tp==0)
				top=0;
			else if(a>=2)
			{
				ret[top].x=s,ret[top].y=3,ret[top++].z=1;
				ret[top].x=s,ret[top].y=3,ret[top++].z=1;
			}
			else if(a==1)
			{
				ret[top].x=s,ret[top].y=t,ret[top++].z=1;
				ret[top].x=s,ret[top].y=t,ret[top++].z=1;
			}
			else if(a==0)
			{
				ret[top].x=s,ret[top].y=t,ret[top++].z=1;
			}
			for(int i=3; i<=a)
			{
				ret[top].x=i,ret[top].y=i+1,ret[top++].z=1;
				ret[top].x=i,ret[top].y=i+1,ret[top++].z=1;
			}

		}
	}
	return 0;
}
