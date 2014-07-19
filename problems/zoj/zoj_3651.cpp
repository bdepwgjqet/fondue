#include <cstdio>
#include <cstring>
#include <algorithm>
#define MOD 1234567890

using namespace std;
typedef long long LL;

LL ret[4][4],mat[4][4],tmp[4][4];
LL p,q,n;

struct node{ LL i,a,b; }no[9];

void mul(LL c[][4],LL a[][4],LL b[][4])
{
	memset(tmp,0,sizeof(tmp));
	for(int i=0; i<4; i++)
		for(int j=0; j<4; j++)
			for(int k=0; k<4; k++)
				tmp[i][j]=(tmp[i][j]+a[i][k]*b[k][j])%MOD;
	for(int i=0; i<4; i++)
		for(int j=0; j<4; j++)
			c[i][j]=tmp[i][j];
}

int cal(LL a,LL b,LL x,LL y,LL n)
{
	memset(ret,0,sizeof(ret));
	memset(mat,0,sizeof(mat));
	for(int i=0; i<4; i++)
		ret[i][i]=1;
	mat[0][0]=mat[0][1]=mat[0][2]=mat[1][3]=mat[2][3]=1;
	mat[1][0]=mat[1][1]=mat[3][2]=(q-1)%MOD;
	mat[2][0]=mat[2][2]=mat[3][1]=(p-1)%MOD;
	mat[3][3]=(p>1&&q>1)?(p+q-3)%MOD:0;
	for(; n;)
	{
		if(n&1)
			mul(ret,ret,mat);
		mul(mat,mat,mat);
		n>>=1;
	}
	LL rr=0;
	int st=0;
	st=(a!=x)*2+(b!=y);
	for(int i=0; i<3; i++)
		rr=(rr+ret[i][st])%MOD;
	return int(rr);
}

int cmp(node a,node b){ return a.i<b.i; }

int main()
{
	while(scanf("%lld%lld%lld",&n,&p,&q)+1)
	{
		for(int i=0; i<8; i++)
			scanf("%lld%lld%lld",&no[i].i,&no[i].a,&no[i].b);
		sort(no,no+8,cmp);
		no[8]=no[0];
		LL pre=no[0].i,rr=1;
		for(int i=1; i<9; i++)
		{
			if(no[i].i==pre)
			{
				if(no[i].a==no[i-1].a&&no[i].b==no[i-1].b)
					continue;
				rr=0;
			}
			else
			{
				rr=rr*cal(no[i].a,no[i].b,no[i-1].a,no[i-1].b,(no[i].i-pre+n)%n-1)%MOD;
			}
			pre=no[i].i;
		}
		printf("%lld\n",rr);
	}
	return 0;
}
