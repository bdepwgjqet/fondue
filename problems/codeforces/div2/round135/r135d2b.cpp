/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  08/27/2012 11:39:10 PM
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

LL ten[29];

int main()
{
	LL p,b;
	ten[0]=1;
	for(int i=1; i<29; i++)
		ten[i]=ten[i-1]*10;
	while(cin>>p>>b)
	{
		LL now,ret;
		int id;
		for(int i=18; i>0; i--)
		{
			if(p<ten[i])
				continue;
			now=ten[i]-1;
			id=(p/ten[i])%10;
			for(int j=id; j>=0; j--)
			{
				LL y;
				if(i==18)
					y=j*ten[i]+now;
				else
					y=(p/ten[i+1]*10+j)*ten[i]+now;
				LL x=p-y;
				if(x>=0&&x<=b)
				{
					cout<<y<<endl;
					return 0;
				}
			}
		}
		cout<<p<<endl;
	}
	return 0;
}
