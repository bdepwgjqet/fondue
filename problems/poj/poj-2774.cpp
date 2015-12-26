#include <cstdio>
#include <cstring>
#define N 200100

char s[N];
int cnt[N],sa[N],sb[N],rk[N],ht[N];

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
		x[sa[0]]=0;
		k=1;
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

void gao(int n1,int n)
{
	int ret=0;
	for(int i=1; i<n; i++)
	{
		int u=sa[i],v=sa[i-1];
		if(ht[i]>ret&&(1LL*(u-n1)*(v-n1)<0))
			ret=ht[i];
	}
	printf("%d\n",ret);
}

int main()
{
	int n,n1,n2;
	while(scanf("%s",s)+1)
	{
		n1=strlen(s);
		s[n1]='#';
		scanf("%s",s+n1+1);
		n=strlen(s)+1;
		da(128,n);
		gao(n1,n);
	}
	return 0;
}
