/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  08/14/2012 11:25:55 PM
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

LL lf[N];
map<LL,int> mp;

int main()
{
	LL k,b,n,ret,ze,cnt;
	int x;
	while(cin>>k>>b>>n)
	{
		lf[0]=0;
		ret=0;
		ze=0;
		cnt=0;
		mp.clear();
		for(int i=1; i<=n; i++)
		{
			scanf("%d",&x);
			lf[i]=(lf[i-1]+x)%(k-1);
			if(x==0)
				cnt++;
			else
				ze+=cnt*(cnt+1)/2,cnt=0;
		}
		ze+=(cnt+1)*cnt/2;
		LL y;
		for(int i=0; i<=n; i++)
		{
			if(mp.count(lf[i])>0)
				ret+=mp[lf[i]];
			y=(lf[i]+b)%(k-1);
			if(mp.count(y)>0)
				mp[y]++;
			else
				mp[y]=1;
		}
		if(b==k-1)
			ret-=ze;
		else if(b==0)
			ret=ze;
		cout<<ret<<endl;
	}
	return 0;
}
