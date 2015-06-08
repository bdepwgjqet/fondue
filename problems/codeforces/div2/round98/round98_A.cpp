/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  04/09/2012 05:51:15 PM
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
	while(scanf("%s",s)!=EOF)
	{
		int l=strlen(s),cnt,ret=0;
		char pre='X';
		cnt=0;
		for(int i=0; i<l; i++)
		{
			if(s[i]!=pre)
			{
				pre=s[i];
				ret+=cnt/5+(cnt%5>0);
				cnt=1;
			}
			else
				cnt++;
		}
		ret+=cnt/5+(cnt%5>0);
		printf("%d\n",ret);
	}
	return 0;
}
