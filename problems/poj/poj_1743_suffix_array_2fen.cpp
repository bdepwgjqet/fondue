#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 20010
#define X 200

using namespace std;

int s[N],sa[N],sb[N],rk[N],cnt[N],ht[N];

void radix_sort(int m,int n,int *x,int *y,int l)
{
	int top=0;
	for(int i=n-l; i<n; i++)
		y[top++]=i;
	for(int i=0; i<n; i++)
		if(sa[i]>=l)
			y[top++]=sa[i]-l;
	memset(cnt,0,sizeof(cnt));
	for(int i=0; i<n; i++)
		cnt[x[i]]++;
	for(int i=1; i<m; i++)
		cnt[i]+=cnt[i-1];
	for(int i=n-1; i>=0; i--)
		sa[--cnt[x[y[i]]]]=y[i];
}

int equal(int i,int j,int *y,int l){ return y[i]==y[j]&&y[i+l]==y[j+l]; }

void da(int m,int n)
{
	int *x=rk,*y=sb,*t;
	for(int i=0; i<n; i++)
		sa[i]=i,rk[i]=s[i];
	radix_sort(m,n,x,y,0);
	int k,l;
	for(k=l=1; k<n; l<<=1)
	{
		radix_sort(m,n,x,y,l);
		t=x,x=y,y=t;
		x[sa[0]]=0,k=1;
		for(int i=1; i<n; i++)
			x[sa[i]]=equal(sa[i],sa[i-1],y,l)?k-1:k++;
		m=k;
	}
	for(int i=0; i<n; i++)
		rk[i]=x[i];
	k=0;
	for(int i=0; i<n-1; i++)
	{
		k>0?k--:k=0;
		for(int j=sa[rk[i]-1]; s[i+k]==s[j+k]; k++);
		ht[rk[i]]=k;
	}
	ht[0]=0;
}

int ok(int l,int n)
{
	int j;
	for(int i=1; i<n; i++)
	{
		if(ht[i]<l)
			continue;
		for(j=i+1; j<n; j++)
			if(ht[j]<l)
				break;
		int mx=0,mi=N;
		for(int k=i-1; k<j; k++)
		{
			mx=max(mx,sa[k]);
			mi=min(mi,sa[k]);
		}
		if(mx-mi>=l)
			return 1;
		i=j-1;
	}
	return 0;
}

void solve(int n)
{
	int l=4,r=n,mid;
	for(; l<=r;)
	{
		mid=(l+r)>>1;
		if(ok(mid,n))
			l=mid+1;
		else
			r=mid-1;
	}
	if(r<4)
		puts("0");
	else
		printf("%d\n",r+1);
}

int main()
{
	int n;
	while(scanf("%d",&n)+1,n)
	{
		for(int i=0; i<n; i++)
			scanf("%d",&s[i]);
		for(int i=0; i<n-1; i++)
			s[i]=s[i+1]-s[i];
		int mi=N;
		for(int i=0; i<n-1; i++)
			mi=min(s[i],mi);
		for(int i=0; i<n-1; i++)
		{
			s[i]-=mi;
			s[i]++;
		}
		s[n-1]=0;
		da(X,n);
		solve(n);
	}
	return 0;
}
