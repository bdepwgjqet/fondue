/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  07/21/2012 08:01:28 PM
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

LL a,b,c,d,e,f,g,h,i,j,k,m;

LL ff(LL a,LL b,LL c,LL x)
{
	return a*x*x+b*x+c;
}

int main()
{
	int t;
	LL ret,x;
	scanf("%d",&t);
	while(t--)
	{
		cin>>m>>a>>b>>c>>d>>e>>f>>g>>h>>i>>j>>k;
		ret=0;
		x=0;
		for(; ret<m;)
		{
			x++;
			LL wi=(j*x+k)%3;
			if(wi==0)
				ret+=ff(a,b,c,x);
			else if(wi==1)
				ret+=ff(d,e,f,x);
			else
				ret+=ff(g,h,i,x);
		}
		cout<<x<<endl;
	}
	return 0;
}
