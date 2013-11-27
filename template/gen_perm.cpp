//排列数生成
#include <cstdio>
#define MAXN 1000

int tag[MAXN],tmp[MAXN],a[MAXN];

void show(int m,int tmp[])
{
	int i;
	for(i=0; i<m; i++)	printf("%d ",tmp[i]);
	puts("");
}

void genperm(int n,int m,int cnt)
{
	int i;
	if(cnt==m)	show(m,tmp);
	else
		for(i=0; i<n; i++)
			if(!tag[i])
				tag[i]=1,tmp[cnt]=a[i],genperm(n,m,cnt+1),tag[i]=0;
}

void gen_perm(int n,int m)
{
	int i;
	for(i=0; i<n; i++)	a[i]=i+1,tag[i]=0;
	genperm(n,m,0);
}
