/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  08/18/2012 02:38:00 PM
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

int got(int up,int dn,int n)
{
	int ret=0,cnt=0;
	for(;;)
	{
		if(up==0&&dn==1)
		{
			if(cnt==n)
			{
				return ret;
			}
			else
				return inf;
		}
		if((dn==0)||(up==0&&dn>1))
			return inf;
		if(up>dn)
		{
			ret+=max((up/dn)-1,0);
			cnt+=up/dn;
			up=up%dn;
		}
		else
		{
			if(up==1)
			{
				ret+=max(dn-2,0);
				cnt+=dn;
				if(cnt==n)
					return ret;
				else
					return inf;
			}
			else
				ret+=max((dn/up)-1,0);
			cnt+=dn/up;
			dn=dn%up;
		}
	}
	return inf; //impossible
}

void show(int u,int d)
{
	if(u==1&&d==1)
	{
		printf("T");
		return;
	}
	if(u>d)
	{
		show(u-d,d);
		printf("T");
	}
	else
	{
		show(u,d-u);
		printf("B");
	}
}

int main()
{
	int n,r;
	while(scanf("%d%d",&n,&r)!=EOF)
	{
		int up,dn,cnt,ret=inf,rd,ru;
		for(int i=1; i<=r; i++)
		{
			up=r,dn=i;
			cnt=got(up,dn,n);
			if(cnt<ret)
			{
				ret=cnt;
				ru=up,rd=dn;
			}
			up=i,dn=r;
			cnt=got(up,dn,n);
			if(cnt<ret)
			{
				ret=cnt;
				ru=up,rd=dn;
			}
		}
		if(ret>=inf)
			puts("IMPOSSIBLE");
		else
		{
			printf("%d\n",ret);
			show(ru,rd);
			puts("");
		}
	}
	return 0;
}
