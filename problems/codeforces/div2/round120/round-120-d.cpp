/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  05/16/2012 11:05:44 PM
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
#define N 600010
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

int dat[N],num[N],cnt[N],x[N];

int cmp(int a,int b){ return a<b; }
int top=0;

int get_id(int e)
{
	int l=1,r=top,m;
	for(; l<=r;)
	{
		m=(l+r)>>1;
		if(x[m]==e)
			return m;
		else if(x[m]<e)
			l=m+1;
		else
			r=m-1;
	}
	return -1; //impossible
}

int main()
{
	int n,k,l,r;
	LL ret;
	while(~scanf("%d%d",&n,&k))
	{
		ret=0;
		memset(cnt,0,sizeof(cnt));
		for(int i=1; i<=n; i++)
			scanf("%d",&dat[i]),x[i]=dat[i];
		sort(x+1,x+1+n,cmp);
		int pre=-1;
		top=0;
		for(int i=1; i<=n; i++)
		{
			if(pre!=x[i])
				x[++top]=x[i],pre=x[i];
		}
		int id,pos;
		l=0,r=0,pos=0;
		for(l=1; l<=n; l++)
		{
			if(cnt[pos]>=k)
				ret+=n-r+1;
			else
			{
				if(r==n)	break;
				for(r++; r<=n; r++)
				{
					id=get_id(dat[r]);
					cnt[id]++;
					if(cnt[id]>=k)
						break;
				}
				if(r>n)	break;
				pos=id;
				ret+=n-r+1;
			//	printf("%d %d\n",l,r);
			}
			id=get_id(dat[l]);
			cnt[id]--;
		}
		cout<<ret<<endl;
	}
	return 0;
}
