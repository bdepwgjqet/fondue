#include <cstdio>
#include <cstring>
#define X 500000
#define N 500011

struct node{ int l,r,c,i;
	int gm(){ return (l+r)>>1; }
}no[N<<2];
int vis[N],q[N],top;

inline int L(int i){ return i<<1; }
inline int R(int i){ return i<<1|1; }

void build(int id,int l,int r)
{
	no[id].l=l,no[id].r=r,no[id].c=0;
	if(l==r) return;
	build(L(id),l,no[id].gm());
	build(R(id),no[id].gm()+1,r);
}

void update(int id,int p)
{
	if(no[id].l==no[id].r)
	{
		no[id].c=1;
		no[id].i=no[id].l;
		return;
	}
	int mid=no[id].gm();
	if(p<=mid)
		update(L(id),p);
	else
		update(R(id),p);
	no[id].c=no[L(id)].c|no[R(id)].c;
	if(no[id].c)
		no[id].i=no[L(id)].c?no[L(id)].i:no[R(id)].i;
}

int query(int id,int ll,int rr)
{
	if(no[id].c==0)
		return 0;
	int l=no[id].l,r=no[id].r,mid=(l+r)>>1,ret=0;
	if(l>=ll&&r<=rr)
		return no[id].c*no[id].i;
	if(mid>=ll&&l<=rr)
	{
		ret=query(L(id),ll,rr);
		if(ret)
			return ret;
	}
	if(mid<rr&&r>=ll)
		return query(R(id),ll,rr);
	return 0;
}

int main()
{
	int n,ca=1;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			break;
		printf("Case %d:\n",ca++);
		top=0;
		memset(vis,0,sizeof(vis));
		char s[10];
		build(1,1,X);
		int x;
		for(int i=0; i<n; i++)
		{
			scanf("%s%d",&s,&x);
			if(s[0]=='B')
			{
				if(vis[x])
					continue;
				q[top++]=x;
				vis[x]=top;
				update(1,x);
			}
			else
			{
				if(x<=2000)
				{
					int md,ret=N,id;
					for(int i=top-1; i>=0; i--)
					{
						md=q[i]%x;
						if(md<ret)
							ret=md,id=i;
						if(ret==0)
							break;
					}
					if(ret>=N)
						puts("-1");
					else
						printf("%d\n",id+1);
				}
				else
				{
					int j,ret=N,now,id;
					for(int i=0; i<=X; i+=x)
					{
						j=i+x-1;
						if(j>X)
							j=X;
						now=query(1,i==0?1:i,j);
						if(now==0)
							continue;
						if((now%x)<ret)
							ret=now%x,id=vis[now];
						else if((now%x)==ret)
							if(vis[now]>id)
								ret=now%x,id=vis[now];
					}
					if(ret>=N)
						puts("-1");
					else
						printf("%d\n",id);
				}
			}
		}
		puts("");
	}
	return 0;
}
