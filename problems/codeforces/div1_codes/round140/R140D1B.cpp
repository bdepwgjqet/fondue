/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  09/26/2012 08:07:26 PM
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

int dat[N];
LL sum[N];

int cmp(int a,int b){ return a<b; }

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		sum[0]=0;
		for(int i=1; i<=n; i++)
			scanf("%d",&dat[i]);
		sort(dat+1,dat+n+1,cmp);
		for(int i=1; i<=n; i++)
			sum[i]=sum[i-1]+dat[i];
		int m;
		scanf("%d",&m);
		LL kone=0,cnt=1,len;
		for(int i=n-1; i>=1; i--)
		{
			kone+=cnt*dat[i];
			cnt++;
		}

		for(int i=1; i<=m; i++)
		{
			int k;
			scanf("%d",&k);
			if(k==1)
				printf("%I64d\n",kone);
				//printf("%lld\n",kone);
			else
			{
				cnt=1;
				len=k;
				LL ret=0;
				for(LL i=n-1; i>=1;)
				{
					ret+=cnt*(sum[i]-sum[max(i-len,0LL)]);
					i=i-len;
					cnt++;
					len=len*k;
				}
				printf("%I64d\n",ret);
				//printf("%lld\n",ret);
			}
		}
	}
	return 0;
}
