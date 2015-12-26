/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  07/15/2012 08:37:28 PM
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
int n,k;
LL dat[N],ret;
int tag[N];

int ok(int sig)
{
	LL sum=0;
	int cnt=0;
	for(int i=n-1; i>=0; i--)
	{
		if(sum+dat[i]>ret)
		{
			tag[i]=1;
			cnt++;
			if(cnt>=k)
				return 0;
			sum=dat[i];
		}
		else
			sum+=dat[i];
		if(sig)
		{
			if(k-cnt-1==i+1)
				for(int j=0; j<=i; j++)
					tag[j]=1;
		}
	}
	return 1;
}

void show()
{
	for(int i=0; i<n-1; i++)
	{
		printf("%lld ",dat[i]);
		if(tag[i])
			printf("/ ");
	}
	printf("%lld\n",dat[n-1]);
}

int main()
{
	int t;
	LL l,r;
	scanf("%d",&t);
	while(t--)
	{
		l=0,r=0;
		scanf("%d%d",&n,&k);
		for(int i=0; i<n; i++)
		{
			scanf("%lld",&dat[i]);
			r+=dat[i];
			l=max(l,dat[i]);
		}
		for(; l<=r;)
		{
			ret=(l+r)>>1;
			if(ok(0))
				r=ret-1;
			else
				l=ret+1;
		}
		memset(tag,0,sizeof(tag));
		ret=l;
		ok(1);
		show();
	}
	return 0;
}
