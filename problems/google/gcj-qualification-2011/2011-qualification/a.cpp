/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  04/09/2012 03:45:53 PM
 ***/

#include <cstring>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cmath>
#include <iostream>
#include <algorithm>
#define N 111
#define M 1000010
#define S 1000100
#define eps 1e-8
#define inf 0x3fffffff
#define MOD 1000000007
#define PB push_back
#define SZ(a) ((int)((a).size()))
#define ALL(a) (a).begin(),(a).end()
#define CLR(a,x) memset(a,x,sizeof(a))

typedef long long LL;
using namespace std;

inline int L(int i){ return i<<1; }
inline int R(int i){ return (i<<1)|1; }
inline int B(int i){ return 1<<i; }
inline int low_bit(int x){ return x&(-x); }

struct node{ char x; int i; }no[N];
int top,OO[N],BB[N],otop,btop;
char s[6];

int sig(int x){ return x>0?1:-1; }

int solve(int &bp,int bo,int &op,int oo)
{
	int st=abs(bo-bp)+1;
	if(st>=abs(oo-op))
		op=oo;
	else
		op=op+sig(oo-op)*st;
	bp=bo;
	return st;
}

int main()
{
	int t,n,m,ca,ret,x;
	scanf("%d",&t);
	for(ca=1; ca<=t; ca++)
	{
		printf("Case #%d: ",ca);
		scanf("%d",&n);
		top=otop=btop=0;
		for(int i=0; i<n; i++)
		{
			scanf("%s%d",s,&x);
			no[top].x=s[0];
			no[top++].i=x;
			if(s[0]=='O')
				OO[otop++]=x;
			else
				BB[btop++]=x;
		}
		int bp=1,op=1,i,onow=0,bnow=0;
		ret=0;
		for(i=0; i<top; i++)
		{
			if(no[i].x=='O')
				ret+=solve(op,OO[onow++],bp,BB[bnow]);
			else
				ret+=solve(bp,BB[bnow++],op,OO[onow]);
		}
		printf("%d\n",ret);
	}
	return 0;
}
