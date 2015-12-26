/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  04/15/2012 02:20:48 PM
 ***/

#include <cstring>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <sstream>
#include <cmath>
#include <functional>
#include <iostream>
#include <algorithm>
#define N 1010000
#define M 1000010
#define S 1000100
#define eps 1e-8
#define inf 0x3fffffff
#define MOD 1000000007
#define PB push_back
#define MP make_pair
#define SZ(a) ((int)((a).size()))
#define ALL(a) (a).begin(),(a).end()
#define CLR(a,x) memset(a,x,sizeof(a))

typedef long long LL;
using namespace std;

inline int L(int i){ return i<<1; }
inline int R(int i){ return (i<<1)|1; }
inline int B(int i){ return 1<<i; }
inline int low_bit(int x){ return x&(-x); }

LL plist[N],p[N],top,oth[N],tmpp[N],tp;

void init()
{
	LL i,j;
	top=0;
	for(i=0; i<N; i++)
		p[i]=i;
	for(i=2; i<N; i++)
	{
		if(p[i]==i)
			plist[top++]=i;
		for(j=0; j<top&&(i*plist[j]<N); j++)
		{
			p[i*plist[j]]=plist[j];
			if(i%plist[j]==0)
				break;
		}
	}
	oth[1]=1;
	for(i=2; i<N; i++)
	{
		LL tmp=i;
		for(; (tmp%p[i]==0)&&tmp>1;)
			tmp/=p[i];
		oth[i]=tmp;
	}
}

LL calc(LL x,LL y,LL cnt,LL id)
{
	LL ret=0;
	if(id==tp)
	{
		if(cnt&1)
			return -x/y;
		else
			return x/y;
	}
	ret+=calc(x,y*tmpp[id],cnt+1,id+1);
	ret+=calc(x,y,cnt,id+1);
	return ret;
}

int main()
{
	int t;
	LL x,l,a,ret,tmp;
	init();
	scanf("%d",&t);
	//while(scanf("%lld",&l),t--)
//	for(l=1; l<1000; l++)
	while(cin>>l,t--)
	{
		if(l<=4)
		{
			puts("0");
			continue;
		}
		ret=0;
		for(a=2; a*a<l; a+=2)
		{
			x=(LL)sqrt(double(l-a*a));
			LL tmp=a;
			for(tp=0; tmp>1; )
			{
				tmpp[tp++]=p[tmp];
				tmp=oth[tmp];
			}
			tmp=calc(x,1LL,0LL,0LL);
			ret+=tmp;
			//printf("%lld %lld\n",x,tmp);
		}
		//printf("%lld\n",ret);
		cout<<ret<<endl;
	}
	return 0;
}
