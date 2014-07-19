#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#define N 50010
using namespace std;

struct node{ int l,r,c,lv,rv,v,i;
	int len(){ return r-l+1; }
	int pos(){ return r-rv+1; }
}no[N<<2];
struct segs{ int l,r;
	segs(int ll,int rr){ l=ll,r=rr; }
};
vector<segs> vec;

char s[100];

inline int L(int i){ return i<<1; }
inline int R(int i){ return i<<1|1; }

void build(int id,int l,int r)
{
	no[id].l=l,no[id].r=r,no[id].c=-1;
	no[id].lv=no[id].rv=no[id].v=no[id].len();
	no[id].i=l;
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
	no[id].v=max(max(no[L(id)].v,no[R(id)].v),no[L(id)].rv+no[R(id)].lv);
	if(no[id].v==no[L(id)].v)
		no[id].i=no[L(id)].i;
	else if(no[id].v==no[L(id)].rv+no[R(id)].lv)
		no[id].i=no[L(id)].pos();
	else
		no[id].i=no[R(id)].i;
}

void down(int id,int l,int r)
{
	if(no[id].c>=0)
	{
		no[L(id)].c=no[id].c;
		no[R(id)].c=no[id].c;
		no[L(id)].v=no[L(id)].lv=no[L(id)].rv=no[L(id)].len()*(1-no[id].c);
		no[R(id)].v=no[R(id)].lv=no[R(id)].rv=no[R(id)].len()*(1-no[id].c);
		no[L(id)].i=no[L(id)].l;
		no[R(id)].i=no[R(id)].l;
		no[id].c=-1;
	}
}

void update(int id,int ll,int rr,int x)
{
	int l=no[id].l,r=no[id].r,mid=(l+r)>>1;
	if(l>=ll&&r<=rr)
	{
		no[id].c=x;
		no[id].v=no[id].lv=no[id].rv=no[id].len()*(1-x);
		no[id].i=l;
		return ;
	}
	down(id,l,r);
	if(mid>=ll&&l<=rr)
		update(L(id),ll,rr,x);
	if(mid<rr&&r>=ll)
		update(R(id),ll,rr,x);
	up(id,l,r);
}

int query(int id,int x)
{
	if(no[id].v<x)
		return 0;
	if(no[id].c==0)
		return no[id].i;
	if(no[id].l==no[id].r)
		return no[id].i;
	if(no[L(id)].v>=x)
		return query(L(id),x);
	if(no[L(id)].rv+no[R(id)].lv>=x)
		return no[L(id)].pos();
	if(no[R(id)].v>=x)
		return query(R(id),x);
	return no[id].i;
}

int get_id(int x)
{
	int l=0,r=vec.size()-1,mid;
	for(; l<=r;)
	{
		mid=(l+r)>>1;
		if(vec[mid].l<=x)
			l=mid+1;
		else
			r=mid-1;
	}
	return l;
}

int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		build(1,1,n);
		vec.clear();
		int x,id;
		for(int i=0; i<m; i++)
		{
			scanf("%s",s);
			if(strcmp(s,"Reset")==0)
			{
				update(1,1,n,0);
				//build(1,1,n);
				puts("Reset Now");
				vec.clear();
			}
			else if(strcmp(s,"New")==0)
			{
				scanf("%d",&x);
				id=query(1,x);
				if(id==0)
					puts("Reject New");
				else
				{
					printf("New at %d\n",id);
					update(1,id,id+x-1,1);
					int ii=get_id(id);
					vec.insert(ii+vec.begin(),segs(id,id+x-1));
				}
			}
			else if(strcmp(s,"Free")==0)
			{
				scanf("%d",&x);
				id=get_id(x)-1;
				if(id==-1||vec[id].r<x)
				{
					puts("Reject Free");
					continue;
				}
				update(1,vec[id].l,vec[id].r,0);
				printf("Free from %d to %d\n",vec[id].l,vec[id].r);
				vec.erase(vec.begin()+id,vec.begin()+id+1);
			}
			else
			{
				scanf("%d",&x);
				if(x>vec.size())
				{
					puts("Reject Get");
					continue;
				}
				printf("Get at %d\n",vec[x-1].l);
			}
		}
		puts("");
	}
	return 0;
}
