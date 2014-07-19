/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  07/21/2012 08:39:30 PM
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
#define MOD 1000000007
#define PB push_back
#define MP make_pair
#define SZ(a) ((int)((a).size()))
#define ALL(a) (a).begin(),(a).end()
#define CLR(a,x) memset(a,x,sizeof(a))

typedef long long LL;
using namespace std;

LL mat[N][N],tag[N],now[N][N],tmp[N][N];

LL calc(int n,int t)
{
	LL ret=0;
	memset(now,0,sizeof(now));
	for(int i=0; i<n; i++)
		now[i][i]=1;
	for(int k=0; k<t; k++)
	{
		memset(tmp,0,sizeof(tmp));
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				for(int u=0; u<n; u++)
					tmp[i][j]+=now[i][u]*mat[u][j];
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				now[i][j]=tmp[i][j];
	}
	for(int i=0; i<n; i++)
		if(tag[i]==1)
			ret+=now[0][i];
	return ret;
}

int main()
{
	int t,n,x,y,z;
	scanf("%d",&t);
	for(; t--;)
	{
		scanf("%d",&n);
		memset(mat,0,sizeof(mat));
		for(int i=0; i<n; i++)
		{
			int ii,tt;
			scanf("%d%d%d%d%d",&ii,&x,&y,&z,&tt);
			ii-=1,x-=1,y-=1,z-=1;
			tag[ii]=tt;
			mat[ii][x]++;
			mat[ii][y]++;
			mat[ii][z]++;
		}
		scanf("%d",&x);
		cout<<calc(n,x)<<endl;
	}
	return 0;
}
