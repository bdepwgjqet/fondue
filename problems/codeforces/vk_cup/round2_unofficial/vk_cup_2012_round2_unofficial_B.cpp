/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  03/26/2012 02:43:28 PM
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
#define N 101000
#define M 1000010
#define S 1000100
#define MOD 1000000007

typedef long long LL;
using namespace std;

inline int L(int i){ return i<<1; }
inline int R(int i){ return (i<<1)|1; }
inline int B(int i){ return 1<<i; }
inline int low_bit(int x){ return x&(-x); }

char s[N],t[N];

int cmp(char a,char b){ return a>b; }

int main()
{
	int n,m;
	scanf("%s%s",s,t);
	n=strlen(s),m=strlen(t);
	sort(t,t+m,cmp);
	int j=0;
	for(int i=0; i<n; i++)
	{
		if(s[i]<t[j])
			s[i]=t[j],j++;
	}
	printf("%s\n",s);
	return 0;
}


