#include <cstdio>
#include <cstring>
#define N 50010

struct node{ int l,r,lv,rv,c; 
	int len(){ return r-l+1; }
	int lpos(){ return l+lv-1; }
	int rpos(){ return r-rv+1; }
}no[N<<3];

inline int L(int i){ return i<<1; }
inline int R(int i){ return i<<1|1; }

void build(int id,int l,int r)
{
	no[id].l=l,no[id].r=r,no[id].c=-1,no[id].lv=no[id].rv=no[id].len();
	if(l==r)
		return;
	int mid=(l+r)>>1;
	build(L(id),l,mid);
	build(R(id),mid+1,r);
}

void up(int id,int l,int r)
{
	no[id].lv=no[L(id)].lv+(no[L(id)].lv==no[L(id)].len())*no[R(id)].lv;
	no[id].rv=no[R(id)].rv+(no[R(id)].rv==no[R(id)].len())*no[L(id)].rv;
}

void down(int id,int l,int r)
{
	if(no[id].c>=0)
	{
		no[L(id)].c=no[id].c;
		no[R(id)].c=no[id].c;
		no[L(id)].lv=no[L(id)].rv=(1-no[id].c)*no[L(id)].len();
		no[R(id)].lv=no[R(id)].rv=(1-no[id].c)*no[R(id)].len();
		no[id].c=-1;
	}
}

void update(int id,int p,int x)
{
	int l=no[id].l,r=no[id].r,mid=(l+r)>>1;
	if(l==r)
	{
		no[id].c=x;
		no[id].lv=no[id].rv=1-x;
		return;
	}
	down(id,l,r);
	if(p<=mid)
		update(L(id),p,x);
	else
		update(R(id),p,x);
	//printf("%d %d %d %d %d %d\n",id,l,r,no[id].lv,no[id].rv,p);
	up(id,l,r);
	//printf("%d %d %d %d %d %d\n",id,l,r,no[id].lv,no[id].rv,p);
}

int query(int id,int p)
{
	if(p>=no[L(id)].rpos()&&p<=no[R(id)].lpos())
		return no[L(id)].rv+no[R(id)].lv;
	int l=no[id].l,r=no[id].r,mid=(l+r)>>1;
	if(l==r)
	{
		if(no[id].c==1)
			return 0;
		else
			return 1;
	}
	if(p<=mid)
		return query(L(id),p);
	else
		return query(R(id),p);
}

char s[10];
int st[N],top;

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	build(1,1,n);
	top=-1;
	int x;
	for(int i=0; i<m; i++)
	{
		scanf("%s",s);
		if(s[0]=='D')
		{
			scanf("%d",&x);
			update(1,x,1);
			st[++top]=x;
		}
		else if(s[0]=='Q')
		{
			scanf("%d",&x);
			printf("%d\n",query(1,x));
		}
		else
		{
			if(top<0)
				continue;
			x=st[top--];
			update(1,x,0);
		}
	}
	return 0;
}
