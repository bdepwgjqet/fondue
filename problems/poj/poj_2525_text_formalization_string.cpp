/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  03/29/2012 04:03:27 PM
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
#define X 100
#define MOD 1000000007

typedef long long LL;
using namespace std;

inline int L(int i){ return i<<1; }
inline int R(int i){ return (i<<1)|1; }
//inline int B(int i){ return 1<<i; }
inline int low_bit(int x){ return x&(-x); }

char s[N],A[2][X][N],B[2][X][N];
int vis[N],n,m;

inline int islow(char x)
{
	return 'a'<=x&&x<='z';
}

inline char upper(char x)
{
	if(islow(x))
		return x+'A'-'a';
	return x;
}

void init(int id,char A[][X][N])
{
	int i,l,top;
	l=strlen(s);
	top=0;
	for(i=1; i<l&&s[i]!='"'; i++)
		A[0][id][top++]=s[i];
	A[0][id][top]='\0';
	for(i++; i<l&&s[i]!='"'; i++);
	top=0;
	for(i++; i<l&&s[i]!='"'; i++)
		A[1][id][top++]=s[i];
	A[1][id][top]='\0';
}

void solve()
{
	int l,la,kind,k,j,lb;
	l=strlen(s);
	for(int i=0; i<l; )
	{
		kind=0;
		for(j=0; j<n; j++)
		{
			la=strlen(A[0][j]);
			lb=strlen(A[1][j]);
			for(k=0; k<la&&A[0][j][k]==s[i+k]; k++);
			if(k>=la)
			{
				kind=1;
				break;
			}
			for(k=0; k<la&&upper(A[0][j][k])==s[i+k]; k++);
			if(k>=la)
			{
				kind=2;
				break;
			}
			if(upper(A[0][j][0])==s[i])
			{
				for(k=1; k<la&&A[0][j][k]==s[i+k]; k++);
				if(k>=la)
				{
					kind=3;
					break;
				}
			}
		}
		if(kind==1)
		{
			printf("%s",A[1][j]);
			i+=la;
		}
		else if(kind==2)
		{
			for(int u=0; u<lb; u++)
				printf("%c",upper(A[1][j][u]));
			i+=la;
		}
		else if(kind==3)
		{
			printf("%c",upper(A[1][j][0]));
			for(int u=1; u<lb; u++)
				printf("%c",A[1][j][u]);
			i+=la;
		}
		if(kind>0)	continue;
		for(j=0; j<m; j++)
		{
			if(vis[j])	continue;
			la=strlen(B[0][j]);
			lb=strlen(B[1][j]);
			for(k=0; k<la&&s[i+k]==B[0][j][k]; k++);
			if(k>=la)
				break;
		}
		if(j<m)
		{
			vis[j]=1;
			printf("%s (%s)",B[1][j],B[0][j]);
			i+=la;
		}
		else
		{
			printf("%c",s[i]);
			i++;
		}
	}
	puts("");
}

int main()
{
	scanf("%d%d",&n,&m);
	getchar();
	for(int i=0; i<n; i++)
	{
		gets(s);
		init(i,A);
	}
	for(int i=0; i<m; i++)
	{
		gets(s);
		init(i,B);
	}
	memset(vis,0,sizeof(vis));
	while(gets(s)!=NULL)
	{
		solve();
		if(s[0]=='#'&&s[1]=='\0')
			memset(vis,0,sizeof(vis));
	}
	return 0;
}
