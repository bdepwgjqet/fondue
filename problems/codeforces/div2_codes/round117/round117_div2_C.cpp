/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  04/24/2012 10:57:28 PM
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
#define N 100010
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

inline int L(int i){ return i<<1; }
inline int R(int i){ return (i<<1)|1; }
inline int B(int i){ return 1<<i; }
inline int low_bit(int x){ return x&(-x); }

int n,l,k;

struct myset
{
	myset(){ schg=ssta=0; }
	multiset<int,less<int> > chg;
	multiset<int,greater<int> >sta;
	LL schg,ssta;
	void erase(int x)
	{
		if(sta.count(x)<=0)
		{
			chg.erase(chg.find(x)),schg-=x;
			if(sta.size()>0)
			{
				x=*sta.begin();
				sta.erase(sta.begin());
				chg.insert(x);
				ssta-=x;
				schg+=x;
			}
		}
		else
			sta.erase(sta.find(x)),ssta-=x;
	}
	void insert(int x)
	{
		if(chg.size()==k)
		{
			chg.insert(x);
			schg+=x;
			x=*chg.begin();
			chg.erase(chg.begin());
			schg-=x;
			sta.insert(x);
			ssta+=x;
		}
		else
			chg.insert(x),schg+=x;

	}
}pos,neg;

int dat[N];

void erase(int x)
{
	if(x>=0)
		pos.erase(x);
	else
		neg.erase(-x);
}

void insert(int x)
{
	if(x>=0)
		pos.insert(x);
	else
	{
		neg.insert(-x);
	}
}

LL solve()
{
	return max(pos.schg+pos.ssta+neg.schg-neg.ssta,neg.schg+neg.ssta+pos.schg-pos.ssta);
}

int main()
{
	LL ret;
	scanf("%d%d",&n,&l);
	for(int i=0; i<n; i++)
		scanf("%d",&dat[i]);
	scanf("%d",&k);
	ret=0;
	for(int i=0; i<n; i++)
	{
		if(i>=l)
			erase(dat[i-l]);
		insert(dat[i]);
		//printf("%lld %lld %lld %lld\n",pos.schg,pos.ssta,neg.schg,neg.ssta);
		if(i>=l-1)
			ret=max(ret,solve());
	}
	printf("%I64d\n",ret);
	return 0;
}
