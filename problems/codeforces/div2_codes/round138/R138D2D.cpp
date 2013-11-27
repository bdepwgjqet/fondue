/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  09/17/2012 01:04:51 AM
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
#define MOD 1000000007
#define PB push_back
#define MP make_pair
#define SZ(a) ((int)((a).size()))
#define ALL(a) (a).begin(),(a).end()
#define CLR(a,x) memset(a,x,sizeof(a))

typedef long long LL;
using namespace std;

int dp[N],dd[N];
vector<int> ids[26];
char s[N],t[N];

int ok(int n)
{
	int now,l,r,ii;
	for(int i=0; i<n; i++)
	{
		now=s[i]-'a';
		l=dd[i+2]-1,r=dp[i]+1;
		ii=s[i]-'a';
		int x=upper_bound(ids[ii].begin(),ids[ii].end(),r)-lower_bound(ids[ii].begin(),ids[ii].end(),l);
		if(x<=0)
			return 0;
	}
	return 1;
}

int main()
{
	while(scanf("%s%s",s,t)!=EOF)
	{
		int ls=strlen(s),lt=strlen(t);
		int i=0;
		for(int i=0; i<26; i++)
			ids[i].clear();
		for(int i=0; i<lt; i++)
		{
			ids[t[i]-'a'].push_back(i);
		}
		for(int i=0; i<26; i++)
			sort(ids[i].begin(),ids[i].end());
		dp[0]=-1;
		for(int j=0; j<lt; j++)
		{
			for(; i<ls; i++)
			{
				if(s[i]==t[j])
				{
					dp[i+1]=j;
					i++;
					break;
				}
				dp[i+1]=j-1;
			}
		}
		for(; i<ls; i++)
			dp[i+1]=dp[i];
		i=ls-1;
		dd[ls+1]=lt;
		for(int j=lt-1; j>=0; j--)
		{
			for(; i>=0; i--)
			{
				if(s[i]==t[j])
				{
					dd[i+1]=j;
					i--;
					break;
				}
				dd[i+1]=j+1;
			}
		}
		for(; i>=0; i--)
			dd[i+1]=dd[i+2];
		if(ok(ls))
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}
