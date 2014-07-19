/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  03/25/2012 10:42:48 PM
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
#define N 5010
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
int ls,lt;
int f[N][N];

int main()
{
	int ret=0;
	while(scanf("%s%s",s,t)!=EOF)
	{
		ret=0;
		ls=strlen(s);
		lt=strlen(t);
		memset(f,0,sizeof(f));
		for(int i=1; i<=ls; i++)
			for(int j=1; j<=lt; j++)
			{
				f[i][j]=f[i][j-1];
				if(s[i-1]==t[j-1])
					f[i][j]=(f[i][j]+f[i-1][j-1]+1)%MOD;
			}
		for(int i=1; i<=ls; i++)
			ret=(ret+f[i][lt])%MOD;
		cout<<ret<<endl;
	}
	return 0;
}
