#include <cstdio>
#include <set>
#define N 200100

using namespace std;

inline int L(int i){ return i<<1; }
inline int R(int i){ return i<<1|1; }

struct segment_tree
{
	int v[N<<2];
	void update(int id,int l,int r,int p,int x)
	{
		if(l==r)
		{
			v[id]=x;
			return;
		}
		int m=(l+r)>>1;
		if(p<=m)
			update(L(id),l,m,p,x);
		else
			update(R(id),m+1,r,p,x);
		v[id]=max(v[L(id)],v[R(id)]);
	}

	int query(int id,int l,int r,int ll,int rr)
	{
		if(ll<=l&&r<=rr)
			return v[id];
		int m=(l+r)>>1,ret=0;
		if(ll<=m&&rr>=l)
			ret=max(ret,query(L(id),l,m,ll,rr));
		if(ll<=r&&rr>m)
			ret=max(ret,query(R(id),m+1,r,ll,rr));
		return ret;
	}
}pt,ht;

int xtoy[N],ytox[N];
set<int> st;
set<int> stx;
set<int>::iterator it;

void add(int x,int y)
{
	xtoy[x]=y,ytox[y]=x;
	st.insert(y);
	stx.insert(x);
	for(it=st.begin(); it!=st.end(); it++)
	{
		int yy=*it,xx=ytox[yy];
		pt.update(1,1,N-1,xx,0);
		ht.update(1,1,N-1,yy,0);
		if(yy==y)
			break;
	}
	for(;;it--)
	{
		int yy=*it,xx=ytox[yy];
		int l=pt.query(1,1,N-1,xx+1,N-1)+1;
		pt.update(1,1,N-1,xx,l);
		ht.update(1,1,N-1,yy,l);
		if(it==st.begin())
			break;
	}
}

void del(int x)
{
	int cnt=0,xx,yy;
	for(it=stx.begin(); it!=stx.end(); it++)
	{
		xx=*it,yy=xtoy[xx];
		pt.update(1,1,N-1,xx,0);
		ht.update(1,1,N-1,yy,0);
		cnt++;
		if(cnt==x) break;
	}
	int dx=xx;
	if(it!=stx.begin())
	{
		for(it--;; it--)
		{
			xx=*it,yy=xtoy[xx];
			int l=ht.query(1,1,N-1,yy+1,N-1)+1;
			pt.update(1,1,N-1,xx,l);
			ht.update(1,1,N-1,yy,l);
			if(it==stx.begin())
				break;
		}
	}
	st.erase(xtoy[dx]);
	stx.erase(dx);
}

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0; i<m; i++)
	{
		int tag;
		scanf("%d",&tag);
		if(tag==1)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			add(x,N-i+y-50);
		}
		else
		{
			int x;
			scanf("%d",&x);
			del(x);
		}
		printf("%d\n",pt.query(1,1,N-1,1,N-1));
	}
}
