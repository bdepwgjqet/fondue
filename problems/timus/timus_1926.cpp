#include <cstdio>
#include <iostream>
#include <cstring>
#define N 100101
#define M 100
#define X 15

using namespace std;
typedef long long LL;

int dp[X][N];
int id[100],p[100],plist[100],top;
int ret[X];
char s[N];

LL b[X],w[X];
int tp;

LL ext_gcd(LL a,LL b,LL &x,LL &y)
{
	if(!b) return x=1,y=0,a;
	LL g=ext_gcd(b,a%b,y,x);
	y-=a/b*x;
	return g;
}

LL modular_linear_system(LL b[],LL w[],LL k)
{
	LL t,d,x,y,ret=b[0],m=w[0],tt,fac,nextm,i;
	for(i=1; i<k; i++)
	{
		d=ext_gcd(m,w[i],x,y);
		t=b[i]-ret;
		if(t%d)	return -1;
		tt=w[i]/d;
		fac=(x*(t/d)%tt+tt)%tt;
		nextm=m/d*w[i];
		ret=((ret+m*fac)%nextm+nextm)%nextm;
		m=nextm;
	}
	return (ret%m+m)%m;
}

void init()
{
	top=0;
	for(int i=0; i<M; i++)
		p[i]=i;
	for(int i=2; i<M; i++)
	{
		if(p[i]==i)
			plist[top++]=i;
		for(int j=0; j<top&&i*plist[j]<M; j++)
		{
			p[i*plist[j]]=plist[j];
			if(i%plist[j]==0)
				break;
		}
	}
	for(int i=0; plist[i]<=47; i++)
		id[plist[i]]=i;
	for(int i=0; i<X; i++)
	{
		dp[i][1]=1;
		for(int j=2; j<=N; j++)
		{
			int x=dp[i][j-1];
			dp[i][j]=x*10%plist[i];
		}
	}
}

int main()
{
	init();
	int n;
	while(scanf("%s",s)+1)
	{
		n=strlen(s);
		for(int i=0; i<n; i++)
			s[i]-='0';
		for(int i=0; i<X; i++)
		{
			int r=0;
			for(int j=0; j<n; j++)
			{
				r*=10,r+=s[j];
				r=r%plist[i];
			}
			ret[i]=r%plist[i];
		}
		int m;
		scanf("%d",&m);
		for(; m--;)
		{
			int tag,x,y;
			scanf("%d",&tag);
			if(tag==0)
			{
				LL now;
				cin>>now;
				if(now==1)
				{
					puts("0");
					continue;
				}
				tp=0;
				for(int i=0; i<X; i++)
					if(now%plist[i]==0)
					{
						w[tp]=plist[i];
						now/=plist[i];
						if(now%plist[i]==0)
							for(;;);
						b[tp]=ret[i];
						tp++;
					}
				LL ans=modular_linear_system(b,w,tp);
				cout<<ans<<endl;
			}
			else
			{
				scanf("%d%d",&x,&y);
				for(int i=0; i<X; i++)
				{
					int md=dp[i][x],d=y-s[n-x];
					md=d*md;
					ret[i]=((ret[i]+md)%plist[i]+plist[i])%plist[i];
				}
				s[n-x]=y;
			}
		}
	}
	return 0;
}
