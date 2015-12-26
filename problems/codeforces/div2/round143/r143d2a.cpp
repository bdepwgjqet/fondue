/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  10/07/2012 11:28:44 PM
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
	int n,ret=0;
	scanf("%d",&n);
	for(int i=0; i<n; i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		if(x+y+z>=2)
			ret++;
	}
	printf("%d\n",ret);
	return 0;
}
