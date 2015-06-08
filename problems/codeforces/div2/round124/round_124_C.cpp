/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  06/12/2012 08:59:36 PM
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
#define N 100010
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

char s[N],ret[N];
int top;

int main()
{
	while(scanf("%s",s)!=EOF)
	{
		int now=0;
		int l=strlen(s);
		top=0;
		for(int i=25; i>=0; i--)
		{
			for(int j=now; j<l; j++)
			{
				if(s[j]==i+'a')
				{
					ret[top++]=i+'a';
					now=j+1;
				}
			}
		}
		ret[top]='\0';
		printf("%s\n",ret);
	}
	return 0;
}
