/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  03/25/2012 02:10:21 PM
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

char s[30];
double p[30],mx;
double ret[30];

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		mx=0;
		for(i=0; i<n; i++)
			ret[i]=1.0;
		for(int i=0; i<26; i++)
			scanf("%lf",&p[i]);
		for(int i=0; i<n; i++)
		{
			scanf("%s",s);
			l=strlen(s);
			for(int j=0; j<l; j++)
				ret[i]*=p[s[j]-'a'];
			mx=max(ret[i],mx);
		}
		if(mx<=0)
			puts("can not stop");
	}
	return 0;
}


