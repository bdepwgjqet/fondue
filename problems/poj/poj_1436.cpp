#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 8011
#define S 200001
using namespace std;

struct edge{ int f,t,n; }e[S];
struct node{ int l,r,c; }no[N<<3]; 
struct segs{ int x,l,r; }seg[N];

int cmp(segs a,segs b){ return a.x>b.x; }
inline int L(int i){ return i<<1; }
inline int R(int i){ return i<<1|1; }
int top,list[N],con[N];

void insert(int f,int t)
{
	e[top].f=f,e[top].t=t;
	e[top].n=list[f],list[f]=top++;
}

void build(int id,int l,int r)
{
	no[id].l=l,no[id].r=r,no[id].c=-1;
	if(l==r)
		return;
	int mid=(l+r)>>1;
	build(L(id),l,mid);
	build(R(id),mid+1,r);
}

void down(int id,int l,int r)
{
	if(no[id].c>=0)
	{
		no[L(id)].c=no[id].c;
		no[R(id)].c=no[id].c;
		no[id].c=-1;
	}
}

void update(int id,int ll,int rr,int x)
{
	int l=no[id].l,r=no[id].r,mid=(l+r)>>1;
	if(l>=ll&&r<=rr)
	{
		no[id].c=x;
		return ;
	}
	down(id,l,r);
	if(mid>=ll&&l<=rr)
		update(L(id),ll,rr,x);
	if(mid<rr&&r>=ll)
		update(R(id),ll,rr,x);
}

void query(int id,int ll,int rr,int x)
{
	int l=no[id].l,r=no[id].r,mid=(l+r)>>1;
	if(no[id].c>=0)
	{
		if(con[no[id].c]!=x)
		{
			insert(x,no[id].c);
			con[no[id].c]=x;
		}
		return ;
	}
	if(l==r)
		return;
	if(mid>=ll&&l<=rr)
		query(L(id),ll,rr,x);
	if(mid<rr&&r>=ll)
		query(R(id),ll,rr,x);
}

int main()
{
	int t,n,mx;
	scanf("%d",&t);
	for(; t--;)
	{
		mx=0;
		top=0;
		memset(list,-1,sizeof(list));
		memset(con,-1,sizeof(con));
		scanf("%d",&n);
		for(int i=0; i<n; i++)
		{
			scanf("%d%d%d",&seg[i].l,&seg[i].r,&seg[i].x);
			seg[i].l++,seg[i].r++;
			seg[i].l<<=1,seg[i].r<<=1;
			mx=max(mx,seg[i].r);
		}
		sort(seg,seg+n,cmp);
		build(1,1,mx);
		for(int i=0; i<n; i++)
		{
			query(1,seg[i].l,seg[i].r,i);
			update(1,seg[i].l,seg[i].r,i);
		}
		int ret=0;
		for(int u=0; u<n; u++)
		{
			for(int j=list[u]; j!=-1; j=e[j].n)
			{
				int v=e[j].t;
				for(int k=list[v]; k!=-1; k=e[k].n)
					for(int i=list[u]; i!=-1; i=e[i].n)
						if(e[k].t==e[i].t)
							ret++;
			}
		}
		printf("%d\n",ret);
	}
	return 0;
}
