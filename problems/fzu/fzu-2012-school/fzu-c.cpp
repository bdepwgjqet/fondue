/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  04/28/2012 01:04:30 PM
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
#define N 10100
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

string s[N];

int cmp(string a,string b){ return a<b; }

int main()
{
	int t,ca,n;
	scanf("%d",&t);
	for(ca=1; ca<=t; ca++)
	{
		scanf("%d",&n);
		for(int i=0; i<n; i++)
			cin>>s[i];
		sort(s,s+n,cmp);
		for(int i=0; i<n; i++)
			cout<<s[i];
		puts("");
	}
	return 0;
}
