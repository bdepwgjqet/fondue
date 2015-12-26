#include <cstdio>
#include <cmath>
#define eps 1e-8

const double pi=acos(-1*1.0);

struct node{ double x,y;
	node(){;}
	node(double xx,double yy){ x=xx,y=yy; }
	double len(){ return sqrt(x*x+y*y); }
}v[2];
struct seg{ node a,b;
	node getv(){ return node(a.x-b.x,a.y-b.y); }
}s[2];

int zero(double x){ return fabs(x)<eps; }

double xmult(node a,node b)
{
	return a.x*b.y-b.x*a.y;
}
double pmult(node a,node b)
{
	return a.x*b.x+a.y*b.y;
}

int pin(double x1,double x2,double x3)
{
	double y=(x1-x2)*(x1-x3);
	return zero(y)?0:y<0?1:-1;
}

int segin(double x1,double x2,double x3,double x4)
{
	int a=pin(x1,x3,x4),b=pin(x2,x3,x4);
	return (a==0&&b==0)||a>0||b>0;
}

void get(node &a,double si)
{
	double x,y;
	x=a.x*cos(si)-a.y*sin(si);
	y=a.x*sin(si)+a.y*cos(si);
	a.x=x,a.y=y;
}

int main()
{
	while(scanf("%lf%lf%lf%lf",&s[0].a.x,&s[0].a.y,&s[0].b.x,&s[0].b.y)+1)
	{
		scanf("%lf%lf%lf%lf",&s[1].a.x,&s[1].a.y,&s[1].b.x,&s[1].b.y);
		for(int i=0; i<2; i++)
			v[i]=s[i].getv();
		if(zero(xmult(v[0],v[1])))
		{
			double x=v[0].x,y=v[0].y;
			if(!zero(y))
			{
				double si=atan2(y,x);
				if(si<-pi/2)
					si+=pi;
				if(si>pi/2)
					si-=pi;
				si=-si;
				for(int i=0; i<2; i++)
				{
					get(s[i].a,si);
					get(s[i].b,si);
				}
			}
			if(segin(s[0].a.x,s[0].b.x,s[1].a.x,s[1].b.x)||segin(s[1].a.x,s[1].b.x,s[0].a.x,s[0].b.x))
				puts("-1");
			else
				puts("0");
		}
		else
		{
			node nv;
			nv.x=v[0].y,nv.y=-v[0].x;
			double ml=pmult(v[1],nv);
			ml/=v[1].len();
			ml/=nv.len();
			double bian=fabs(v[1].len()/ml);
			printf("%.12lf\n",bian*v[0].len());
		}
	}
	return 0;
}
