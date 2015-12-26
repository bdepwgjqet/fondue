#include <cstdio>
#include <vector>
#include <algorithm>
#define inf 0x7fffffff
#define N 100010

typedef long long LL;
using namespace std;

struct node{ LL x,h; }no[N];

int cmp(node a,node b){ return a.x==b.x?a.h<b.h:a.x<b.x; }
int dl[N],dr[N],ddl[N],ddr[N];
int val[2]={ N , 0 };
int dp[N];

struct sta{ int x,i; };
vector<sta> st;

struct seg
{
	struct node{ int l,r,x[2];
		int gm(){ return (l+r)>>1; }
	}no[N<<2];

	inline int L(int i){ return i<<1; }
	inline int R(int i){ return i<<1|1; }

	void init(int id,int l,int r)
	{
		no[id].x[0]=0,no[id].l=l,no[id].r=r,no[id].x[1]=0;
		if(l==r) return;
		int m=no[id].gm();
		init(L(id),l,m);
		init(R(id),m+1,r);
	}

	void update(int id,int p,int x)
	{
		int m=no[id].gm();
		if(no[id].l==no[id].r)
		{
			no[id].x[0]=no[id].x[1]=x;
			return;
		}
		if(m>=p)
			update(L(id),p,x);
		else
			update(R(id),p,x);
		no[id].x[0]=min(no[L(id)].x[0],no[R(id)].x[0]);
		no[id].x[1]=max(no[L(id)].x[1],no[R(id)].x[1]);
	}

	int mycmp(int a,int b,int tag)
	{
		if(tag==0)
			return min(a,b);
		return max(a,b);
	}

	int query(int id,int ll,int rr,int tag)
	{
		int l=no[id].l,r=no[id].r,m=no[id].gm();
		if(ll<=l&&rr>=r)
			return no[id].x[tag];
		int ret=val[tag];
		if(rr>=l&&ll<=m)
			ret=mycmp(ret,query(L(id),ll,rr,tag),tag);
		if(ll<=r&&rr>m)
			ret=mycmp(ret,query(R(id),ll,rr,tag),tag);
		return ret;
	}
}sg;

int get(int now,int l,int r,int tag)
{
	LL x=no[now].x+tag*no[now].h;
	int mid;
	for(; l<=r;)
	{
		mid=(l+r)>>1;
		if(tag==-1)
		{
			if(no[mid].x>=x)
				r=mid-1;
			else
				l=mid+1;
		}
		else
		{
			if(no[mid].x<=x)
				l=mid+1;
			else
				r=mid-1;
		}
	}
	if(tag==-1)
		return l;
	return r;
}

int getid(int x)
{
	int l=0,r=st.size()-1,mid;
	for(; l<=r;)
	{
		mid=(l+r)>>1;
		if(st[mid].x>=x)
			r=mid-1;
		else
			l=mid+1;
	}
	return st[l].i;
}

int main()
{
	int n;
	while(scanf("%d",&n)+1)
	{
		for(int i=1; i<=n; i++)
			scanf("%lld%lld",&no[i].x,&no[i].h);
		sort(no+1,no+n+1,cmp);
		dl[1]=1;
		for(int i=2; i<=n; i++)
			dl[i]=get(i,1,i-1,-1);
		dr[n]=n;
		for(int i=n-1; i>=1; i--)
			dr[i]=get(i,i+1,n,1);

		sg.init(1,1,n);
		ddl[1]=1;
		sg.update(1,1,1);
		for(int i=2; i<=n; i++)
		{
			int l=dl[i],r=i-1;
			if(l>r)
				ddl[i]=i;
			else
				ddl[i]=sg.query(1,l,r,0);
			sg.update(1,i,ddl[i]);
		}
		sg.init(1,1,n);
		ddr[n]=n;
		sg.update(1,n,n);
		for(int i=n-1; i>=1; i--)
		{
			int r=dr[i],l=i+1;
			if(l>r)
				ddr[i]=i;
			else
				ddr[i]=sg.query(1,l,r,1);
			sg.update(1,i,ddr[i]);
		}

		dp[0]=0;
		st.clear();
		sta tmp;
		for(int i=1; i<=n; i++)
		{
			dp[i]=dp[ddl[i]-1]+1;
			int xx=-1,sz=st.size();
			if(sz>0)
			{
				xx=max(xx,st[sz-1].x);
				if(xx>=i)
				{
					int id=getid(i);
					dp[i]=min(dp[i],dp[id-1]+1);
				}
				else
					st.clear();
			}
			if(ddr[i]>=xx)
			{
				tmp.x=ddr[i];
				tmp.i=i;
				for(; st.size()>0; )
				{
					if(dp[tmp.i-1]<=dp[st[st.size()-1].i-1])
						st.pop_back();
					else break;
				}
				st.push_back(tmp);
			}
		}
		printf("%d\n",dp[n]);
	}
	return 0;
}
