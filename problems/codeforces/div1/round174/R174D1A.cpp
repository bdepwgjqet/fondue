#include <cstdio>
#define X 1<<18

typedef long long LL;

struct node{ LL x,a; int l,r; 
	int gl(){ return r-l+1; }
}no[X<<2];

inline int L(int i){ return i<<1; }
inline int R(int i){ return i<<1|1; }

void down(int id)
{
	if(no[id].a!=0)
	{
		no[L(id)].a+=no[id].a;
		no[R(id)].a+=no[id].a;
		no[id].a=0;
	}
}

void init(int id,int l,int r)
{
	no[id].l=l,no[id].r=r,no[id].a=no[id].x=0;
	if(l==r) return;
	int m=(l+r)>>1;
	init(L(id),l,m);
	init(R(id),m+1,r);
}

void up(int id)
{
	no[id].x=no[L(id)].x+no[R(id)].x+no[L(id)].a*no[L(id)].gl()+no[R(id)].a*no[R(id)].gl();
}

void add(int id,int l,int r,int ll,int rr,int x)
{
	if(ll<=l&&rr>=r)
	{
		no[id].a+=x;
		return;
	}
	int m=(l+r)>>1;
	down(id);
	if(ll<=m&&rr>=l)
		add(L(id),l,m,ll,rr,x);
	if(ll<=r&&rr>=m+1)
		add(R(id),m+1,r,ll,rr,x);
	up(id);
}

LL cal(int id,int l,int r,int ll,int rr)
{
	if(ll<=l&&rr>=r)
		return no[id].x+no[id].a*(r-l+1);
	int m=(l+r)>>1;
	down(id);
	LL ret=0;
	if(ll<=m&&rr>=l)
		ret+=cal(L(id),l,m,ll,rr);
	if(ll<=r&&rr>=m+1)
		ret+=cal(R(id),m+1,r,ll,rr);
	up(id);
	return ret;
}

void update(int id,int l,int r,int p,int x)
{
	if(l==r)
	{
		no[id].a=0,no[id].x=x;
		return;
	}
	int m=(l+r)>>1;
	down(id);
	if(p>m)
		update(R(id),m+1,r,p,x);
	else
		update(L(id),l,m,p,x);
	up(id);
}

int main()
{
	int n,cnt=1;
	init(1,1,X);
	scanf("%d",&n);
	for(int i=0; i<n; i++)
	{
		int t;
		scanf("%d",&t);
		if(t==1)
		{
			int a,x;
			scanf("%d%d",&a,&x);
			add(1,1,X,1,a,x);
		}
		else if(t==2)
		{
			cnt++;
			int x;
			scanf("%d",&x);
			update(1,1,X,cnt,x);
		}
		else
		{
			if(cnt>=2)
			{
				update(1,1,X,cnt,0);
				cnt--;
			}
		}
		LL sum=cal(1,1,X,1,cnt);
		printf("%.12lf\n",1.0*sum/cnt);
	}
	return 0;
}
