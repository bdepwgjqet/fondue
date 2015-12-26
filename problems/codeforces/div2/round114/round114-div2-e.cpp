/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  03/27/2012 10:38:06 PM
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
#define N 1010
#define M 1000010
#define S 1000100
#define MOD 1000000007

typedef long long LL;
using namespace std;

inline int L(int i){ return i<<1; }
inline int R(int i){ return (i<<1)|1; }
inline int B(int i){ return 1<<i; }
inline int low_bit(int x){ return x&(-x); }
LL cnt[N],top;
LL tmp,mul;

bool must_win(LL a,LL b)
{
	if(a==0||b==0)
		return 0;
	if(a>b)
		tmp=a,a=b,b=tmp;
	if(must_win(b%a,a)==0)
		return 1;
	tmp=b;
	tmp/=a;
	tmp%=a+1;
	if(tmp&1)
		return 0;
	return 1;
}

int main()
{
	int t;
	LL a,b; 
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		if(must_win(a,b))
			puts("First");
		else
			puts("Second");
	}
	return 0;
}


