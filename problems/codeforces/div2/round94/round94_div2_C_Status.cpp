/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  03/15/2012 05:16:27 PM
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
#define X 10

typedef long long LL;
using namespace std;

inline int L(int i){ return i<<1; }
inline int R(int i){ return (i<<1)|1; }
inline int max(int a,int b){ return a<b?b:a; }
inline int min(int a,int b){ return a<b?a:b; }
inline int abs(int x){ return x<0?-x:x; }

struct node{ int x,y; }no[MAXN],st,ed;

int mat[100][X][X],dir[10][2]={{-1,0},{0,1},{0,-1},{1,0},{1,1},{1,-1},{-1,1},{-1,-1}},v[1000][9][9],tag;
char s[X][X];

inline int inboard(int x,int y){ return 0<=x&&x<8&&0<=y&&y<8; }

void init()
{
	int i,j,k;
	memset(mat,0,sizeof(mat));
	memset(v,0,sizeof(v));
	tag=1;
	for(i=0; i<8; i++)
		for(j=0; j<8; j++)
		{
			if(s[i][j]=='S')
				mat[0][i][j]=1;
			else
				mat[0][i][j]=0;
			if(s[i][j]=='M')
				st.x=i,st.y=j;
			if(s[i][j]=='A')
				ed.x=i,ed.y=j;
		}
	for(i=1; i<=8; i++)
	{
		for(j=1; j<8; j++)
			for(k=0; k<8; k++)
				mat[i][j][k]=mat[i-1][j-1][k];
	}
	/*
	for(i=0; i<8; i++,puts(""))
		for(j=0; j<8; j++,puts(""))
			for(k=0; k<8; k++)
				printf("%d ",mat[i][j][k]);
				*/
}

inline int get(int t,int x,int y)
{
	if(t>=8)
		return 0;
	return mat[t][x][y];
}

void dfs(int x,int y,int t)
{
//	printf("%d %d %d\n",x,y,t);
	if(get(t,x,y)==1)	return ;
	if((x==ed.x&&y==ed.y)||t>8)
	{
		tag=0;
		return ;
	}
	int i,tx,ty;
	v[t][x][y]=1;
	dfs(x,y,t+1);
	for(i=0; i<8&&tag; i++)
	{
		tx=x+dir[i][0],ty=y+dir[i][1];
		if(inboard(tx,ty)&&(!v[t+1][tx][ty])&&get(t+1,tx,ty)==0&&get(t,tx,ty)==0)
			if(t==0||(!v[t-1][tx][ty]))
				dfs(tx,ty,t+1);
	}
}

int main()
{
	int i;
	for(i=0; i<8; i++)
		scanf("%s",s[i]);
	init();
	dfs(st.x,st.y,0);
	if(tag)	puts("LOSE");
	else	puts("WIN");
	return 0;
}
