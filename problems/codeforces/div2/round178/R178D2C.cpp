#include <cstdio>
#include <cstring>
#include <iostream>
#define N 1101
#define MOD 1000000007

typedef long long LL;
using namespace std;

int tag[N];
LL c[N][N];

LL cal(LL a,LL b)
{
	if(b<0) return 1;
	LL ret=1;
	for(; b; b>>=1)
	{
		if(b&1)
			ret=ret*a%MOD;
		a=a*a%MOD;
	}
	return ret;
}

int main()
{
	int n,m;
	c[0][0]=1;
	c[1][0]=c[1][1]=1;
	for(int i=2; i<N; i++)
	{
		c[i][0]=1;
		for(int j=1; j<i; j++)
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%MOD;
		c[i][i]=1;
	}
	memset(tag,0,sizeof(tag));
	scanf("%d%d",&n,&m);
	if(m==0) 
	{
		puts("0");
		return 0;
	}
	for(int i=0; i<m; i++)
	{
		int x;
		scanf("%d",&x);
		tag[x]=1;
	}
	int l,r,ttl=0;
	for(int i=1; i<=n; i++)
		if(tag[i]==0) ttl++;
	LL ret=1;
	for(l=1; l<=n; l++)
		if(tag[l])
		{
			ret=ret*c[ttl][l-1]%MOD;
			ttl-=l-1;
			break;
		}
	for(r=n; r>=l; r--)
		if(tag[r])
		{
			ret=ret*c[ttl][n-r]%MOD;
			ttl-=n-r;
			break;
		}
	int pre=l,now=l;
	for(int i=l; i<=r; i++)
		if(tag[i])
		{
			now=i;
			ret=ret*c[ttl][now-pre]%MOD;
			ttl-=now-pre;
			ret=ret*cal(2,now-pre-1)%MOD;
			for(; i<=r; i++)
				if(!tag[i])
				{
					pre=i;
					break;
				}
		}
	cout<<ret<<endl;
	return 0;
}
