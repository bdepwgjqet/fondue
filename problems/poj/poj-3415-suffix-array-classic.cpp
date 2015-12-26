/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  07/22/2012 11:07:09 AM
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
#define N 200010
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

struct stack{ int x,c; }st[N];
char s[N];
int sa[N],sb[N],cnt[N],rank[N],dat[N],dp[N][20],height[N],n1;
int equal(int i,int j,int l,int *y){ return y[i]==y[j]&&y[i+l]==y[j+l]; }

inline int B(int i){ return 1<<i; }

void radix_sort(int n,int m,int l,int *x,int *y)
{
	int k,i;
	for(k=0,i=n-l; i<n; i++) y[k++]=i;
	for(i=0; i<n; i++) 
		if(sa[i]>=l) y[k++]=sa[i]-l;
	memset(cnt,0,sizeof(cnt));
	for(i=0; i<n; i++) cnt[x[i]]++;
	for(i=1; i<m; i++) cnt[i]+=cnt[i-1];
	for(i=n-1; i>=0; i--) sa[--cnt[x[y[i]]]]=y[i];
}

void da(int n,int m)
{
	int *t,*x=rank,*y=sb,l,k,i;
	for(i=0; i<n; i++) x[i]=s[i],sa[i]=i;
	radix_sort(n,m,0,x,y);
	for(k=l=1; k<n; l<<=1)
	{
		radix_sort(n,m,l,x,y);
		t=x,x=y,y=t;
		x[sa[0]]=0,k=1;
		for(i=1; i<n; i++)
			x[sa[i]]=equal(sa[i],sa[i-1],l,y)?k-1:k++;
		m=k;
	}
	for(i=0; i<n; i++) rank[sa[i]]=i;
}

void calc_height(int n)
{
	int k=0;
	for(int i=0; i<n-1; i++)
	{
		k=(k>0)?k-1:0;
		for(int j=sa[rank[i]-1]; s[i+k]==s[j+k]; k++);
		height[rank[i]]=k;
	}
	height[0]=0;
}

LL single_stack(int &j,int tag,int k,int n)
{
	LL top=-1,tmp=0,ret=0,c;
	for(; height[j]>=k&&j<n; j++)
	{
		for(c=0; top>=0&&height[j]<=st[top].x; )
		{
			tmp+=(height[j]-st[top].x)*st[top].c;
			c+=st[top].c;
			top--;
		}
		++top;
		st[top].x=height[j];
		st[top].c=c;
		if(tag==0)
		{
			if(sa[j-1]<n1)
			{
				tmp+=height[j]-k+1;
				st[top].c++;
			}
			if(sa[j]>n1)
				ret+=tmp;
		}
		else
		{
			if(sa[j-1]>n1)
			{
				tmp+=height[j]-k+1;
				st[top].c++;
			}
			if(sa[j]<n1)
			{
				ret+=tmp;
			}
		}
	}
	return ret;
}

LL solve(int n,int k)
{
	int i,j,top;
	LL ret=0,tmp,c;
	for(i=1; i<n; )
	{
		if(height[i]<k)
		{
			i++;
			continue;
		}
		j=i;
		ret+=single_stack(j,0,k,n);
		j=i;
		ret+=single_stack(j,1,k,n);
		i=j+1;
	}
	return ret;
}

int main()
{
	int k,n;
	while(scanf("%d",&k)!=EOF)
	{
		if(k==0) break;
		scanf("%s",s);
		n1=strlen(s);
		s[n1]='$';
		scanf("%s",s+n1+1);
		n=strlen(s);
		da(n+1,128);
		calc_height(n+1);
		printf("%lld\n",solve(n+1,k));
	}
	return 0;
}
