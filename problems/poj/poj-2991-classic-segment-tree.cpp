#include <cstdio>
#include <cmath>
#define MOD 360
#define N 10011

inline int L(int i){ return i<<1; }
inline int R(int i){ return i<<1|1; }

double pi;
int sum[N],len[N];
double coss[400],sinn[400];

struct point{ double x,y;
	point operator+(point b){ 
		point ret;
		ret.x=x+b.x,ret.y=y+b.y;
		return ret;
	}
	point operator-(point b){
		point ret;
		ret.x=x-b.x,ret.y=y-b.y;
		return ret;
	}
};
struct node{ int l,r,c,col; point s,e;
	void turn(int x)
	{
		point xu,vec;
		vec=e-s;
		xu.x=coss[x];
		xu.y=sinn[x];
		e.x=s.x+vec.x*xu.x-vec.y*xu.y;
		e.y=s.y+vec.x*xu.y+vec.y*xu.x;
	}
	int gm(){ return (l+r)>>1; }
}no[N<<2];

void build(int id,int l,int r)
{
	no[id].l=l,no[id].r=r,no[id].c=0;
	no[id].s.x=no[id].e.x=0;
	no[id].s.y=sum[l]-len[l];
	no[id].col=0;
	no[id].e.y=sum[r];
	if(l==r)
		return;
	build(L(id),l,no[id].gm());
	build(R(id),no[id].gm()+1,r);
}

void down(int id)
{
	if(no[id].col)
	{
		int l=L(id),r=R(id);
		no[l].e=no[l].e-no[l].s+no[id].s;
		no[l].s=no[id].s;
		no[l].turn(no[id].c);
		no[l].c=(no[l].c+no[id].c)%MOD;
		no[l].col=1;

		no[r].e=no[r].e-no[r].s+no[l].e;
		no[r].s=no[l].e;
		no[r].turn(no[id].c);
		no[r].c=(no[r].c+no[id].c)%MOD;
		no[r].col=1;

		no[id].c=0;
		no[id].col=0;
	}
}

int query(int id,int p)
{
	if(no[id].l==no[id].r)
		return no[id].c;
	down(id);
	if(p<=no[id].gm())
		return query(L(id),p);
	else
		return query(R(id),p);
}

void update(int id,int p,int x)
{
	if(no[id].l==p)
	{
		no[id].c=(no[id].c+x)%MOD;
		no[id].turn(x);
		no[id].col=1;
		return;
	}
	down(id);
	int mid=no[id].gm();
	if(p<=mid)
	{
		update(L(id),p,x);
		no[R(id)].e=no[R(id)].e-no[R(id)].s+no[L(id)].e;
		no[R(id)].s=no[L(id)].e;
		update(R(id),mid+1,x);
	}
	else
		update(R(id),p,x);
	no[id].e=no[R(id)].e;
}

int main()
{
	int n,m,ca=0;
	pi=acos(-1);
	for(int i=0; i<MOD; i++)
	{
		coss[i]=cos(1.0*i*pi/180);
		sinn[i]=sin(1.0*i*pi/180);
	}
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(ca) puts("");
		else ca=1;
		sum[0]=0;
		for(int i=1; i<=n; i++)
		{
			scanf("%d",&len[i]);
			sum[i]=sum[i-1]+len[i];
		}
		build(1,1,n);
		int x,a,b;
		for(int i=0; i<m; i++)
		{
			scanf("%d%d",&x,&a);
			b=query(1,x+1)-query(1,x);
			update(1,x+1,((180+a-b)%MOD+MOD)%MOD);
			printf("%.2f %.2f\n",no[1].e.x,no[1].e.y);
		}
	}
	return 0;
}
