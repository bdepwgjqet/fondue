/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  08/06/2012 11:29:00 PM
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
	int n,m,s;
	while(scanf("%d%d%d",&n,&m,&s)!=EOF)
	{
		LL ret=0;
		int d,aa,bb,cc,dd,x,y,ss;
		for(int a=0; 2*a<n; a++)
			for(int b=0; 2*b<m; b++)
				for(int c=0; c<=a; c++)
				{
					aa=2*a+1,bb=2*b+1,cc=2*c+1;
					ss=s;
					if(ss==aa*bb)
					{
						ret+=(n-2*a)*(m-2*b)*(1+(a>c))*(b+1);
					}
					else if(ss>aa*bb)
					{
						ss-=aa*bb;
						ss+=cc*bb;
						if(ss%cc==0)
						{
							ss/=cc;
							ss-=1;
							if(ss>=0&&ss%2==0)
							{
								d=ss/2;
								if(d>b&&2*d<m)
								{
									ret+=(n-2*a)*(m-2*d)*(1+(a>c));
								}
							}
						}
					}
				}
		cout<<ret<<endl;
	}
	return 0;
}
