#include <cstdio>
#include <cmath>
#include <cstring>
#define N 100001

char s[N];
int sa[N],sb[N],cnt[N],rank[N],dat[N],dp[N][20],height[N];
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

void RMQ(int n)
{
	int k=int(log(1.0*n)/log(2.0)),a,b;
	for(int i=1; i<=n; i++)
		dat[i]=height[i-1],dp[i][0]=i;
	for(int j=1; j<=k; j++)
		for(int i=1; i+B(j)-1<=n; i++)
		{
			a=dp[i][j-1];
			b=dp[i+B(j-1)][j-1];
			if(dat[a]<dat[b]) dp[i][j]=a;
			else dp[i][j]=b;
		}
}

int RMQ_query(int a,int b)
{
	int k=int(log(1.0*(b-a+1))/log(2.0));
	a=dp[a][k],b=dp[b-B(k)+1][k];
	return dat[a]>dat[b]?b:a;
}

int lcp(int a,int b)
{
	int t;
	a=rank[a],b=rank[b];
	if(a>b) t=a,a=b,b=t;
	return height[RMQ_query(a+1,b)];
}
