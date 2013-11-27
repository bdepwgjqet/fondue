/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  07/13/2012 03:06:53 PM
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
#define X 60
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

int cnt[N],dat[N],ret,fi[N];
int ok(int x,int d)
{
	int ret=inf;
	for(int i=x; i<X; i+=d)
	{
		if(cnt[i]<=0)
			return 0;
	}
	return 1;
}

void add(int x,int d,int v)
{
	for(int i=x; i<X; i+=d)
		cnt[i]+=v;
}

void dfs(int lay,int now)
{
	int next;
	if(lay>17)
		return;
	for(int i=now; i<X; i++)
		if(lay+cnt[i]>ret)
			return;

	if(now>=60)
	{
		ret=min(ret,lay);
		return;
	}
	if(cnt[now]==0)
	{
		for(next=now; next<X; next++)
			if(cnt[next]>0)
				break;
		dfs(lay,next);
		return;
	}
	for(int i=dat[0]; i<now-i; i++)
	{
		if(fi[i]>0)
		{
			if(ok(now,now-i))
			{
				add(now,now-i,-1);
				fi[i]--;
				dfs(lay,now);
				fi[i]++;
				add(now,now-i,1);
			}
		}
	}
	if(2*now+1<X)
	{
		fi[now]++;
		cnt[now]--;
		dfs(lay+1,now);
		fi[now]--;
		cnt[now]++;
	}
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
		{
			puts("0");
			continue;
		}
		memset(fi,0,sizeof(fi));
		memset(cnt,0,sizeof(cnt));
		for(int i=0; i<n; i++)
		{
			scanf("%d",&dat[i]);
			cnt[dat[i]]++;
		}
		ret=inf;
		dfs(0,dat[0]);
		printf("%d\n",ret);
	}
	return 0;
}
