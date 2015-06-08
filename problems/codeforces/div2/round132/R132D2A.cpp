/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  08/06/2012 11:28:39 PM
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

int a[N],b[N];

int main()
{
	int n,m;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0; i<n; i++)
			scanf("%d",&a[i]);
		scanf("%d",&m);
		for(int j=0; j<m; j++)
			scanf("%d",&b[j]);
		int ret=0;
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				if(b[j]%a[i]==0)
				{
					ret=max(ret,b[j]/a[i]);
				}
		int cnt=0;
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				if(b[j]%a[i]==0)
				{
					if(b[j]/a[i]==ret)
						cnt++;
				}
		printf("%d\n",cnt);
	}
	return 0;
}
