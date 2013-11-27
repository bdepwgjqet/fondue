/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  04/04/2012 05:01:24 PM
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
#define inf 10000000
#define N 510
#define M 1000010
#define S 1000100
#define MOD 1000000007
#define X 53

int dp[N][N][X];

typedef long long LL;
using namespace std;

inline int L(int i){ return i<<1; }
inline int R(int i){ return (i<<1)|1; }
inline int B(int i){ return 1<<i; }
inline int low_bit(int x){ return x&(-x); }

char s[N],t[N];
int ls,lt;

int get_val(char x)
{
	if(x>='a')
		return x-'a'+26;
	return x-'A';
}

char get_char(int x)
{
	if(x<26)
		return x+'A';
	return x-26+'a';
}

int dfs(int i,int j,int tag)
{
	int ret=inf;
	char x;
	if(dp[i][j][tag]>=0)	return dp[i][j][tag];
	if(j==lt)
		return dp[i][j][tag]=ls-i;
	if(i==ls)
		return dp[i][j][tag]=lt-j;
	if(tag==52)
		x=s[i];
	else
		x=get_char(tag);
	if(x==t[j])
		ret=min(ret,dfs(i+1,j+1,tag));
	ret=min(ret,dfs(i,j+1,tag)+1);
	ret=min(ret,dfs(i+1,j,tag)+1);
	ret=min(ret,dfs(i+1,j+1,tag)+1);
	if(x!=t[j])
		ret=min(ret,dfs(i+1,j+1,get_val(t[j]))+1);
	//printf("%d %d %d\n",i,j,ret);
	return dp[i][j][tag]=ret;
}

int main()
{
	int ret;
	while(scanf("%s",s)!=EOF)
	{
		if(s[0]=='#')
			break;
		scanf("%s",t);
		memset(dp,-1,sizeof(dp));
		ls=strlen(s);
		lt=strlen(t);
		ret=dfs(0,0,52);
		printf("%d\n",ret);
	}
	return 0;
}
