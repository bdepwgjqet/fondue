/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  04/07/2012 04:54:15 PM
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
#define N 210
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

int dp[110][N][55][2],ret=0;
char s[N],l;

char chg(char x)
{
	if(x=='F')
		return 'T';
	return 'F';
}

void dfs(int id,int pos,int ope,int dir)
{
	int d;
	char x;
	if(dp[id][pos][ope][dir])
		return;
	dp[id][pos][ope][dir]=1;
	if(id==l)
	{
		if(ope>0)
			return;
		ret=max(ret,abs(pos-100));
		return;
	}
	if(dir==0)
		d=-1;
	else
		d=1;
	for(int i=0; i<=ope; i++)
	{
		if(i&1)
			x=chg(s[id]);
		else
			x=s[id];
		if(x=='F')
			dfs(id+1,pos+d,ope-i,dir);
		else
			dfs(id+1,pos,ope-i,dir^1);
	}
}

int main()
{
	int n;
	scanf("%s%d",s,&n);
	l=strlen(s);
	CLR(dp,0);
	ret=0;
	dfs(0,100,n,1);
	printf("%d\n",ret);
	return 0;
}
