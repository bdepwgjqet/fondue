/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  07/11/2012 11:31:52 PM
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
#define inf 0x7fffffff
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

int dat[N];

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int x=inf,id;
		for(int i=0; i<n; i++)
		{
			scanf("%d",&dat[i]);
			if(x>dat[i])
				x=dat[i],id=i;
		}
		int cnt=0;
		for(int i=0; i<n; i++)
			if(dat[i]==x)
				cnt++;
		if(cnt>=2)
			puts("Still Rozdil");
		else
			printf("%d\n",id+1);
	}
	return 0;
}
