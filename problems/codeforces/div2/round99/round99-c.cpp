/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  04/10/2012 11:09:02 AM
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
#define N 2610
#define M 1000010
#define S 1000100
#define eps 1e-8
#define inf 0x3fffffff
#define MOD 1000000007
#define PB push_back
#define SZ(a) ((int)((a).size()))
#define ALL(a) (a).begin(),(a).end()
#define CLR(a,x) memset(a,x,sizeof(a))

typedef long long LL;
using namespace std;

inline int L(int i){ return i<<1; }
inline int R(int i){ return (i<<1)|1; }
inline int B(int i){ return 1<<i; }
inline int low_bit(int x){ return x&(-x); }

int tag[N];
int id[4],l[4];
char s[4][5*N];
char ans[4][5]={"aaaa","aabb","abab","abba"};

inline int is_v(char x)
{
	return x=='a'||x=='e'||x=='i'||x=='o'||x=='u';
}

int equ(int idi,int idj)
{
	int a=id[idi],b=id[idj],la=l[idi],lb=l[idj];
	if(a<0||b<0)	return 0;
	if(la-a!=lb-b)	return 0;
	int i,j;
	for(i=a,j=b; i<la; i++,j++)
		if(s[idi][i]!=s[idj][j])
			return 0;
	return 1;
}

int get_id()
{
	if(equ(0,1))
	{
		if(equ(1,2)&&equ(2,3))
			return 4;
		if(equ(2,3))
			return 1;
		return 0;
	}
	else if(equ(0,2))
	{
		if(equ(1,3))
			return 2;
		return 0;
	}
	else if(equ(0,3))
	{
		if(equ(1,2))
			return 3;
		return 0;
	}
	return 0;
}

int main()
{
	int cnt,ret=-1,top=0,x,n,k;
	scanf("%d%d",&n,&k);
	for(int i=0; i<n; i++)
	{
		for(int u=0; u<4; u++)
			scanf("%s",s[u]);
		if(ret>=0)	continue;
		for(int u=0; u<4; u++)
		{
			int j;
			cnt=0;
			l[u]=strlen(s[u]);
			for(j=l[u]-1; j>=0; j--)
			{
				if(is_v(s[u][j]))
					cnt++;
				if(cnt==k)
					break;
			}
			if(cnt<k)
				id[u]=-1;
			else
				id[u]=j;
		}
		x=get_id();
		if(x==0)
			ret=0;
		else if(x<4)
			tag[top++]=x;
	}
	if(ret==0)
		puts("NO");
	else
	{
		if(top==0)
			puts("aaaa");
		else
		{
			sort(tag,tag+top);
			if(tag[0]!=tag[top-1])
				puts("NO");
			else
				puts(ans[tag[0]]);
		}
	}
	return 0;
}
