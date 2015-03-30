#include <cstdio>
#define MAXN 100
typedef long long LL;

LL gcd(LL a,LL b){ return b?gcd(b,a%b):a; }
LL lcm(LL a,LL b){ return a*b/gcd(a,b); }

//扩展Euclid求解gcd(a,b)=ax+by 
LL ext_gcd(LL a,LL b,LL &x,LL &y)
{
	if(!b) return x=1,y=0,a;
	LL g=ext_gcd(b,a%b,y,x);
	y-=a/b*x;
	return g;
}

//求解模线性方程ax=b (mod m) 
//返回解的个数,解保存在 sol[]中 
LL modular_linear(LL a,LL b,LL m,LL sol[])
{
	LL d,e,x,y,i;
	d=ext_gcd(a,m,x,y);
	if(b%d)	return 0;
	e=(x*(b/d)%m+m)%m;
	for(i=0; i<d; i++)
		sol[i]=(e+i*(m/d))%m;
	return d;
}

//求解模线性方程组(中国剩余定理) 
//  x = b[0] (mod w[0]) 
//  x = b[1] (mod w[1]) 
//  ... 
//  x = b[k-1] (mod w[k-1]) 
//要求w[i]>0,w[i]与 w[j]互质,解的范围1..n,n=w[0]*w[1]*...*w[k-1] 
LL modular_linear_system(LL b[],LL w[],LL k)
{
	LL d,x,y,ret=0,m,n=1,i;
	for(i=0; i<k; i++)	n*=w[i];
	for(i=0; i<k; i++)
	{
		m=n/w[i];
		d=ext_gcd(w[i],m,x,y);
		ret=(ret+y*m*b[i])%n;
	}
	return (ret+n)%n;
}

//求解模线性方程组(中国剩余定理) 
//  x = b[0] (mod w[0]) 
//  x = b[1] (mod w[1]) 
//  ... 
//  x = b[k-1] (mod w[k-1]) 
//要求w[i]>0,w[i]与 w[j]可以不互质,解的范围0,1..m-1,m=w[i]...的最小公倍数
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
