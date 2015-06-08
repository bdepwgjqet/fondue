/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  04/24/2012 10:57:23 PM
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

char s[N],t[N];
int p[N],plist[N],top;
int ps[N],ts,cnt[N],ret,ls,lt;

void init()
{
	top=0;
	for(int i=0; i<N; i++)
		p[i]=i;
	for(int i=2; i<N; i++)
	{
		if(p[i]==i)
			plist[top++]=i;
		for(int j=0; j<top&&i*plist[j]<N; j++)
		{
			p[i*plist[j]]=plist[j];
			if(i%plist[j]==0)
				break;
		}
	}
}

int ok(int l)
{
	for(int i=1; i*l<ls; i++)
	{
		for(int j=0; j<l; j++)
			if(s[i*l+j]!=s[j])
				return 0;
	}
	for(int i=0; i*l<lt; i++)
	{
		for(int j=0; j<l; j++)
			if(t[i*l+j]!=s[j])
				return 0;
	}
	return 1;
}

void dfs(int now,int id)
{
	int tmp;
	if(lt%now)	return;
	if(id==ts)
	{
		if(ok(now))
			ret++;
		return;
	}
	tmp=now;
	dfs(tmp,id+1);
	for(int i=0; i<cnt[id]; i++)
	{
		tmp*=ps[id];
		dfs(tmp,id+1);
	}
}

int main()
{
	init();
	while(scanf("%s%s",s,t)!=EOF)
	{
		ls=strlen(s);
		lt=strlen(t);
		memset(cnt,0,sizeof(cnt));
		ts=0;
		int x;
		for(x=ls; x>1; )
		{
			int tmp=x;
			ps[ts++]=p[x];
			cnt[ts-1]=1;
			for(; tmp%p[x]==0; )
				tmp/=p[x],cnt[ts-1]++;
			x=tmp;
		}
		//printf("%d\n",ps[0]);
		ret=0;
		dfs(1,0);
		printf("%d\n",ret);
	}
	return 0;
}
