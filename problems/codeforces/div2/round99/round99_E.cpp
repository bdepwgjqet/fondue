/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  04/11/2012 10:13:07 PM
 ***/

#include <cstring>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <functional>
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

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

inline int L(int i){ return i<<1; }
inline int R(int i){ return (i<<1)|1; }
inline int B(int i){ return 1<<i; }
inline int low_bit(int x){ return x&(-x); }

vector<pii> tr;
vector<pii> mu;

int cmp(pii a,pii b){ return a.first<b.first; }

int main()
{
	int n,m,x,h,l,r,w;
	double ret,p;
	scanf("%d%d",&n,&m);
	for(int i=0; i<n; i++)
	{
		scanf("%d%d%d%d",&x,&h,&l,&r);
		tr.PB(MP(x-h,l));
		tr.PB(MP(x,-l));
		tr.PB(MP(x+1,r));
		tr.PB(MP(x+h+1,-r));
	}
	for(int i=0; i<m; i++)
	{
		scanf("%d%d",&x,&w);
		mu.PB(MP(x,w));
	}
	sort(ALL(tr),cmp);
	sort(ALL(mu),cmp);
	int j=0,zero=0;
	p=0,ret=0;
	for(int i=0; i<mu.size(); i++)
	{
		x=mu[i].first,w=mu[i].second;
		for(; j<tr.size()&&x>=tr[j].first; j++)
		{
			double pp;
			if(tr[j].second>=0)
			{
				pp=1-tr[j].second/100.0;
				if(pp>0)
					p+=log(pp);
				else
					zero++;
			}
			else
			{
				pp=1+tr[j].second/100.0;
				if(pp>0)
					p-=log(pp);
				else
					zero--;
			}
		}
		if(zero==0)
			ret+=exp(p)*w;
	}
	printf("%.4lf\n",ret);
	return 0;
}
