/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  07/31/2012 12:17:23 PM
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
#define N 501000
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

struct node{ int x,t; }no[N];
int top,xx[N],tp,ret[N],q[N];

int cmp(node a,node b){ return a.x==b.x?a.t>b.t:a.x<b.x; }
int cmp1(int x,int y){ return x<y; }

int get_id(int x)
{
	int l=0,r=tp-1,mid;
	for(; l<=r;)
	{
		mid=(l+r)>>1;
		if(xx[mid]<x)
			l=mid+1;
		else if(xx[mid]>x)
			r=mid-1;
		else return mid;
	}
	return -1;
}

int main()
{
	int t,n,ca=1,m;
	scanf("%d",&t);
	for(; ca<=t; ca++)
	{
		printf("Case #%d:\n",ca);
		scanf("%d%d",&n,&m);
		top=0,tp=0;
		for(int i=0; i<n; i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			no[top].x=x,no[top++].t=1;
			no[top].x=y+1,no[top++].t=-1;
		}
		for(int i=0; i<m; i++)
		{
			int x;
			scanf("%d",&x);
			xx[tp++]=x;
			q[i]=x;
		}
		sort(xx,xx+tp,cmp1);
		sort(no,no+top,cmp);
		int pre=xx[0];
		int ntp=1;
		for(int i=1; i<tp; i++)
		{
			if(pre==xx[i])
				continue;
			else
			{
				xx[ntp++]=xx[i];
				pre=xx[i];
			}
		}
		tp=ntp;
		int cnt=0,j=0;
		for(int i=0; i<tp; i++)
		{
			for(; no[j].x<=xx[i]&&j<top; j++)
				cnt+=no[j].t;
			ret[i]=cnt;
		}
		for(int i=0; i<m; i++)
		{
			int id=get_id(q[i]);
			printf("%d\n",ret[id]);
		}
	}
	return 0;
}
