/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  08/14/2012 11:25:24 PM
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

int a[10];
int cmp(int a,int b){ return a<b; }

int main()
{
	while(scanf("%d%d%d",&a[0],&a[1],&a[2])!=EOF)
	{
		sort(a,a+3,cmp);
		int now=a[0],ret=0;
		for(int i=0; i<a[1]-1; i++)
			ret+=2*now,now++;
		for(int i=a[1]; i<=a[2]; i++)
			ret+=now;
		printf("%d\n",ret);
	}
	return 0;
}
