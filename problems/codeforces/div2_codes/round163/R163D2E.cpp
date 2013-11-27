#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define MOD 1000000007
#define N 100010
#define K 6

using namespace std;
typedef long long LL;

struct node{ int l,r,x; LL s[K];
	int gm(){ return (l+r)>>1; }
}no[N<<2];

int dat[N];
LL C[K][K],S[N][K];

inline int L(int i){ return i<<1; }
inline int R(int i){ return i<<1|1; }

LL power(LL a,LL b)
{
	LL ret=1;
	for(; b; b>>=1,a=a*a%MOD)
		if(b&1)
			ret=ret*a%MOD;
	return ret;
}

void up(int id)
{
	for(int i=0; i<K; i++)
		no[id].s[i]=(no[L(id)].s[i]+no[R(id)].s[i])%MOD;
}

void build(int id,int l,int r)
{
	no[id].x=-1,no[id].l=l,no[id].r=r;
	if(l==r)
	{
		no[id].x=dat[l];
		no[id].s[0]=dat[l];
		for(int i=1; i<K; i++)
		{
			no[id].s[i]=dat[l]*power(l,i)%MOD;
		}
		return;
	}
	build(L(id),l,no[id].gm());
	build(R(id),no[id].gm()+1,r);
	up(id);
}

void paint(int id,int l,int r,int x)
{
	no[id].x=x;
	for(int i=0; i<K; i++)
		no[id].s[i]=x*((S[r][i]-S[l-1][i])%MOD+MOD)%MOD;
}

void down(int id)
{
	if(no[id].x>=0)
	{
		paint(L(id),no[id].l,no[id].gm(),no[id].x);
		paint(R(id),no[id].gm()+1,no[id].r,no[id].x);
		no[L(id)].x=no[id].x;
		no[R(id)].x=no[id].x;
		no[id].x=-1;
	}
}

void update(int id,int l,int r,int x)
{
	int ll=no[id].l,rr=no[id].r,mid=no[id].gm();
	if(ll>=l&&rr<=r)
	{
		paint(id,ll,rr,x);
		return;
	}
	down(id);
	if(r>=ll&&l<=mid)
		update(L(id),l,r,x);
	if(l<=rr&&r>mid)
		update(R(id),l,r,x);
	up(id);
}

LL query(int id,int l,int r,int k)
{
	int ll=no[id].l,rr=no[id].r,mid=no[id].gm();
	if(ll>=l&&rr<=r)
		return no[id].s[k];
	LL ret=0;
	down(id);
	if(r>=ll&&l<=mid)
		ret=(ret+query(L(id),l,r,k))%MOD;
	if(l<=rr&&r>mid)
		ret=(ret+query(R(id),l,r,k))%MOD;
	up(id);
	return ret;
}

void init()
{
	C[0][0]=C[1][0]=C[1][1]=1;
	for(int i=2; i<K; i++)
	{
		C[i][0]=1;
		for(int j=1; j<i; j++)
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
		C[i][i]=1;
	}
	memset(S,0,sizeof(S));
	for(int i=1; i<N; i++)
		for(int j=0; j<K; j++)
			S[i][j]=(S[i-1][j]+power(i,j))%MOD;
}

LL cal(int l,int r,int k)
{
	LL ret=0;
	for(int i=0; i<=k; i++)
	{
		LL pp=query(1,l,r,i);
		ret=(ret+C[k][i]*pp%MOD*power(1-l,k-i))%MOD;
	}
	return (ret+MOD)%MOD;
}

int main()
{
	int n,m;
	init();
	while(scanf("%d%d",&n,&m)+1)
	{
		for(int i=1; i<=n; i++)
			scanf("%d",&dat[i]);
		build(1,1,n);
		for(int i=0; i<m; i++)
		{
			char s[3];
			int x,y,z;
			scanf("%s%d%d%d",s,&x,&y,&z);
			if(s[0]=='=')
				update(1,x,y,z);
			else
				cout<<cal(x,y,z)<<endl;
		}
	}
	return 0;
}
