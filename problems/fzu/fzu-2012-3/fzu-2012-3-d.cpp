/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  03/19/2012 04:39:27 PM
 ***/
#include <cstring>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>
#define MAXN 1010
#define MAXM 1000010
#define MOD 1000000007
#define N 100011
#define X 26

typedef long long LL;
using namespace std;

inline int L(int i){ return i<<1; }
inline int R(int i){ return (i<<1)|1; }
inline int max(int a,int b){ return a<b?b:a; }
inline int min(int a,int b){ return a<b?a:b; }
inline int abs(int x){ return x<0?-x:x; }

int n,l,rtop;
char s[N],ret[N];
vector<int> q[N];

void init()
{
	q[0].clear();
	for(int i=0; i<l; i++)
		q[0].push_back(i);
	rtop=0;
}

int dfs(int v)
{
	int cnt[X]={0},top=q[v].size();
	/*
	for(int i=0; i<top; i++)
		printf("%d ",q[v][i]);
	puts("");
	*/
	if(v==l)
		return 0;
	for(int i=0; i<top; i++)
		cnt[s[q[v][i]+v]-'a']++;
	/*
	for(int i=0; i<4; i++)
		printf("%d ",cnt[i]);
	puts("");
	*/
	for(int i=0; i<X; i++)
	{
		q[v+1].clear();
		if(cnt[i]==n)
		{
			//printf("%d %d\n",n,cnt[i]);
			ret[rtop++]=i+'a';
			return 1;
		}
		else if(cnt[i]>n)
		{
			ret[rtop++]=i+'a';
			for(int j=0; j<top; j++)
				if(s[q[v][j]+v]-'a'==i&&q[v][j]+v+1<l)
					q[v+1].push_back(q[v][j]);
			if(dfs(v+1))
				return 1;
			else
				rtop--;
		}
	}
	return 0;
}

int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		scanf("%s",s);
		l=strlen(s);
		init();
		if(dfs(0))
		{
			for(int i=0; i<rtop; i++)
				printf("%c",ret[i]);
			puts("");
		}
		else
			puts("impossible");
	}
	return 0;
}
