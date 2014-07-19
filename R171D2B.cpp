#include <cstdio>
#include <algorithm>
#define N 100101

using namespace std;

int dat[N],s[N],n,t;

int gao(int st)
{
	int l=st,r=n;
	for(; l<=r;)
	{
		int m=(l+r)>>1;
		if(s[m]-s[st-1]<=t)
			l=m+1;
		else
			r=m-1;
	}
	return l-st;
}

int main()
{
	scanf("%d%d",&n,&t);
	for(int i=1; i<=n; i++)
		scanf("%d",&dat[i]);
	dat[0]=0;
	s[0]=0;
	for(int i=1; i<=n; i++)
		s[i]=s[i-1]+dat[i];
	int ret=0;
	for(int i=1; i<=n; i++)
	{
		ret=max(ret,gao(i));
	}
	printf("%d\n",ret);
	return 0;
}
