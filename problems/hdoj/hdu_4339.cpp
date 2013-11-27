#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 1000011
using namespace std;

struct node{ int l,r,lv,rv;
	int len(){ return r-l+1; }
}no[N<<2];

char s1[N],s2[N];
int n,l1,l2;
int dat[N];

inline int L(int i){ return i<<1; }
inline int R(int i){ return i<<1|1; }

void up(int id,int l,int r)
{
	no[id].lv=no[L(id)].lv+(no[L(id)].lv==no[L(id)].len())*no[R(id)].lv;
	no[id].rv=no[R(id)].rv+(no[R(id)].rv==no[R(id)].len())*no[L(id)].rv;
}

void build(int id,int l,int r)
{
	no[id].l=l,no[id].r=r;
	if(l==r)
	{
		no[id].lv=no[id].rv=(dat[l]==0);
		return ;
	}
	int mid=(l+r)>>1;
	build(L(id),l,mid);
	build(R(id),mid+1,r);
	up(id,l,r);
}

void update(int id,int p,int x)
{
	int l=no[id].l,r=no[id].r,mid=(l+r)>>1;
	if(l==r)
	{
		no[id].lv=no[id].rv=(1-x);
		return;
	}
	if(p<=mid)
		update(L(id),p,x);
	else
		update(R(id),p,x);
	up(id,l,r);
}

int query(int id,int ll,int rr)
{
	int l=no[id].l,r=no[id].r,mid=(l+r)>>1,ret=0;
	if(l>=ll&&r<=rr)
	{
		return no[id].lv;
	}
	if(mid>=ll&&l<=rr)
	{
		ret=query(L(id),ll,rr);
		if(ret<min(mid-ll+1,min(mid-l+1,rr-l+1)))
		{
			return ret;
		}
	}
	if(mid<rr&&r>=ll)
	{
		int y;
		y=query(R(id),ll,rr);
		if(y<min(r-ll+1,min(r-mid,rr-mid)))
			return ret+y;
		ret+=y;
	}
	return ret;
}

int main()
{
	int t,ca,m;
	scanf("%d",&t);
	for(ca=1; ca<=t; ca++)
	{
		printf("Case %d:\n",ca);
		scanf("%s%s",s1,s2);
		l1=strlen(s1);
		l2=strlen(s2);
		n=max(l1,l2);
		for(int i=l1; i<n; i++)
			s1[i]='#';
		for(int i=l2; i<n; i++)
			s2[i]='$';
		s1[n]='\0',s2[n]='\0';
		for(int i=0; i<n; i++)
		{
			if(s1[i]==s2[i])
				dat[i+1]=0;
			else
				dat[i+1]=1;
		}
		build(1,1,n);
		scanf("%d",&m);
		int x,y;
		char c[10];
		for(int i=0; i<m; i++)
		{
			scanf("%d",&x);
			if(x==1)
			{
				scanf("%d%d%s",&x,&y,c);
				if(x==1)
				{
					s1[y]=c[0];
					update(1,y+1,s1[y]!=s2[y]);
				}
				else
				{
					s2[y]=c[0];
					update(1,y+1,s1[y]!=s2[y]);
				}
			}
			else
			{
				scanf("%d",&x);
				y=query(1,x+1,n);
				printf("%d\n",y);
			}
		}
	}
	return 0;
}
