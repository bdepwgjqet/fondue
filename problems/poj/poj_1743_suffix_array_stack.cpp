#include <cstdio>
#include <cstring>
#include <algorithm>
#define X 200
#define N 20010

using namespace std;

struct node{ int mi,mx,h;
	node(){;}
	node(int i,int x,int hh){ mi=i,mx=x,h=hh; }
}st[N];
int s[N],sa[N],sb[N],rk[N],ht[N],cnt[N];

int equal(int i,int j,int *y,int l){ return y[i]==y[j]&&y[i+l]==y[j+l]; }

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

void da(int m,int n)
{
	int *x=rk,*y=sb,*t;
	for(int i=0; i<n; i++)
		rk[i]=s[i],sa[i]=i;
	radix_sort(m,n,x,y,0);
	int l,k;
	for(l=k=1; k<n; l<<=1)
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
		for(int j=sa[rk[i]-1]; s[j+k]==s[i+k]; k++);
		ht[rk[i]]=k;
	}
	ht[0]=0;
}

void solve(int n)
{
	int top=-1,ret=0;
	for(int i=1; i<n; i++)
	{
		if(top>=0)
		{
			int mx=max(sa[i],sa[i-1]),mi=min(sa[i],sa[i-1]);
			for(; top>=0&&ht[i]<=st[top].h; )
			{
				int a=st[top].mx,b=st[top].mi;
				ret=max(ret,min(st[top].h,a-b));
				mx=max(a,mx),mi=min(b,mi);
				top--;
				if(top>=0)
					st[top].mx=max(st[top].mx,a),st[top].mi=min(b,st[top].mi);
			}
			st[++top]=node(mi,mx,ht[i]);
		}
		else st[++top]=node(min(sa[i],sa[i-1]),max(sa[i],sa[i-1]),ht[i]);
	}
	for(; top>=0;)
	{
		int a=st[top].mx,b=st[top].mi;
		ret=max(ret,min(a-b,st[top].h));
		top--;
		if(top>=0)
			st[top].mx=max(st[top].mx,a),st[top].mi=min(b,st[top].mi);
	}
	if(ret<4)
		puts("0");
	else
		printf("%d\n",ret+1);
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
			mi=min(mi,s[i]);
		for(int i=0; i<n-1; i++)
			s[i]-=mi-1;
		s[n-1]=0;
		da(X,n);
		solve(n);
	}
	return 0;
}
