#include <cstdio>
#include <iostream>
#include <vector>
#define N 40100

using namespace std;
typedef long long LL;

vector<int> vec[N];

struct node{ int c,lc,rc,l,r,x;
	int gm(){ return (l+r)>>1; }
	int len(){ return r-l+1; }
}no[N<<2];

inline int L(int i){ return i<<1; }
inline int R(int i){ return i<<1|1; }
int p,q;

int cal(int l)
{
	if(l>=q)
		return l-q+1;
	return 0;
}

int get(int id)
{
	int ret=no[id].c;
	ret+=cal(no[id].lc);
	ret+=cal(no[id].rc);
	if(no[id].lc==no[id].len())
		ret-=no[id].lc-q+1;
	return ret;
}

void build(int id,int l,int r)
{
	no[id].l=l,no[id].r=r,no[id].lc=no[id].rc=no[id].len(),no[id].x=0;
	no[id].c=0;
	if(l==r) return;
	build(L(id),l,no[id].gm());
	build(R(id),no[id].gm()+1,r);
}

void up(int id)
{
	no[id].c=no[L(id)].c+no[R(id)].c;
	if(no[L(id)].lc==no[L(id)].len())
		no[id].lc=no[L(id)].lc+no[R(id)].lc;
	else
		no[id].lc=no[L(id)].lc;
	if(no[R(id)].rc==no[R(id)].len())
		no[id].rc=no[R(id)].rc+no[L(id)].rc;
	else
		no[id].rc=no[R(id)].rc;
	if(no[L(id)].lc==no[L(id)].len()||no[R(id)].rc==no[R(id)].len())
		return;
	no[id].c+=cal(no[L(id)].rc+no[R(id)].lc);
}

void update(int id,int po,int x)
{
	int l=no[id].l,r=no[id].r,m=no[id].gm();
	if(l==r)
	{
		no[id].x+=x;
		no[id].c=0;
		if(no[id].x==0)
			no[id].lc=no[id].rc=1;
		else
			no[id].lc=no[id].rc=0;
		return;
	}
	if(po<=m)
		update(L(id),po,x);
	else
		update(R(id),po,x);
	up(id);
}

int main()
{
	int T;
	scanf("%d",&T);
	for(int ca=1; ca<=T; ca++)
	{
		for(int i=0; i<N; i++)
			vec[i].clear();
		int w,h,n,x,y,a,b,c,d;
		LL ret=0;
		scanf("%d%d%d%d%d%d%d%d%d%d%d",&w,&h,&p,&q,&n,&x,&y,&a,&b,&c,&d);
		printf("Case #%d: ",ca);
		vec[x+1].push_back(y+1);
		for(int i=1; i<n; i++)
		{
			int px=x,py=y;
			x=(a*px+b*py+1)%w;
			y=(c*px+d*py+1)%h;
			vec[x+1].push_back(y+1);
		}
		build(1,1,h);
		for(int i=1; i<=p; i++)
		{
			for(int j=0; j<vec[i].size(); j++)
				update(1,vec[i][j],1);
		}
		ret+=get(1);
		for(int i=p+1; i<=w; i++)
		{
			for(int j=0; j<vec[i-p].size(); j++)
				update(1,vec[i-p][j],-1);
			for(int j=0; j<vec[i].size(); j++)
				update(1,vec[i][j],1);
			ret+=get(1);
		}
		cout<<ret<<endl;
	}
	return 0;
}
