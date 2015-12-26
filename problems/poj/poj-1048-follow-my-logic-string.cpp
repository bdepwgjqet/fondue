/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  04/04/2012 10:21:58 AM
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
#define N 1010
#define M 1000010
#define S 1000100
#define MOD 1000000007

typedef long long LL;
using namespace std;

inline int L(int i){ return i<<1; }
inline int R(int i){ return (i<<1)|1; }
inline int B(int i){ return 1<<i; }
inline int low_bit(int x){ return x&(-x); }

char mat[N][N],val[30];
int n;
int v[N][N];
int dir[4][2]={{-1,0},{1,0},{0,1},{0,-1}};

int has_next()
{
	memset(mat,0,sizeof(mat));
	int i=0;
	for(; gets(mat[i])!=NULL; i++)
		if(mat[i][0]=='*')
			break;
	n=i;
	return i>0;
}

void find_qus(int &x,int &y)
{
	for(int i=0; i<n; i++)
		for(int j=0; mat[i][j]; j++)
			if(mat[i][j]=='?')
				x=i,y=j;
}

int is_letter(char x)
{
	return 'A'<=x&&x<='Z';
}

int to_go(int x,int y)
{
	char c=mat[x][y];
	if(x<0||y<0)
		return 0;
	if(v[x][y])
		return 0;
	if(c=='-'||c=='|'||c==')'||c=='>'||is_letter(c)||c=='o'||c=='+')
		return 1;
	return 0;
}

int dfs(int x,int y)
{
//	printf("%d %d=>\n",x,y);
	int tag=0,ret;
	char c=mat[x][y];
	v[x][y]=1;
	if(is_letter(c))
		return val[c-'A']-'0';
	if(c=='>')
		return dfs(x-1,y-3)|dfs(x+1,y-3);
	if(c==')')
		return dfs(x-1,y-3)&dfs(x+1,y-3);
	if(c=='|')
	{
		if(to_go(x-1,y))
			return dfs(x-1,y);
		else
			return dfs(x+1,y);
	}
	if(c=='-')
	{
		if(to_go(x,y-1))
			return dfs(x,y-1);
		else
			return dfs(x,y+1);
	}
	if(c=='+')
	{
		if(to_go(x,y-1)&&mat[x][y-1]=='-')
			return dfs(x,y-1);
		if(to_go(x,y+1)&&mat[x][y+1]=='-')
			return dfs(x,y+1);
		if(to_go(x-1,y)&&mat[x-1][y]=='|')
			return dfs(x-1,y);
		if(to_go(x+1,y)&&mat[x+1][y]=='|')
			return dfs(x+1,y);
	}
	if(c=='?'||c=='o')
	{
		for(int i=0; i<4; i++)
		{
			int tx=x+dir[i][0],ty=y+dir[i][1];
			if(to_go(tx,ty))
			{
				if(c=='o')
					return !dfs(tx,ty);
				return dfs(tx,ty);
			}
		}
	}
}

int main()
{
	int x,y;
	int p_c=0;
	while(has_next())
	{
		if(p_c)
			puts("");
		else
			p_c=1;
		/*
		for(int i=0; i<n; i++)
			puts(mat[i]);
			*/
		find_qus(x,y);
		while(scanf("%s",val)!=EOF)
		{
			if(val[0]=='*')
				break;
			memset(v,0,sizeof(v));
			printf("%d\n",dfs(x,y));
		}
		getchar();
	}
	return 0;
}
