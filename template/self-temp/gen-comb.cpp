//生成组合数
#include <cstdio>
#define MAXN 1000

int dat[MAXN],tmp[MAXN];

void show(int n,int tmp[])
{
	int i;
	for(i=0; i<n; i++)	printf("%d ",tmp[i]);
	puts("");
}

void gencomb(int s,int e,int m,int cnt)
{
	int i;
	if(cnt==m)	show(m,tmp);
	else
		for(i=s; i+m-cnt<=e; i++)
			tmp[cnt++]=dat[i],gencomb(i+1,e,m,cnt),cnt--;
}

void gen_comb(int n,int m)
{
	int i;
	for(i=0; i<n; i++)	dat[i]=i+1;
	gencomb(0,n,m,0);
}


