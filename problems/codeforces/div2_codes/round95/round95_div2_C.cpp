/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  04/05/2012 07:27:34 PM
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

LL c[31][31];

void init()
{
	c[0][0]=1,c[1][1]=1;
	c[1][0]=1;
	for(int i=2; i<31; i++)
	{
		c[i][0]=1;
		for(int j=1; j<i; j++)
		{
			c[i][j]=c[i-1][j]+c[i-1][j-1];
		}
		c[i][i]=1;
	}
}

int main()
{
	int n,m,t;
	init();
	while(scanf("%d%d%d",&n,&m,&t)!=EOF)
	{
		LL ret=0;
		for(int i=4; t-i>=1&&i<=n; i++)
		{
			if(t-i<=m)
				ret+=c[n][i]*c[m][t-i];
		}
		cout<<ret<<endl;
	}
	return 0;
}


