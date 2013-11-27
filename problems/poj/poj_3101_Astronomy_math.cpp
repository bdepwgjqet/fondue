/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  03/08/2012 07:22:07 PM
 ***/

#include <cstring>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>
#define inf 0x7fffffff
#define X 10011
#define N 1010
#define MAXM 1000010
#define MOD 1000000007
#define DIGIT 4
#define DEPTH 10000
#define MAXN  8502
typedef int big_num[MAXN+1];
big_num reta,retb;

typedef long long LL;
using namespace std;

inline int L(int i){ return i<<1; }
inline int R(int i){ return (i<<1)|1; }
inline int max(int a,int b){ return a<b?b:a; }
inline int min(int a,int b){ return a<b?a:b; }
inline int abs(int x){ return x<0?-x:x; }
inline int cmp(int a,int b){ return a<b; }

int T[N];
int fac[X],plist[X],isp[X],top,cnt[X];

void write(const big_num a)
{
    int i,j;
    for(printf("%d",a[i=a[0]]),i--; i; i--)
        for(j=DEPTH/10; j; j/=10)
            printf("%d",a[i]/j%10);
}

void mul(big_num a,const int b)     // AC
{
    int i;
    for(a[1]*=b,i=2; i<=a[0]; i++)
    {
        a[i]*=b;
        if(a[i-1]>=DEPTH)
            a[i]+=a[i-1]/DEPTH,a[i-1]%=DEPTH;
    }
    for(; a[a[0]]>=DEPTH; a[a[0]+1]=a[a[0]]/DEPTH,a[a[0]]%=DEPTH,a[0]++);
    for(; !a[a[0]] && a[0]>1; a[0]--);
}

void init()
{
	int i,t,j;
	for(top=i=0; i<X; i++)	isp[i]=i;
	for(i=2; i<X; i++)
	{
		if(isp[i]==i)	plist[top++]=i;
		for(j=0; j<top&&i*plist[j]<X; j++)
		{
			isp[i*plist[j]]=plist[j];
			if(i%plist[j]==0)	break;
		}
	}
	/*
	for(i=0; i<10; i++)
		printf("%d ",plist[i]);
		*/
}

void operate(int x,int tag)
{
	int tcnt,a;
	for(; x>1;)
	{
		a=isp[x];
		for(tcnt=0; x%a==0; )
			tcnt++,x/=a;
		cnt[a]+=tag*tcnt;
	}
}

void update()
{
	int i;
	for(i=1; i<X; i++)
		fac[i]=max(fac[i],cnt[i]);
}

void solve()
{
	int i,j;
	memset(reta,0,sizeof(reta));
	memset(retb,0,sizeof(retb));
	reta[0]=reta[1]=1;
	retb[0]=retb[1]=1;
	for(i=2; i<X; i++)
		if(fac[i]>-inf)
		{
			if(fac[i]<0)
				for(j=0; j<-fac[i]; j++)
					mul(retb,i);
			else
				for(j=0; j<fac[i]; j++)
					mul(reta,i);
		}
}

int gcd(int a,int b){ return b==0?a:gcd(b,a%b); }

int main()
{
	int n,x,pre,tcnt,y1,y2,g,i;
	init();
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0; i<X; i++)
			fac[i]=-inf;
		for(i=0; i<n; i++)
			scanf("%d",&T[i]);
		sort(T,T+n,cmp);
		for(i=1; i<n; i++)
		{
			y1=T[i],y2=T[i-1];
			x=2*(T[i]-T[i-1]);
		//	printf("%d %d %d=>\n",x,y1,y2);
			if(x==0)	continue;
			g=gcd(y1,x);
			y1/=g,x/=g;
			g=gcd(y2,x);
			y2/=g,x/=g;
			memset(cnt,0,sizeof(cnt));
			operate(x,-1);
			operate(y1,1);
			operate(y2,1);
			update();
		}
		solve();
		
		/*
		for(i=0; i<10; i++)
			printf("%d ",fac[i]);
		puts("");
		*/
		
		write(reta);
		printf(" ");
		write(retb);
		puts("");
	}
	return 0;
}
