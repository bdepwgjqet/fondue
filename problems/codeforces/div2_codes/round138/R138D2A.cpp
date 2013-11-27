/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  09/16/2012 11:32:41 PM
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
	int a,b,c,ret; 
	while(scanf("%d%d%d",&a,&b,&c)!=EOF)
	{
		ret=0;
		for(int i=1; i*i<=a; i++)
		{
			if(a%i==0)
			{
				int j=a/i;
				for(int k=1; k<=b&&k<=c; k++)
				{
					if(b%k==0&&c%k==0)
					{
						if((i==b/k&&j==c/k)||(i==c/k&&j==b/k))
						{
							printf("%d\n",4*(i+j+k));
							return 0;
						}
					}
				}
			}
		}
	}
	return 0;
}
