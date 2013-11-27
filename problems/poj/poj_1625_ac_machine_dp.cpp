/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  07/16/2012 10:56:37 AM
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
#define N 52
#define M 1000010
#define S 1000
#define eps 1e-8
#define inf 0x3fffffff
#define MOD 1000000007
#define PB push_back
#define MP make_pair
#define SZ(a) ((int)((a).size()))
#define ALL(a) (a).begin(),(a).end()
#define CLR(a,x) memset(a,x,sizeof(a))
#define DIGIT 4
#define DEPTH 10000
#define MAXN  300

typedef long long LL;
using namespace std;
typedef int big_num[MAXN+1];
big_num dp[2][S];

struct node{ int next[N],fail,is; }no[S];
char s[S+10];
int tab[S],top,q[S];

void add(big_num a,big_num b)
{
    int i;
    for(i=1; i<=b[0]; i++)
        if((a[i]+=b[i])>=DEPTH)
            a[i]-=DEPTH,a[i+1]++;
    if(b[0]>=a[0])      a[0]=b[0];
    else                for(; a[i]>=DEPTH && i<=a[0]; a[i]-=DEPTH,i++,a[i]++ );
    a[0]+=(a[a[0]+1]>0);
}

void write(const big_num a)
{
    int i,j;
    for(printf("%d",a[i=a[0]]),i--; i; i--)
        for(j=DEPTH/10; j; j/=10)
            printf("%d",a[i]/j%10);
}

void init()
{
	top=1;
	for(int i=0; i<S; i++)
	{
		no[i].is=0,no[i].fail=-1;
		for(int j=0; j<N; j++)
			no[i].next[j]=-1;
	}
}

void insert(char s[])
{
	int l=strlen(s),p=0;
	for(int i=0; i<l; i++)
	{
		int ii=tab[s[i]];
		if(no[p].is)
			break;
		if(no[p].next[ii]==-1)
			no[p].next[ii]=top++;
		p=no[p].next[ii];
	}
	no[p].is=1;
}

void build_ac(int n)
{
	int l,r;
	q[l=r=0]=0;
	for(; l<=r;)
	{
		int now=q[l++];
		for(int i=0; i<n; i++)
		{
			int ii=no[now].next[i];
			if(ii==-1)
			{
				if(now==0)
					no[now].next[i]=0;
				else
					no[now].next[i]=no[no[now].fail].next[i];
			}
			else
			{
				if(now==0)
					no[ii].fail=0;
				else
				{
					no[ii].fail=no[no[now].fail].next[i];
					if(no[no[ii].fail].is)
						no[ii].is=1;
				}
				q[++r]=ii;
			}
		}
	}
}

void solve(int m,int n)
{
	memset(dp,0,sizeof(dp));
	dp[0][0][1]=1;
	for(int i=0; i<top; i++)
	{
		dp[0][i][0]=1;
		dp[1][i][0]=1;
	}
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<top; j++)
			for(int k=0; k<n; k++)
			{
				int to=no[j].next[k];
				if(no[to].is)
					continue;
				add(dp[1][to],dp[0][j]);
			}
		for(int j=0; j<top; j++)
		{
			for(int k=0; k<MAXN; k++)
				dp[0][j][k]=dp[1][j][k],dp[1][j][k]=0;
			dp[1][j][0]=1;
		}
	}
	for(int i=0; i<top; i++)
		add(dp[1][0],dp[0][i]);
	write(dp[1][0]);
	puts("");
}

int main()
{
	int n,m,p;
	while(scanf("%d%d%d",&n,&m,&p)!=EOF)
	{
		getchar();
		init();
		gets(s);
		for(int i=0; i<n; i++)
			tab[s[i]]=i;
		for(int i=0; i<p; i++)
		{
			scanf("%s",s);
			insert(s);
		}
		build_ac(n);
		solve(m,n);
	}
	return 0;
}
