/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  04/09/2012 04:46:16 PM
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
#define N 210010
#define M 1000010
#define S 1000100
#define eps 1e-8
#define inf 0x3fffffff
#define MOD 1000000007
#define PB push_back
#define SZ(a) ((int)((a).size()))
#define ALL(a) (a).begin(),(a).end()
#define CLR(a,x) memset(a,x,sizeof(a))

typedef long long LL;
using namespace std;

inline int L(int i){ return i<<1; }
inline int R(int i){ return (i<<1)|1; }
inline int B(int i){ return 1<<i; }
inline int low_bit(int x){ return x&(-x); }

char s[N];

int main()
{
	int a,b,l,half,mod;
	while(scanf("%s",s)!=EOF)
	{
		a=b=0;
		l=strlen(s);
		for(int i=0; i<l; i++)
			if(s[i]=='1')
				b++;
			else if(s[i]=='0')
				a++;
		half=l/2,mod=l%2;
		if(b<half+mod)
			puts("00");
		if(a<=half&&b<=half+mod)
		{
			if(s[l-1]=='0')
				puts("10");
			else if(s[l-1]=='1')
				puts("01");
			else
			{
				if(b<half+mod)
					puts("01");
				if(a<half)
					puts("10");
			}
		}
		if(a<half)
			puts("11");
	}
	return 0;
}
