/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  10/07/2012 11:29:06 PM
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
int a[6];
int xx,yy,zz,xx1,yy1,zz1;

int ok(int i)
{
	if(i==0)
		return yy<0;
	if(i==1)
		return yy>yy1;
	if(i==2)
		return zz<0;
	if(i==3)
		return zz>zz1;
	if(i==4)
		return xx<0;
	return xx>xx1;
}

int main()
{
	while(scanf("%d%d%d%d%d%d",&xx,&yy,&zz,&xx1,&yy1,&zz1)+1)
	{
		int ret=0;
		for(int i=0; i<6; i++)
			scanf("%d",&a[i]);
		for(int i=0; i<6; i++)
			if(ok(i))
				ret+=a[i];
		printf("%d\n",ret);
	}
	return 0;
}
