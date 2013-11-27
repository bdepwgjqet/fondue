/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  09/16/2012 11:42:20 PM
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
#define N 101000
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

map<int,int> mp;
int dat[N];

int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1; i<=n; i++)
	{
		scanf("%d",&dat[i]);
	}
	int l=1,r=-1;
	for(; l<n; l++)
		if(dat[l]!=dat[l+1])
			break;
	for(int i=l; i<=n; i++)
	{
		mp[dat[i]]++;
		if(mp.size()==k)
		{
			r=i;
			break;
		}
	}
	if(r==-1)
		puts("-1 -1");
	else
	{
		for(; l<=r;)
		{
			if(mp[dat[l]]>1)
			{
				mp[dat[l]]--;
				l++;
			}
			else
				break;
		}
		printf("%d %d\n",l,r);
	}
	return 0;
}
