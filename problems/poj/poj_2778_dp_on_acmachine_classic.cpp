/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  07/15/2012 02:53:56 PM
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
#define N 110
#define M 1000010
#define S 101000
#define eps 1e-8
#define inf 0x3fffffff
#define MOD 100000
#define PB push_back
#define MP make_pair
#define SZ(a) ((int)((a).size()))
#define ALL(a) (a).begin(),(a).end()
#define CLR(a,x) memset(a,x,sizeof(a))

typedef long long LL;
using namespace std;

struct node{ int next[4],fail,is; }no[S];
LL mat[N][N],retm[N][N],tmp[N][N];
int top;
char s[110];
int q[S];

int get_id(char x)
{
	if(x=='A') return 0;
	if(x=='G') return 1;
	if(x=='C') return 2;
	return 3;
}

void insert(char s[])
{
	int l=strlen(s),r=0;
	for(int i=0; i<l; i++)
	{
		if(no[r].is)
			break;
		int ii=get_id(s[i]);
		if(no[r].next[ii]==-1)
			no[r].next[ii]=top++;
		r=no[r].next[ii];
	}
	no[r].is=1;
}

void init()
{
	top=1;
	for(int i=0; i<S; i++)
	{
		no[i].fail=-1,no[i].is=0;
		for(int j=0; j<4; j++)
			no[i].next[j]=-1;
	}
}

void build_ac()
{
	int l,r;
	no[0].fail=0;
	q[l=r=0]=0;
	for(; l<=r;)
	{
		int now=q[l++];
		for(int i=0; i<4; i++)
		{
			int to=no[now].next[i];
			if(to==-1)
			{
				if(now==0)
					no[now].next[i]=0;
				else
					no[now].next[i]=no[no[now].fail].next[i];
			}
			else
			{
				if(now==0)
					no[to].fail=0;
				else
				{
					no[to].fail=no[no[now].fail].next[i];
					if(no[no[to].fail].is)
						no[to].is=1; //important
				}
				q[++r]=no[now].next[i];
			}
		}
	}
}

void build_matrix()
{
	memset(mat,0,sizeof(mat));
	memset(retm,0,sizeof(retm));
	for(int i=0; i<top; i++)
	{
		if(no[i].is==0)
			for(int j=0; j<4; j++)
			{
				if(no[no[i].next[j]].is==0)
					mat[no[i].next[j]][i]++;
			}
	}
	for(int i=0; i<top; i++)
		retm[i][i]=1;
}

void _mat_mult(LL retm[][N],LL mat[][N])
{
	memset(tmp,0,sizeof(tmp));
	for(int i=0; i<top; i++)
		for(int j=0; j<top; j++)
			for(int k=0; k<top; k++)
			{
			//	tmp[i][j]=(tmp[i][j]+retm[k][j]*mat[i][k])%MOD;
				tmp[i][j]+=retm[k][j]*mat[i][k];
				if(tmp[i][j]>MOD)
					tmp[i][j]%=MOD;
			}
	for(int i=0; i<top; i++)
		for(int j=0; j<top; j++)
			retm[i][j]=tmp[i][j];
}

void mat_mult(int n)
{
	for(; n; n>>=1)
	{
		if(n&1)
			_mat_mult(retm,mat);
		_mat_mult(mat,mat);
	}
}

LL get_ans()
{
	LL ret=0;
	for(int i=0; i<top; i++)
		ret=(ret+retm[i][0])%MOD;
	return ret;
}

int main()
{
	int m,n;
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		init();
		for(int i=0; i<m; i++)
		{
			scanf("%s",s);
			insert(s);
		}
		build_ac();
		build_matrix();
		mat_mult(n);
		LL ans=get_ans();
		printf("%lld\n",ans);
	}
	return 0;
}
