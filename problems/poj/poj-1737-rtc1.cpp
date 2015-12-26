/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  07/25/2012 01:46:35 PM
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

#define DIGIT 4
#define DEPTH 10000
#define MAXN  501
typedef int big_num[MAXN+1];
big_num comb[51][51],f[51],dp[51],bin[1250];

void write(const big_num a)
{
    int i,j;
    for(printf("%d",a[i=a[0]]),i--; i; i--)
        for(j=DEPTH/10; j; j/=10)
            printf("%d",a[i]/j%10);
}

void add(big_num c,big_num a,big_num b)
{
    int i;
	for(i=0; i<=a[0]; i++)
		c[i]=a[i];
    for(i=1; i<=b[0]; i++)
        if((c[i]+=b[i])>=DEPTH)
            c[i]-=DEPTH,c[i+1]++;
    if(b[0]>=c[0])      c[0]=b[0];
    else                for(; c[i]>=DEPTH && i<=c[0]; c[i]-=DEPTH,i++,c[i]++ );
    c[0]+=(c[c[0]+1]>0);
}

void mul(big_num c,big_num a,big_num b)
{
    int i,j;
    memset(c,0,sizeof(int)*(MAXN+1));
    for(c[0]=a[0]+b[0]-1,i=1; i<=a[0]; i++)
        for(j=1;j<=b[0];j++)
            if((c[i+j-1]+=a[i]*b[j])>=DEPTH)
                c[i+j]+=c[i+j-1]/DEPTH,c[i+j-1]%=DEPTH;
    for(c[0]+=(c[c[0]+1]>0); !c[c[0]]&&c[0]>1; c[0]--);
}

void sub(big_num a,big_num b)   //a>b;
{
    int i;
    for(i=1; i<=b[0]; i++)
        if((a[i]-=b[i])<0)
            a[i+1]--,a[i]+=DEPTH;
    for(; a[i]<0; a[i]+=DEPTH,i++,a[i]--);
    for(; !a[a[0]]&&a[0]>1; a[0]--);
}

void give(big_num a,int x)
{
	memset(a,0,sizeof(a));
	a[0]=1,a[1]=x;
}

void give(big_num a,big_num b)
{
	for(int i=0; i<=b[0]; i++)
		a[i]=b[i];
}

void init()
{
	big_num tmp,tmp2;
	give(comb[0][0],1);
	give(comb[1][0],1);
	give(comb[1][1],1);
	for(int i=2; i<51; i++)
	{
		give(comb[i][0],1);
		for(int j=1; j<i; j++)
		{
			add(comb[i][j],comb[i-1][j-1],comb[i-1][j]);
		}
		give(comb[i][i],1);
	}
	give(bin[0],1);
	give(tmp,2);
	for(int i=1; i<1250; i++)
		mul(bin[i],bin[i-1],tmp);
	give(dp[1],1);
	for(int i=2; i<51; i++)
	{
		give(dp[i],bin[i*(i-1)/2]);
		for(int j=0; j<i-1; j++)
		{
			mul(tmp,comb[i-1][j],dp[j+1]);
			mul(tmp2,tmp,bin[(i-j-1)*(i-j-2)/2]);
			sub(dp[i],tmp2);
		}
	}
}

int main()
{
	int n;
	init();
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0) break;
		write(dp[n]);
		puts("");
	}
	return 0;
}
