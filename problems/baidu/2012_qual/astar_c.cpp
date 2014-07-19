/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  06/02/2012 10:56:18 AM
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

inline int L(int i){ return i<<1; }
inline int R(int i){ return (i<<1)|1; }
inline int B(int i){ return 1<<i; }
inline int low_bit(int x){ return x&(-x); }

struct seg{ LL l,r; }se[N];
int cmp(seg a,seg b){ return a.l==b.l?a.r<b.r:a.l<b.l; }

int main()
{
	int n;
	LL ret=0,pre,l,r,ll,rr,nl,nr,nll,nrr;
	scanf("%d",&n);
	for(int i=0; i<n; i++)
	{
		cin>>se[i].l>>se[i].r;
	}
	sort(se,se+n,cmp);
	l=ll=se[0].l,r=rr=se[0].r,pre=0;
	for(int i=1; i<n; i++)
	{
		if(se[i].r<=rr)
		{
			nl=se[i].l,nr=min(se[i].r,r);
			nll=ll,nrr=max(rr,se[i].r);
			//cout<<nl<<" "<<nr<<" "<<nll<<" "<<nrr<<" "<<endl;
			if((nr-nl)*(nrr-nll)>ret)
				ret=(nr-nl)*(nrr-nll);
				continue;
		}


		if(se[i].l>r)
		{
			pre=0;
			l=se[i].l;
			r=se[i].r;
			ll=se[i].l;
			rr=se[i].r;
		}
		else
		{
			nl=se[i].l,nr=r;
			nll=ll,nrr=se[i].r;
			if((nr-nl)*(nrr-nll)>pre)
			{
				pre=(nr-nl)*(nrr-nll);
				l=nl,r=nr,ll=nll,rr=nrr;
			}
		}
		ret=max(ret,pre);
	}
	cout<<ret<<endl;
	return 0;
}
