/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  07/22/2012 07:54:34 PM
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
#define N 101010
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

char ss[110][1011];
int s[N],top,sa[N],rank[N],sb[N],cnt[N],seg[N],vis[110],rets[N],rtop,height[N];

inline int equal(int i,int j,int l,int *y){ return y[i]==y[j]&&y[i+l]==y[j+l]; }

void radix_sort(int n,int m,int l,int *x,int *y)
{
	int i,k;
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
	int i,l,k,*x=rank,*t,*y=sb;
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

void get_height(int n)
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

int ok(int k,int n,int nn)
{
	int i,j,num,ttl=nn/2+1;
	rtop=0;
	for(i=0; i<n; )
	{
		if(height[i]<k)
		{
			i++;
			continue;
		}
		memset(vis,0,sizeof(vis));
		for(j=i; j<n; j++)
		{
			if(height[j]<k)
				break;
			vis[seg[sa[j]]]=1;
			if(j>0)
				vis[seg[sa[j-1]]]=1;
		}
		num=0;
		for(int u=0; u<nn; u++)
			if(vis[u])
				num++;
		if(num>=ttl)
			rets[rtop++]=i;
		i=j+1;
	}
	return rtop>0;
}

void solve(int l,int r,int n,int nn)
{
	int mid;
	for(; l<=r;)
	{
		mid=(l+r)>>1;
		if(ok(mid,n,nn))
			l=mid+1;
		else
			r=mid-1;
	}
	if(r<=0)
	{
		puts("?");
		return;
	}
	ok(r,n,nn);
	for(int i=0; i<rtop; i++)
	{
		int id=sa[rets[i]];
		for(int j=0; j<r; j++)
			printf("%c",s[id+j]);
		puts("");
	}
}

int main()
{
	int n,ll,rr,tag=0;
	while(scanf("%d",&n)!=EOF)
	{
		memset(s,0,sizeof(s));
		if(n==0) break;
		if(tag)
			puts("");
		else
			tag=1;
		for(int i=0; i<n; i++)
			scanf("%s",ss[i]);
		int tp=128;
		top=0,rr=N;
		for(int i=0; i<n; i++)
		{
			int l=strlen(ss[i]);
			rr=min(l,rr);
			for(int j=0; j<l; j++)
			{
				seg[top]=i;
				s[top++]=ss[i][j];
			}
			if(i+1<n)
			{
				seg[top]=i;
				s[top++]=tp++;
			}
		}
		seg[top]=n-1;
		s[top++]=0;
		da(top,tp);
		get_height(top);
		ll=0;
		solve(ll,rr,top,n);
	}
	return 0;
}
