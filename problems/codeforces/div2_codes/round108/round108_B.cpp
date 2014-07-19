#include <cstdio>
typedef long long LL;
int n,m;

inline int inboard(int x,int y)
{
	return 1<=x&&x<=n&&1<=y&&y<=m;
}

inline int min(int a,int b){ return a<b?a:b; }
inline int abs(int a){ return a>0?a:-a; }

LL cal(int &x,int &y,int dx,int dy)
{
	LL mul=0; int absx,absy,xx,yy;
	absx=abs(dx); absy=abs(dy);
	if(dx>=0&&dy>=0)
		xx=n-x,yy=m-y;
	else if(dx>0)
		xx=n-x,yy=y-1;
	else if(dy>0)
		xx=x-1,yy=m-y;
	else
		xx=x-1,yy=y-1;

	if(dx==0)
		mul=yy/absy;
	else if(dy==0)
		mul=xx/absx;
	else
		mul=min(xx/absx,yy/absy);
	x=x+mul*dx,y=y+mul*dy;
	return mul;
}

int main()
{
	int x,y,k,i,dx,dy; LL ret=0;
	scanf("%d%d",&n,&m);
	scanf("%d%d",&x,&y);
	scanf("%d",&k);
	for(i=0; i<k; i++)
	{
		scanf("%d%d",&dx,&dy);
		ret+=cal(x,y,dx,dy);
	}
	printf("%I64d\n",ret);
	return 0;
}
