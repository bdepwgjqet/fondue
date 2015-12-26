/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  03/17/2012 09:54:36 PM
 ***/

#include <cstring>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>
#define MAXN 1010
#define MAXM 1000010
#define MOD 1000000007
#define N 81000
#define M 1000010

typedef long long LL;
using namespace std;

inline int L(int i){ return i<<1; }
inline int R(int i){ return (i<<1)|1; }
inline int max(int a,int b){ return a<b?b:a; }
inline int min(int a,int b){ return a<b?a:b; }
inline int abs(int x){ return x<0?-x:x; }

struct line{ int x1,y1,x2,y2,t,i,w; double k; }ln[N];

int coor[N<<1],next[N],top,q[M],ctop,in[N],ret[N];

int cmp(line a,line b){ return a.x1==b.x1?(a.y1==b.y1?a.y2<b.y2:a.y1<b.y1):a.x1<b.x1; }

int lower_equ(int x,int id,int y)
{
	double h=ln[id].k*(x-ln[id].x1)+ln[id].y1;
	return h<=y;
}

void add(int x,int id)
{
	int i,k=-1;
	for(i=top-1; i>=0; i--)
		if(lower_equ(x,q[i],ln[id].y1))
		{
			k=i;
			break;
		}
	for(i=top; i>k+1; i--)
		q[i]=q[i-1];
	q[k+1]=id;
	top++;
}

void update(int x)
{
	int i,x1,x2,del,j;
	for(i=1; i<top; i++)
	{
		x1=ln[q[i]].x1,x2=ln[q[i]].x2;
		del=ln[q[i]].y1-ln[q[i]].y2;
		if((x1==x&&del<0)||(x2==x&&del>0))
		{
			//printf("%d %d=>\n",q[i],q[i-1]);
			next[q[i]]=q[i-1];
			in[q[i-1]]++;
		}
	}
	for(j=i=0; i<top; i++)
	{
		if(ln[q[i]].x2==x)
			continue;
		else
			q[j++]=q[i];
	}
	top=j;
}

void topo_sort(int n)
{
	int i,l,r,t;
	l=0,r=-1;
	for(i=0; i<n; i++)
		if(in[i]==0)
			q[++r]=i;
	for(; l<=r; )
	{
		t=q[l++];
		if(next[t]<0)
			continue;
		ln[next[t]].w+=ln[t].w;
		in[next[t]]--;
		if(in[next[t]]==0)
			q[++r]=next[t];
	}
	for(i=0; i<n; i++)
		ret[ln[i].i]=ln[i].w;
}

int main()
{
	int n,i,j,pre;
	while(scanf("%d\n",&n)!=EOF)
	{
		memset(in,0,sizeof(in));
		memset(next,-1,sizeof(next));
		memset(ret,0,sizeof(ret));
		for(ctop=i=0; i<n; i++)
		{
			scanf("%d%d%d%d",&ln[i].x1,&ln[i].y1,&ln[i].x2,&ln[i].y2);
			ln[i].k=(double(ln[i].y2-ln[i].y1))/(ln[i].x2-ln[i].x1);
			ln[i].i=i,ln[i].w=0;
			coor[ctop++]=ln[i].x1;
			coor[ctop++]=ln[i].x2;
		}
		sort(coor,coor+ctop);
		sort(ln,ln+n,cmp);
		for(j=0,i=1; i<ctop; i++)
		{
			if(coor[i]==coor[j])	continue;
			else	coor[++j]=coor[i];
		}
		ctop=j+1;
		for(top=j=i=0; i<ctop; i++)
		{
			if(top>0)
				ln[q[top-1]].w+=coor[i]-pre;
			pre=coor[i];
			for(; ln[j].x1==coor[i]&&j<n; j++)
				add(coor[i],j);
			update(coor[i]);
		}
		/*
		for(i=0; i<n; i++)
			printf("%d ",ln[i].w);
		puts("");
		for(i=0; i<n; i++)
			printf("%d ",next[i]);
		puts("");
		for(i=0; i<n; i++)
			printf("%d ",in[i]);
		puts("");
		*/
		topo_sort(n);
		/*
		for(i=0; i<n; i++)
			printf("%d ",in[i]);
		puts("");
		*/
		for(i=0; i<n; i++)
			printf("%d\n",ret[i]);
	}
	return 0;
}
