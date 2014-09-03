#include <cstdio>

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int in(int x,int a,int b)
{
	return (x-a)*(x-b)<=0;
}

int main()
{
	int x,y;
	scanf("%d%d",&x,&y);
	int nx=0,ny=0,d=1,ret=0;
	for(int i=0;; i++)
	{
		int tx=nx+dx[i%4]*d,ty=ny+dy[i%4]*d;
		if(nx==tx)
		{
			if(x==nx&&in(y,ny,ty))
				break;
		}
		else
		{
			if(y==ny&&in(x,nx,tx))
				break;
		}
		if(i&1) d++;
		ret++;
		nx=tx,ny=ty;
	}
	printf("%d\n",ret);
	return 0;
}
