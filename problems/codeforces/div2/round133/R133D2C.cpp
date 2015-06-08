/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  08/14/2012 11:25:38 PM
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
int ret[S];

int main()
{
	int n,m,k,top;
	while(scanf("%d%d%d",&n,&m,&k)!=EOF)
	{
		top=0;
		if(k==1)
		{
			int now=1;
			for(; now<1+n+m;)
			{
				ret[top++]=now;
				now+=n-1;
			}
			printf("%d\n",top);
			for(int i=0; i<top; i++)
				printf("%d ",ret[i]);
			puts("");
		}
		else
		{
			top=1;
			ret[0]=1;
			int now=n;
			top=2,ret[1]=n;
			if(m==n)
				printf("%d\n",top*k+1);
			else
				printf("%d\n",top*k);
			for(int i=0; i<k; i++)
				printf("1 ");
			for(int i=1; i<top; i++)
			{
				printf("%d ",ret[i]);
				for(int j=1; j<k; j++)
					printf("%d ",ret[i]+1);
			}
			if(m==n)
				printf("%d ",2*n);
			puts("");
		}
	}
	return 0;
}
