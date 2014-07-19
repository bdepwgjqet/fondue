/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  07/09/2012 10:11:46 AM
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

inline int L(int i){ return i<<1; }
inline int R(int i){ return (i<<1)|1; }
inline int B(int i){ return 1<<i; }
inline int low_bit(int x){ return x&(-x); }

set<string> st;
map<string,int> mp;
string sa,sb;
struct edge{ int f,t,l,n; }e[S],E[S],P[S];
int n,top,list[N],pk,et,lim,v[S],tp;

void insert(int f,int t,int l)
{
	e[top].f=f,e[top].t=t,e[top].l=l;
	e[top].n=list[f],list[f]=top++;
}

void del(int f,int t)
{
	int i=list[f],nx;
	if(e[i].n==-1)
	{
		list[f]=-1;
		return;
	}
	if(e[i].t==t)
	{
		list[f]=e[i].n;
		return;
	}
	for(; e[i].n!=-1; i=e[i].n)
	{
		nx=e[i].n;
		if(e[nx].t==t)
		{
			e[i].n=e[nx].n;
			break;
		}
	}
}

struct ufind
{
	int p[N],t;
	void init()
	{ 
		for(int i=0; i<N; i++)
			p[i]=i;
	}
	void run(int &x){ for(; p[t=x]!=x; x=p[x],p[t]=p[x]); }
	int isfriend(int i,int j)
	{
		run(i); run(j);
		return i==j;
	}
	void setfriend(int i,int j)
	{
		run(i); run(j);
		p[i]=p[j];
	}
}uf;

void dfs(int now,int pre,int t,int &a,int &b,int &l,int &tag)
{
	if(now==t)
	{
		tag=1;
		return;
	}
	for(int i=list[now]; i!=-1; i=e[i].n)
	{
		int to=e[i].t;
		if(to==pre)
			continue;
		dfs(to,now,t,a,b,l,tag);
		if(tag)
		{
			if(e[i].l>l)
			{
				l=e[i].l;
				a=e[i].f,b=e[i].t;
			}
			return;
		}
	}
}

int cmp(edge a,edge b){ return a.l<b.l; }

int main()
{
	int l,a,b,ret;
	while(scanf("%d",&n)!=EOF)
	{
		memset(v,0,sizeof(v));
		uf.init();
		st.clear();
		mp.clear();
		tp=ret=et=top=0;
		for(int i=0; i<N; i++)
			list[i]=-1;
		for(int i=0; i<n; i++)
		{
			cin>>sa>>sb>>l;
			if(st.count(sa)==0)
			{
				st.insert(sa);
				a=tp;
				mp[sa]=tp++;
			}
			else
				a=mp[sa];
			if(st.count(sb)==0)
			{
				st.insert(sb);
				b=tp;
				mp[sb]=tp++;
			}
			else
				b=mp[sb];
			E[i].f=a,E[i].t=b,E[i].l=l;
		}
		pk=mp[string("Park")];
		sort(E,E+n,cmp);
		for(int i=0; i<n; i++)
		{
			a=E[i].f,b=E[i].t;
			if(a==pk||b==pk)
			{
				P[et].f=pk;
				if(a==pk)
					P[et].t=b;
				else
					P[et].t=a;
				P[et++].l=E[i].l;
				continue;
			}
			if(uf.isfriend(a,b)) continue;
			uf.setfriend(a,b);
			insert(a,b,E[i].l);
			insert(b,a,E[i].l);
			ret+=E[i].l;
		}
		cin>>lim;
		sort(P,P+et,cmp);
		int cnt=0;
		for(int i=0; i<et; i++)
		{
			a=P[i].f,b=P[i].t;
			if(uf.isfriend(a,b)) continue;
			uf.setfriend(a,b);
			insert(a,b,P[i].l);
			insert(b,a,P[i].l);
			ret+=P[i].l;
			v[i]=1;
			cnt++;
		}
		int mi=inf,ll,aa,bb,id,tag;
		while(cnt<lim)
		{
			mi=inf;
			for(int i=0; i<et; i++)
			{
				if(v[i]) continue;
				tag=0;
				ll=P[i].l;
				dfs(P[i].t,P[i].f,P[i].f,a,b,ll,tag);
				if(mi>P[i].l-ll)
				{
					mi=P[i].l-ll;
					aa=a,bb=b;
					id=i;
				}
			}
			if(mi>=0)
				break;
			ret+=mi;
			del(aa,bb);
			del(bb,aa);
			insert(P[id].f,P[id].t,P[id].l);
			insert(P[id].t,P[id].f,P[id].l);
			v[id]=1;
			cnt++;
		}
		printf("Total miles driven: %d\n",ret);
	}
	return 0;
}
