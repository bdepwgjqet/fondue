/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  10/25/2012 11:25:18 PM
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

int p[N],plist[N],top,cnt[N];

void init()
{
	top=0;
	for(int i=0; i<N; i++)
		p[i]=i;
	for(int i=2; i<N; i++)
	{
		if(p[i]==i)
			plist[top++]=i;
		for(int j=0; i*plist[j]<N&&j<top; j++)
		{
			p[i*plist[j]]=plist[j];
			if(i%plist[j]==0)
				break;
		}
	}
	cnt[0]=0,cnt[1]=0;
	for(int i=2; i<N; i++)
		cnt[i]=cnt[i-1]+(p[i]==i);
}

int a,b,k;

int ok(int l)
{
	for(int i=a; i<=b-l+1; i++) 
	{
		if(cnt[i+l-1]-cnt[i-1]<k)
			return 0;
	}
	return 1;
}

int main()
{
	init();
	while(scanf("%d%d%d",&a,&b,&k)+1)
	{
		int l=1,r=b-a+1;
		for(; l<=r;)
		{
			int mid=(l+r)>>1;
			if(ok(mid))
				r=mid-1;
			else
				l=mid+1;
		}
		if(l>b-a+1)
			puts("-1");
		else
			printf("%d\n",l);
	}
	return 0;
}
