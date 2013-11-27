/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  07/29/2012 11:01:58 AM
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
#define N 1000010
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

char s[N];
LL nob[N],now[N],dpb[N],dpw[N],cntb[N],cntw[N];
int n,k;

void init()
{
	cntb[0]=cntw[n]=0;
	for(int i=1; i<=n; i++)
		cntb[i]=cntb[i-1]+(s[i-1]=='B');
	for(int i=n-1; i>=0; i--)
		cntw[i]=cntw[i+1]+(s[i]=='W');
	nob[0]=now[n]=1;
	LL two=1;
	for(int i=1; i<=n; i++)
	{
		dpb[i]=0;
		if(i>=k&&cntw[i]==cntw[i-k])
		{
			if(i==k||s[i-k-1]!='B')
				dpb[i]=nob[max(i-k-1,0)];
		}
		two=1;
		if(s[i-1]=='X')
			two=2;
		nob[i]=(nob[i-1]*two-dpb[i])%MOD;
	}
	for(int i=n-1; i>=0; i--)
	{
		dpw[i]=0;
		if(i+k<=n&&cntb[i]==cntb[i+k])
		{
			if(i+k==n||s[i+k]!='W')
				dpw[i]=now[min(n,i+k+1)];
		}
		two=1;
		if(s[i]=='X')
			two=2;
		now[i]=(now[i+1]*two-dpw[i])%MOD;
	}
}

int main()
{
	while(scanf("%d%d%s",&n,&k,s)!=EOF)
	{
		init();
		LL ret=0,two=1,tmp;
		for(int i=0; i<n; i++)
		{
			if(s[i]=='X')
				two=(two*2)%MOD;
			tmp=(two-nob[i+1])%MOD;
			ret=(ret+tmp*dpw[i+1])%MOD;
		}
		cout<<(ret%MOD+MOD)%MOD<<endl;
	}
	return 0;
}
