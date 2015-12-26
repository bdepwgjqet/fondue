/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  05/29/2012 04:26:23 PM
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
#define N 501000
#define M 1000010
#define S 1000100
#define X 26
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

int dp[30][30];
char s[N];

int main()
{
	int n;
	memset(dp,0,sizeof(dp));
	scanf("%d",&n);
	for(int i=0; i<n; i++)
	{
		scanf("%s",s);
		int l=strlen(s);
		for(int j=0; j<X; j++)
		{
			if(dp[j][s[0]-'a']>0)
				dp[j][s[l-1]-'a']=max(dp[j][s[l-1]-'a'],dp[j][s[0]-'a']+l);
			else if(j==s[0]-'a')
				dp[j][s[l-1]-'a']=max(dp[j][s[l-1]-'a'],dp[j][s[0]-'a']+l);
		}
	}
	int ret=0;
	for(int i=0; i<X; i++)
		ret=max(ret,dp[i][i]);
	printf("%d\n",ret);
	return 0;
}
