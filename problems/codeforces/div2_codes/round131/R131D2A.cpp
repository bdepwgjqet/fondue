/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  07/31/2012 07:52:27 PM
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

int main()
{
	int n,m,ret=0;
	scanf("%d%d",&n,&m);
	for(int a=0; a<=n; a++)
		for(int b=0; b<=n; b++)
		{
			if(a*a+b==n&&b*b+a==m)
				ret++;
		}
	printf("%d\n",ret);
	return 0;
}
