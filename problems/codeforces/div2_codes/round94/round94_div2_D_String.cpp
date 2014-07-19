/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  03/16/2012 02:55:44 PM
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
#define N 100001

typedef long long LL;
using namespace std;

inline int L(int i){ return i<<1; }
inline int R(int i){ return (i<<1)|1; }
inline int max(int a,int b){ return a<b?b:a; }
inline int min(int a,int b){ return a<b?a:b; }
inline int abs(int x){ return x<0?-x:x; }

int id[N],v,top,rtop;
LL cnt[30],l,same[30];
char s[N],ret[N];

void init()
{
	int i;
	for(i=0; i<l; i++)
		id[i]=i;
	top=l;
	rtop=0;
	v=0;
}

int solve(int &k)
{
	int i,j,tmpt;
	memset(cnt,0,sizeof(cnt));
	memset(same,0,sizeof(same));
	for(i=0; i<top; i++)
	{
		cnt[s[id[i]+v]-'a']+=l-id[i]-v;
		same[s[id[i]+v]-'a']++;
	}
	for(i=0; i<26; i++)
		if(k<=cnt[i])
		{
			ret[rtop++]=i+'a';
			if(same[i]>=k)
				return 0;
			else
				k-=same[i];
			for(tmpt=j=0; j<top&&id[j]+v<l; j++)
				if(s[id[j]+v]==i+'a')
					id[tmpt++]=id[j];
			v++;
			top=tmpt;
			return 1;
		}
		else
			k-=cnt[i];
	return -1;	//impossible
}

int main()
{
	int k,i;
	LL len;
	scanf("%s%d",s,&k);
	l=strlen(s);
	init();
	len=((LL)l)*(l+1)/2;
	if(len<k)
		puts("No such line.");
	else
	{
		while(solve(k));
		puts(ret);
	}
	return 0;
}
