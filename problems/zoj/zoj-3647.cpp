#include <cstdio>
#include <cstring>
#define N 1011
typedef long long LL;

LL comb(LL a)
{
	if(a<=2) return 0;
	return a*(a-1)*(a-2)/6;
}

LL com2(LL x)
{
	if(x<=1) return 0;
	return x*(x-1)/2;
}

int gcd(int a,int b){ return b?gcd(b,a%b):a; }
LL f[N][N];

void init()
{
	memset(f,0,sizeof(f));
	for(int i=0; i<N; i++)
	{
		f[1][i]=f[i][1]=com2(i);
		f[0][i]=f[i][0]=com2(i);
	}
	for(int i=2; i<N; i++)
		for(int j=i; j<N; j++)
			f[j][i]=f[i][j]=f[i-1][j]+f[i][j-1]-f[i-1][j-1]+gcd(i,j)-1;
}

int main()
{
	int n,m;
	init();
	while(scanf("%d%d",&m,&n)+1)
	{
		LL ret=0,cnt=(n+1)*(m+1);
		ret=comb(cnt);
		LL ans=0,tmp;
		for(int i=0; i<=m; i++)
			for(int j=0; j<=n; j++)
			{
				tmp=f[i][j]+f[m-i][n-j]+f[i][n-j]+f[m-i][j]-com2(i)-com2(j)-com2(m-i)-com2(n-j);
				ans+=tmp;
			}
		printf("%lld\n",ret-ans/2);
	}
	return 0;
}
