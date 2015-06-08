/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  10/07/2012 11:29:02 PM
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

int dat[N];
map<int,int> mp;
map<int,int>::iterator it;
LL dp[N],sum[N],csum[N];
struct node{ int x,c; }no[N];

int get(int i,int k)
{
	int l=0,r=i,mid;
	for(; l<=r; )
	{
		mid=(l+r)>>1;
		if(sum[i]-sum[mid]-csum[mid]*(no[i].x-no[mid].x)<=k)
			r=mid-1;
		else
			l=mid+1;
	}
	return l;
}

int main()
{
	int n,k;
	while(scanf("%d%d",&n,&k)+1)
	{
		mp.clear();
		for(int i=1; i<=n; i++)
		{
			scanf("%d",&dat[i]);
			mp[dat[i]]++;
		}
		int top=0;
		for(it=mp.begin(); it!=mp.end(); it++)
		{
			no[top].x=it->first;
			no[top++].c=it->second;
		}
		sum[0]=0;
		csum[0]=0;
		for(int i=1; i<top; i++)
		{
			sum[i]=sum[i-1]+(csum[i-1]+no[i-1].c)*(no[i].x-no[i-1].x);
			csum[i]=csum[i-1]+no[i-1].c;
		}
		dp[0]=no[0].c;
		for(int i=1; i<top; i++)
		{
			int id=get(i,k);
			LL lf=k-(sum[i]-sum[id]-csum[id]*(no[i].x-no[id].x));
			int now=csum[i]-csum[id]+no[i].c;
			if(id>0)
			{
				now+=lf/(no[i].x-no[id-1].x);
			}
			dp[i]=now;
		}
		LL ret=0,id=-1;
		for(int i=0; i<top; i++)
		{
			if(ret<dp[i])
				ret=dp[i],id=i;
		}
		int ans=int(ret);
		printf("%d %d\n",ans,no[id].x);
	}
	return 0;
}
