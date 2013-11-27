/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  04/10/2012 01:43:08 PM
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
#define N 100010
#define M 1000010
#define S 1000100
#define X 10
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

char s[N],ret[2][N];
int num[2][11],all[11],top0,top1;

int main()
{
	int id,mx,tmp,x,zero;
	while(scanf("%s",s)!=EOF)
	{
		CLR(all,0);
		CLR(num,0);
		for(int i=0; s[i]; i++)
			all[s[i]-'0']++;
		mx=0,id=-1,zero=0;
		for(int i=1; i<=5; i++)
		{
			for(int k=0; k<X; k++)
				num[1][k]=num[0][k]=all[k];
			int j=X-i;
			if(all[j]==0||all[i]==0)
				continue;
			num[0][i]--,num[1][j]--;
			tmp=1;
			for(int k=0; k<=9; k++)
			{
				x=min(num[0][k],num[1][X-k-1]);
				num[0][k]-=x,num[1][X-k-1]-=x;
				tmp+=x;
			}
			tmp+=min(num[0][0],num[1][0]);
			if(tmp>mx)
			{
				mx=tmp;
				id=i;
				zero=min(num[0][0],num[1][0]);
			}
		}
		if(id<0)
			mx=all[0];
		if(mx==0)
		{
			puts(s);
			puts(s);
			continue;
		}
		for(int k=0; k<X; k++)
			num[1][k]=num[0][k]=all[k];
		top0=top1=0;
		num[0][0]-=zero,num[1][0]-=zero;
		for(int k=0; k<zero; k++)
			ret[0][top0++]=0,ret[1][top1++]=0;
		if(id>0)
		{
			ret[0][top0++]=id;
			ret[1][top1++]=X-id;
			num[0][id]--,num[1][X-id]--;
		}
		for(int k=0; k<X; k++)
		{
			x=min(num[0][k],num[1][X-k-1]);
			num[0][k]-=x,num[1][X-k-1]-=x;
			for(int j=0; j<x; j++)
			{
				ret[0][top0++]=k;
				ret[1][top1++]=X-k-1;
			}
		}
		for(int k=0; k<X; k++)
		{
			if(num[0][k]==0)
				continue;
			for(int j=0; j<num[0][k]; j++)
				ret[0][top0++]=k;
		}
		for(int k=0; k<X; k++)
		{
			if(num[1][k]==0)
				continue;
			for(int j=0; j<num[1][k]; j++)
				ret[1][top1++]=k;
		}
		for(int i=top0-1; i>=0; i--)
			printf("%c",ret[0][i]+'0');
		puts("");
		for(int i=top1-1; i>=0; i--)
			printf("%c",ret[1][i]+'0');
		puts("");
	}
	return 0;
}
