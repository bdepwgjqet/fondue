/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  09/16/2012 11:49:09 PM
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

char s[N];

int mat[N],len,ret,dp[N],reti[N];
int st[N],top;

int dfs(int l,int r)
{
	if(l>r)
		return 1;
	if(mat[l]==-1)
	{
		dfs(l+1,r);
		dp[l]=0;
		reti[l]=-1;
		return 0;
	}
	int id=mat[l],a,b,add;
	a=dfs(l+1,mat[l]-1);
	b=dfs(mat[l]+1,r);

	if(s[l]=='['&&a)
		add=1;
	else
		add=0;

	if(a)
	{
		dp[l]=dp[l+1]+dp[mat[l]+1]+add;
		reti[l]=l;
	}
	else
	{
		reti[l]=-1;
		dp[l]=0;
		/*
		if(dp[mat[l]+1]>dp[l+1]+add)
			reti[l]=mat[l]+1;
		else
			reti[l]=l;
		dp[l]=max(dp[mat[l]+1],dp[l+1]+add);
		*/
	}

	if(a&&b)
		return 1;
	else
		return 0;
}

void show(int i)
{
	if(i<0)
		return;
	if(reti[i]==i)
	{
		int id=mat[i];
		printf("%c",s[i]);
		show(i+1);
		printf("%c",s[id]);
		show(id+1);
	}
	else
		show(reti[i]);
}

int main()
{
	scanf("%s",s);
	len=strlen(s);
	top=-1;
	for(int i=0; i<len; i++)
		mat[i]=-1;
	for(int i=0; i<len; i++)
	{
		if(s[i]=='(')
			st[++top]=i;
		else if(s[i]=='[')
			st[++top]=i;
		else if(s[i]==')')
		{
			if(top<0)
				continue;
			int id=st[top];
			if(s[id]=='(')
			{
				mat[i]=id;
				mat[id]=i;
			}
			top--;
		}
		else
		{
			if(top<0)
				continue;
			int id=st[top];
			if(s[id]=='[')
			{
				mat[i]=id;
				mat[id]=i;
			}
			top--;
		}
	}
	memset(dp,0,sizeof(dp));
	memset(reti,-1,sizeof(reti));
	dfs(0,len-1);
	int ret=0,id=-1;
	for(int i=0; i<len; i++)
		if(ret<dp[i])
			ret=dp[i],id=i;
	printf("%d\n",ret);
	if(ret==0)
		puts("");
	else
	{
		show(id);
		puts("");
	}
	return 0;
}
