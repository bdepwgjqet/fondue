/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  10/07/2012 11:28:53 PM
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

int dat[N];

int main()
{
	int n,d,l;
	while(scanf("%d%d%d",&n,&d,&l)+1)
	{
	for(int i=1; i<n; i++)
	{
		if(d>l)
		{
			dat[i]=l;
			d=dat[i]-d;
		}
		else if(d<1)
		{
			dat[i]=1;
			d=dat[i]-d;
		}
		else
		{
			dat[i]=l;
			d=dat[i]-d;
		}
	}
	if(d<1||d>l)
		puts("-1");
	else
	{
		for(int i=1; i<n; i++)
			printf("%d ",dat[i]);
		printf("%d\n",d);
	}
	}
	return 0;
}
