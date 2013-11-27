#include <cstdio>
#include <cstring>

typedef long long LL;
const int MOD=1000000007;
const int X=222222224;

LL mat[2][2]={3,1,1,0},ret[2][2],tmp[2][2];

void mul(LL a[][2],LL b[][2],LL c[][2],int mod)
{
	memset(tmp,0,sizeof(tmp));
	for(int i=0; i<2; i++)
		for(int j=0; j<2; j++)
			for(int k=0; k<2; k++)
				tmp[i][j]=(tmp[i][j]+b[i][k]*c[k][j])%mod;
	for(int i=0; i<2; i++)
		for(int j=0; j<2; j++)
			a[i][j]=tmp[i][j];
}

void show(LL ret[][2])
{
	for(int i=0; i<2; i++,puts(""))
		for(int j=0; j<2; j++)
			printf("%lld ",ret[i][j]);
}

LL g(LL n,int mod)
{
	if(n==0)
		return 0;
	n--;
	memset(ret,0,sizeof(ret));
	ret[1][1]=ret[0][0]=1;
	mat[0][0]=3,mat[0][1]=1,mat[1][0]=1,mat[1][1]=0;
	for(; n; n>>=1)
	{
		if(n&1)
			mul(ret,ret,mat,mod);
		mul(mat,mat,mat,mod);
	}
	return ret[0][0];
}

int main()
{
	LL n;
	while(scanf("%I64d",&n)!=EOF)
//	while(scanf("%lld",&n)!=EOF)
	{
		n%=240;
//		printf("%lld\n",g(g(g(n,X),X),MOD));
		printf("%I64d\n",g(g(g(n,183120),X),MOD));
	}
	/*
	int i,a=0,b=1,c;
	for(int i=2; i<10; i++)
	{
		c=(a+3LL*b)%MOD;
		a=b;
		b=c;
		printf("%d\n",c);
		printf("%lld=>\n",g(i,MOD));
	}
	*/
	return 0;
}
