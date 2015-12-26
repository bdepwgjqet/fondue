/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  04/05/2012 08:57:31 PM
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
#define N 101000
#define inf 0x7fffffff
#define M 1000010
#define S 1000100
#define MOD 1000000007

typedef long long LL;
using namespace std;

inline int L(int i){ return i<<1; }
inline int R(int i){ return (i<<1)|1; }
inline int B(int i){ return 1<<i; }
inline int low_bit(int x){ return x&(-x); }

struct data{ int x,y,i; }dat[N];
int cnt[N],ret[10];

int cmp1(data a,data b)
{
	return a.x==b.x?a.y<b.y:a.x<b.x;
}

int cmp2(data a,data b)
{
	return a.y==b.y?a.x<b.x:a.y<b.y;
}

int cmp3(data a,data b)
{
	int aa=a.x-a.y,bb=b.x-b.y;
	return aa==bb?a.x<b.x:aa<bb;
}

int cmp4(data a,data b)
{
	int aa=a.x+a.y,bb=b.x+b.y;
	return aa==bb?a.x<b.x:aa<bb;
}

int main()
{
	int n,m,pre;
	memset(cnt,0,sizeof(cnt));
	scanf("%d%d",&n,&m);
	for(int i=0; i<m; i++)
	{
		scanf("%d%d",&dat[i].x,&dat[i].y);
		dat[i].i=i;
	}
	sort(dat,dat+m,cmp1);
	pre=-1;
	for(int i=0; i<m; i++)
	{
		if(pre==dat[i].x)
			cnt[dat[i].i]++;
		else
			pre=dat[i].x;
		if(i+1<m&&dat[i].x==dat[i+1].x)
			cnt[dat[i].i]++;
	}
	sort(dat,dat+m,cmp2);
	pre=-1;
	for(int i=0; i<m; i++)
	{
		if(pre==dat[i].y)
			cnt[dat[i].i]++;
		else
			pre=dat[i].y;
		if(i+1<m&&dat[i].y==dat[i+1].y)
			cnt[dat[i].i]++;
	}
	sort(dat,dat+m,cmp3);
	pre=inf;
	for(int i=0; i<m; i++)
	{
		int tmp=dat[i].x-dat[i].y;
		if(pre==tmp)
			cnt[dat[i].i]++;
		else
			pre=tmp;
		if(i+1<m&&tmp==dat[i+1].x-dat[i+1].y)
			cnt[dat[i].i]++;
	}
	sort(dat,dat+m,cmp4);
	pre=inf;
	for(int i=0; i<m; i++)
	{
		int tmp=dat[i].x+dat[i].y;
		if(pre==tmp)
			cnt[dat[i].i]++;
		else
			pre=tmp;
		if(i+1<m&&tmp==dat[i+1].x+dat[i+1].y)
			cnt[dat[i].i]++;
	}
	memset(ret,0,sizeof(ret));
	for(int i=0; i<m; i++)
		ret[cnt[i]]++;
	for(int i=0; i<9; i++)
		printf("%d ",ret[i]);
	puts("");
	return 0;
}
