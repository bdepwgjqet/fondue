/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  08/06/2012 11:29:07 PM
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
#define N 101000
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

struct node{ LL t,c,T,x; }no[N];
int n,m;

LL get(int i)
{
	LL ret=0;
	if(no[i].t>=no[i].T)
		return no[i].c+m*no[i].x;
	else
	{
		if(m>no[i].T-no[i].t)
		{
			LL k=(m%(no[i].T-no[i].t));
			LL y=(m/(no[i].T-no[i].t));
			if(k==0)
				return min(no[i].c*y,no[i].c+no[i].x*m);
			else
			{
				return min(no[i].c+no[i].x*m,min(no[i].c*y+no[i].x*(no[i].T-no[i].t+k),no[i].c*(y+1)));
			}
		}
		else
			return no[i].c;
	}
}

int main()
{
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		int t,c,tt,x;
		for(int i=0; i<n; i++)
		{
			scanf("%d%d%d%d",&t,&tt,&x,&c);
			no[i].t=t,no[i].T=tt,no[i].x=x,no[i].c=c;
		}
		LL ret=0;
		for(int i=0; i<n; i++)
		{
			ret+=get(i);
		}
		cout<<ret<<endl;
	}
	return 0;
}
