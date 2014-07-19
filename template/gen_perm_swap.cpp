//产生邻位交换全排列O(n!)
#include <cstdio>
#include <cstring>
#define MAXN 1000

int pos[MAXN],dir[MAXN],a[MAXN];

void show(int n,int tmp[])
{
	int i;
	for(i=0; i<n; i++)	printf("%d ",tmp[i]);
	puts("");
}

void _gen_perm_swap(int n,int l)
{
	int p1,p2,i,t;
	if(l==n)	show(n,a);
	else
	{
		_gen_perm_swap(n,l+1);
		for(i=0; i<l; i++)
		{
			p2=(p1=pos[l])+dir[l];
			t=a[p2],a[p2]=a[p1],a[p1]=t;
			pos[a[p1]-1]=p1,pos[a[p2]-1]=p2;
			_gen_perm_swap(n,l+1);
		}
	}
	dir[l]=-dir[l];
}

void gen_perm_swap(int n)
{
	int i;
	for(i=0; i<n; i++)	a[i]=i+1,dir[i]=-1,pos[i]=i;
	_gen_perm_swap(n,0);
}

