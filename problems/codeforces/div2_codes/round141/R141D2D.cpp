#include <cstdio>
#include <iostream>
#define N 100100

using namespace std;
typedef long long LL;

struct bit
{
	LL a[N];
	int lb(int x){ return x&(-x); }
	LL sum(int i)
	{
		LL ret=0;
		for(; i>0; i-=lb(i))
			ret+=a[i];
		return ret;
	}

	LL query(int l,int r)
	{
		return sum(r)-sum(l-1);
	}

	LL update(int i,int x)
	{
		for(; i<N; i+=lb(i))
			a[i]+=x;
	}
}tr[7][14];

inline int get(int x){ return (x-1)<<1; }

int dat[N];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
	{
		int x;
		scanf("%d",&x);
		dat[i]=x;
		for(int j=2; j<=6; j++)
			tr[j][i%get(j)].update(i,x);
	}
	int q;
	scanf("%d",&q);
	for(int i=0; i<q; i++)
	{
		int x,p,l,r,z;
		scanf("%d",&x);
		if(x==1)
		{
			scanf("%d%d",&p,&x);
			int del=x-dat[p];
			for(int j=2; j<=6; j++)
				tr[j][p%get(j)].update(p,del);
			dat[p]=x;
		}
		else
		{
			scanf("%d%d%d",&l,&r,&z);
			LL ret=0,b=1;
			for(int i=l; i<l+get(z)&&i<=r; i++)
			{
				ret+=b*tr[z][i%get(z)].query(i,r);
				if(i-l+1<z)
					b++;
				else
					b--;
			}
			cout<<ret<<endl;
		}
	}
	return 0;
}
