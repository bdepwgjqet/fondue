/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  08/28/2012 01:59:06 PM
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

struct point{ int l,r; }p[N];
struct segment{ int l,lp,rp,d;
	friend bool operator <(segment a,segment b)
	{
		int la=(a.l-1)>>1,lb=(b.l-1)>>1;
		return a.d==b.d?((a.lp==b.lp)?a.rp<b.rp:a.lp<b.lp):a.d>b.d;
	}
}seg[N],pool[N<<2];
set<segment> st;
set<segment>::iterator it;
int pos[N],top,n;

void addseg(int lp,int rp)
{
	pool[top].lp=lp,pool[top].rp=rp,pool[top].l=pool[top].rp-pool[top].lp-1;
	if(lp==0||rp==n+1)
		pool[top].d=pool[top].l;
	else
		pool[top].d=(pool[top].l+1)/2;
	if(pool[top].l>0)
	{
		st.insert(pool[top]);
	}
	top++;
}

void eraseseg(int lp,int rp)
{
	pool[top].lp=lp,pool[top].rp=rp,pool[top].l=pool[top].rp-pool[top].lp-1;
	if(lp==0||rp==n+1)
		pool[top].d=pool[top].l;
	else
		pool[top].d=(pool[top].l+1)/2;
	if(pool[top].l<=0)
		return;
	it=st.find(pool[top]);
	if(it!=st.end())
		st.erase(it);
	top++;
}

int main()
{
	int m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		st.clear();
		top=0;
		addseg(0,n+1);
		int x,id;
		for(int i=0; i<m; i++)
		{
			scanf("%d%d",&x,&id);
			if(x==1)
			{
				int nowp;
				it=st.begin();
				if(it->lp==0)
					nowp=1;
				else if(it->rp==n+1)
					nowp=n;
				else
				{
					nowp=it->lp+(it->l+1)/2;
				}
				pos[id]=nowp;
				printf("%d\n",nowp);
				p[nowp].l=it->lp,p[nowp].r=it->rp;
				p[it->lp].r=nowp;
				p[it->rp].l=nowp;
				addseg(it->lp,nowp);
				addseg(nowp,it->rp);
				st.erase(it);
			}
			else
			{
				int nowp=pos[id];
				p[p[nowp].l].r=p[nowp].r;
				p[p[nowp].r].l=p[nowp].l;
				eraseseg(p[nowp].l,nowp);
				eraseseg(nowp,p[nowp].r);
				addseg(p[nowp].l,p[nowp].r);
			}
		}
	}
	return 0;
}
