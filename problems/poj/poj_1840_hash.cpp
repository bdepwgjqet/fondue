/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  07/07/2012 03:28:59 PM
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
#define N 201000
#define M 1000010
#define S 1000100
#define eps 1e-8
#define inf 0x3fffffff
#define MOD 100003
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

struct hash{ int x,c; hash *next; }*h[N],*tmp,*t,*pre,*p[N];
int top;
int a[6];

void init()
{
	for(int i=0; i<N; i++)
	{
		h[i]=NULL;
		p[i]=new hash;
	}
	top=0;
}

void add(int x)
{
	int y=(x%MOD+MOD)%MOD;
	tmp=pre=h[y];
	for(; tmp!=NULL; )
	{
		if(tmp->x==x)
		{
			tmp->c++;
			return;
		}
		if(tmp->next!=NULL)
			pre=pre->next;
		tmp=tmp->next;
	}
	t=p[top++];
	t->x=x;
	t->next=NULL;
	t->c=1;
	if(pre==NULL)
		h[y]=t;
	else
		pre->next=t;
}

int calc(int x)
{
	int y=(x%MOD+MOD)%MOD;
	if(h[y]==NULL)
		return 0LL;
	tmp=h[y];
	for(; tmp!=NULL;)
	{
		if(tmp->x==x)
			return tmp->c;
		tmp=tmp->next;
	}
	return 0;
}

int main()
{
	init();
	for(int i=0; i<5; i++)
		scanf("%d",&a[i]);
	for(int i=-50; i<=50; i++)
		for(int j=-50; j<=50; j++)
		{
			if(i==0||j==0)
				continue;
			int x=a[0]*i*i*i+a[1]*j*j*j;
			add(x);
		}
	int ret=0;
	for(int i=-50; i<=50; i++)
		for(int j=-50; j<=50; j++)
			for(int k=-50; k<=50; k++)
			{
				if(i==0||j==0||k==0)
					continue;
				int x=a[2]*i*i*i+a[3]*j*j*j+a[4]*k*k*k;
				x=-x;
				ret+=calc(x);
			}
	printf("%d\n",ret);
	return 0;
}
