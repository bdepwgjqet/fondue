/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  03/18/2012 03:45:21 PM
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
#define MAXN 1010
#define MAXM 1000010
#define MOD 1000000007
#define N 80001

typedef long long LL;
using namespace std;


struct line{ LL x,y1,y2; int t; }ln[N];
LL coor[N];
int top,ctop;

inline int L(int i){ return i<<1; }
inline int R(int i){ return (i<<1)|1; }
inline int max(int a,int b){ return a<b?b:a; }
inline int min(int a,int b){ return a<b?a:b; }
inline int abs(int x){ return x<0?-x:x; }
inline int lower_bound(int x){ return x&(-x); }
inline LL length(int l,int r){ return coor[r-1]-coor[l-1]; }
int cmp(line a,line b){ return a.x<b.x; }

struct seg_tree
{
	int l,r,col,cnt,bl,br; LL len;
}segt[N<<2];

void create_tree(int id,int l,int r)
{
	int m=(l+r)>>1;
	segt[id].l=l,segt[id].r=r;
	segt[id].col=segt[id].len=0;
	segt[id].bl=segt[id].br=segt[id].cnt=0;
	if(r-l<=1)
		return;
	create_tree(L(id),l,m);
	create_tree(R(id),m,r);
}

void update(int id,int l,int r)
{
	if(segt[id].col||r==l)
	{
		segt[id].len=length(l,r);
		segt[id].cnt=segt[id].bl=segt[id].br=1;
	}
	else
	{
		segt[id].len=segt[L(id)].len+segt[R(id)].len;
		segt[id].cnt=segt[L(id)].cnt+segt[R(id)].cnt;
		if(segt[L(id)].br&&segt[R(id)].bl)
			segt[id].cnt--;
		segt[id].bl=segt[L(id)].bl;
		segt[id].br=segt[R(id)].br;
	}
}

void insert_seg(int id,int ll,int rr)
{
	int l=segt[id].l,r=segt[id].r,m=(l+r)>>1;
	if(ll==l&&rr==r)
		segt[id].col++;
	else
	{
		if(ll<m)
			insert_seg(L(id),ll,min(m,rr));
		if(rr>m)
			insert_seg(R(id),max(ll,m),rr);
		if(segt[L(id)].col&&segt[R(id)].col)
		{
			segt[L(id)].col--;
			update(L(id),l,m);
			segt[R(id)].col--;
			update(R(id),m,r);
			segt[id].col++;
		}
	}
	update(id,l,r);
}

void del_seg(int id,int ll,int rr)
{
	int l=segt[id].l,r=segt[id].r,m=(l+r)>>1;
	if(ll==l&&rr==r)
		segt[id].col--;
	else if(segt[id].col)
	{
		segt[id].col--;
		if(ll>l)
			insert_seg(id,l,ll);
		if(rr<r)
			insert_seg(id,rr,r);
	}
	else
	{
		if(ll<m)
			del_seg(L(id),ll,min(m,rr));
		if(rr>m)
			del_seg(R(id),max(ll,m),rr);
	}
	update(id,l,r);
}

LL seg_len(int id,int ll,int rr)
{
	int l=segt[id].l,r=segt[id].r,m=(l+r)>>1;
	LL ret=0;
	if(segt[id].col||(ll==l&&rr==r))
		return segt[id].len;
	if(ll<m)
		ret+=seg_len(L(id),ll,min(m,rr));
	if(rr>m)
		ret+=seg_len(R(id),max(ll,m),rr);
	return ret;
}

int get_id(LL x)
{
	int l,r,m; 
	for(l=0,r=ctop-1; l<=r; )
	{
		m=(l+r)>>1;
		if(coor[m]>x)	
			r=m-1;
		else if(coor[m]<x)
			l=m+1;
		else
			return m;
	}
	return -1;	//impossible
}

int main()
{
	int n,i,j,l,r,tag;
	LL x1,x2,y1,y2,pre,ret,h;
	while(scanf("%d",&n)!=EOF)
	{
		y1=0;
		for(ctop=top=i=0; i<n; i++)
		{
			scanf("%lld%lld%lld",&x1,&x2,&y2);
			ln[top].x=x1,ln[top].y1=y1,ln[top].y2=y2;
			ln[top++].t=0;
			ln[top].x=x2,ln[top].y1=y1,ln[top].y2=y2;
			ln[top++].t=1;
			coor[ctop++]=y1,coor[ctop++]=y2;
		}
		sort(coor,coor+ctop);
		sort(ln,ln+top,cmp);
		for(j=0,i=1; i<ctop; i++)
		{
			if(coor[j]==coor[i])
				continue;
			else
				coor[++j]=coor[i];
		}
		ctop=j+1;
		create_tree(1,1,ctop+1);
		pre=ln[0].x;
		for(ret=i=0; i<top; i++)
		{
			l=get_id(ln[i].y1)+1;
			r=get_id(ln[i].y2)+1;
			tag=ln[i].t;
		//	printf("%d %d %lf %lf\n",l,r,segt[1].len,ln[i].x-pre);
			ret+=(ln[i].x-pre)*segt[1].len;
			if(tag)
				del_seg(1,l,r);
			else
				insert_seg(1,l,r);
			pre=ln[i].x;
		}
		printf("%lld\n",ret);
	}
	return 0;
}

