/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  07/19/2012 12:47:55 PM
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
#define N 1010
#define M 1000010
#define S 1000100
#define eps 1e-8
#define inf 0x3fffffff
#define MOD 100000007
#define PB push_back
#define MP make_pair
#define SZ(a) ((int)((a).size()))
#define ALL(a) (a).begin(),(a).end()
#define CLR(a,x) memset(a,x,sizeof(a))

typedef long long LL;
using namespace std;

LL g[N][2*N],f[N][2*N];

int main()
{
	memset(f,0,sizeof(f));
	memset(g,0,sizeof(g));
	for(int i=1; i<N; i++)
		g[i][1]=1;
	f[1][2]=1;
	for(int i=2; i<N; i++)
		for(int j=2; j<=i+i; j++)
		{
			f[i][j]=((f[i-1][j-2]+g[i-1][j-2])+2*(f[i-1][j-1]+g[i-1][j-1])+f[i-1][j])%MOD;
			g[i][j]=((f[i-1][j-1]+g[i-1][j-1])+(f[i-1][j]+g[i-1][j])+f[i-1][j])%MOD;
		}
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		cout<<(f[x][y]+g[x][y])%MOD<<endl;
	}
	return 0;
}
