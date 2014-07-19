/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  09/20/2012 12:05:14 AM
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

LL dat[1000000];
int list[1000000];

int main()
{
	int n,k;
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		dat[0]=0,dat[1]=1;
		int top=0;
		for(int i=2; ; i++)
		{
			LL now=0;
			for(int j=i-1; j>=0&&j>=i-k; j--)
				now+=dat[j];
			dat[i]=now;
			if(dat[i]>n)
			{
				top=i;
				break;
			}
		}
		int ret=0,id=top-1;
		if(dat[id]==n)
			list[ret++]=0;
		for(; id>=1&&n;)
		{
			for(; dat[id]>n&&id>=1; id--);
			list[ret++]=dat[id],n-=dat[id];
		}
		printf("%d\n",ret);
		for(int i=0; i<ret; i++)
			printf("%d ",list[i]);
		puts("");
	}
	return 0;
}
