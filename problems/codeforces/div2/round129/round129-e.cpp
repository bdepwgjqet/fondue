/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  07/12/2012 01:06:22 AM
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
#define N 201000
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

char sa[N],sb[N];
LL mat[30][N],tra[30][N];

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		double ret=0;
		scanf("%s%s",sa,sb);
		memset(mat,0,sizeof(mat));
		memset(tra,0,sizeof(tra));
		for(int i=0; i<26; i++)
		{
			for(int j=0; j<n; j++)
			{
				if(sb[j]-'A'==i)
					mat[i][j+1]=mat[i][j]+j+1;
				else
					mat[i][j+1]=mat[i][j];
			}
			for(int j=n-1; j>=0; j--)
			{
				if(sb[j]-'A'==i)
					tra[i][j+1]=tra[i][j+2]+n-j;
				else
					tra[i][j+1]=tra[i][j+2];
			}
		}
		for(int i=0; i<26; i++)
			for(int j=0; j<n; j++)
			{
				if(sa[j]-'A'==i)
				{
					ret+=1.0*mat[i][j+1]*(n-j)+1.0*tra[i][j+1]*(j+1);
					if(sb[j]-'A'==i)
						ret-=1.0*(j+1)*(n-j);
				}
			}
		printf("%.9lf\n",6.0*ret/n/(n+1)/(2*n+1));
	}
	return 0;
}
