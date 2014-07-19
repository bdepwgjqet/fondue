/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  08/27/2012 11:24:40 PM
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

int cnt[27],ret[N];
char s[N];

int ok(int k)
{
	for(int i=0; i<26; i++)
		if(cnt[i]%k)
			return 0;
	return 1;
}

int main()
{
	int k,l;
	while(scanf("%d",&k)!=EOF)
	{
		scanf("%s",s);
		l=strlen(s);
		memset(cnt,0,sizeof(cnt));
		for(int i=0; s[i]; i++)
			cnt[s[i]-'a']++;
		if(ok(k))
		{
			int top=0;
			for(int i=0; i<26; i++)
				for(int j=0; j<cnt[i]/k; j++)
					ret[top++]=i;
			for(int i=0; i<k; i++)
				for(int j=0; j<top; j++)
					printf("%c",ret[j]+'a');
			puts("");
		}
		else
		{
			puts("-1");
		}
	}
	return 0;
}
