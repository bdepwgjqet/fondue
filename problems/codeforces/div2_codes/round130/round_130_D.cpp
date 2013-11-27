/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  07/23/2012 11:12:52 PM
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

LL ret[N],dat[N],a[10];

int main()
{
	int n;
	LL left;
	while(scanf("%d",&n)!=EOF)
	{
		memset(ret,0,sizeof(ret));
		int x;
		for(int i=0; i<n; i++)
			cin>>dat[i];
		for(int i=0; i<5; i++)
		{
			cin>>a[i];
		}
		LL pre=0,left=0;
		for(int i=0; i<n; i++)
		{
			LL x=dat[i]+pre;
		//	cout<<x<<endl;
			for(int j=4; j>=0; j--)
			{
				if(x>=a[j])
				{
					ret[j]+=x/a[j];
					x%=a[j];
				}
			}
			pre=x;
		}
		cout<<ret[0];
		for(int i=1; i<5; i++)
			cout<<" "<<ret[i];
		cout<<endl;
		cout<<pre<<endl;
	}
	return 0;
}
