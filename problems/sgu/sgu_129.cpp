#include <cstdio>
#include <cmath>
#include <algorithm>
#define inf 40000
#define eps 1e-7
#define N 411

using namespace std;

struct node{ double x,y; }no[N],st,ed,jiao[N];

double xmult(node a,node b,node c)
{
	return (a.x-c.x)*(b.y-c.y)-(a.y-c.y)*(b.x-c.x);
}

double xmult(node a,node b,node c,node d)
{
	return (a.x-b.x)*(c.y-d.y)-(a.y-b.y)*(c.x-d.x);
}

int cmp(node a,node b)
{
	return xmult(a,b,no[0])>0;
}

int get(double x){ return fabs(x)<eps?1:x>0?2:0; }

int inboard(node a,int n)
{
	int tag[3]={0};
	for(int i=0; i<n; i++)
		tag[get(xmult(no[i],no[i+1],a))]=1;
	if(tag[1]) return 0;
	if(tag[0]&&tag[2]) return 0;
	return 1;
}

double sq(double x){ return x*x; }

double len(node a,node b)
{
	return sqrt(1.0*(sq(a.x-b.x)+sq(a.y-b.y)));
}

int inter(node &ret,int i)
{
	double up,dn,t,x,y;
	up=1.0*xmult(no[i],no[i+1],no[i],st);
	dn=1.0*xmult(st,ed,no[i],no[i+1]);
	t=up/dn;
	x=st.x+(ed.x-st.x)*t;
	y=st.y+(ed.y-st.y)*t;
	if(fabs(x-no[i].x)<eps&&fabs(y-no[i].y)<eps)
		return 0;
	if((x-st.x)*(x-ed.x)<eps&&(y-st.y)*(y-ed.y)<eps&&(x-no[i].x)*(x-no[i+1].x)<eps&&(y-no[i].y)*(y-no[i+1].y)<eps)
	{
			ret.x=x,ret.y=y;
			if(fabs(xmult(ret,no[i],no[i+1]))<eps)
				return 1;
			return 0;
	}
	return 0;
}

double gao(int n)
{
	int t1,t2;
	t1=inboard(st,n);
	t2=inboard(ed,n);

	int top=0;
	if(t1==0&&t2==0)
	{
		for(int i=0; i<n; i++)
		{
			if(fabs(xmult(st,ed,no[i],no[i+1]))<eps)
				continue;
			if(inter(jiao[top],i))
				top++;
		}
		if(top==2)
			return len(jiao[0],jiao[1]);
		return 0;
	}
	else if(t1&&t2)
		return len(st,ed);

	if(t1==0)
	{
		swap(t1,t2);
		swap(st,ed);
	}
	jiao[0]=st;
	for(int i=0; i<n; i++)
	{
		if(fabs(xmult(st,ed,no[i],no[i+1]))<eps)
			continue;
		if(inter(jiao[0],i))
			break;
	}
	return len(st,jiao[0]);
}

int main()
{
	int n;
	while(scanf("%d",&n)+1)
	{
		int x=inf,y=inf,id=-1;
		for(int i=0; i<n; i++)
		{
			scanf("%lf%lf",&no[i].x,&no[i].y);
			if(no[i].x<x||(no[i].x==x&&no[i].y<y))
				x=no[i].x,y=no[i].y,id=i;
		}
		swap(no[0],no[id]);
		sort(no+1,no+n,cmp);
		no[n]=no[0];
		int m;
		scanf("%d",&m);
		for(int i=0; i<m; i++)
		{
			scanf("%lf%lf%lf%lf",&st.x,&st.y,&ed.x,&ed.y);
			printf("%.10f\n",gao(n));
		}
	}
	return 0;
}
