/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  08/19/2012 02:52:11 PM
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
	int n,k,now;
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		for(int i=0; i<2*n+1; i++)
			scanf("%d",&dat[i]);
		for(int i=0; i<2*n+1; i++)
		{
			if(k>0)
			{
				if(i>0&&i<2*n)
				{
					if(dat[i]-1>dat[i-1]&&dat[i]-1>dat[i+1])
						now=dat[i]-1,k--;
					else
						now=dat[i];
				}
				else
					now=dat[i];
			}
			else
				now=dat[i];
			printf("%d ",now);
		}
		puts("");
	}
	return 0;
}
