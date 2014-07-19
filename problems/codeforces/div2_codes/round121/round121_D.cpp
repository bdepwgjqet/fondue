/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  07/27/2012 04:52:18 PM
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
#define N 100010
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


struct node{ int x,i; }no[N];
LL a[N];
int tag[N];
int cmp(node a,node b){ return a.x>b.x; }

int main()
{
	int n,k;
	LL b,s1,s2;
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		cin>>b;
		s1=s2=0;
		memset(tag,0,sizeof(tag));
		for(int i=0; i<n; i++)
		{
			int x;
			scanf("%d",&x);
			a[i]=x;
			no[i].x=x,no[i].i=i;
		}
		sort(no,no+n-1,cmp);
		for(int i=0; i<k; i++)
		{
			tag[no[i].i]=1;
			s1+=no[i].x;
		}
		s2=s1-no[k-1].x;
		int ret=-1;
		for(int i=0; i<n; i++)
		{
			if(tag[i])
			{
				if(s1>b)
				{
					ret=i+1;
					break;
				}
			}
			else if(s2+a[i]>b)
			{
				ret=i+1;
				break;
			}
		}
		if(ret==-1)
			ret=n;
		printf("%d\n",ret);
	}
	return 0;
}
