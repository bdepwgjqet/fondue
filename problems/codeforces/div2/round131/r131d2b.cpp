/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  07/31/2012 07:56:07 PM
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
#define N 1010
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

int cnt[10];

int main()
{
	int n,x,ttl=0;
	scanf("%d",&n);
	for(int i=0; i<n; i++)
	{
		scanf("%d",&x);
		ttl+=x;
		cnt[x]++;
	}
	x=ttl%3;
	int i;
	if(x!=0)
	{
		for(i=x; i<10; i+=3)
			if(cnt[i]>0)
			{
				cnt[i]--;
				break;
			}
		if(i>=10)
		{
			i=(x==1)?2:1;
			int lf=2;
			for(; i<10&&lf>0; i+=3)
			{
				while(cnt[i]>0&&lf>0)
				{
					cnt[i]--;
					lf--;
				}
				if(lf==0)
					break;
			}
			if(i>=10)
			{
				puts("-1");
				return 0;
			}
		}
	}
	if(cnt[0]>0)
	{
		int tt=0;
		for(int i=0; i<=9; i++)
			tt+=cnt[i];
		if(tt==cnt[0])
			puts("0");
		else
		{
			for(int i=9; i>=0; i--)
				for(int j=0; j<cnt[i]; j++)
					printf("%d",i);
			puts("");
		}
	}
	else
		puts("-1");
	return 0;
}
