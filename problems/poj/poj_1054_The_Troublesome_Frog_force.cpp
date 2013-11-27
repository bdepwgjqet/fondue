#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 5010
using std::sort;

int mat[MAXN][MAXN],ret,m,n;
struct point{ int x,y; }p[MAXN];

int cmp(point a,point b)
{
	return a.x==b.x?a.y<b.y:a.x<b.x;
}

inline int inboard(int x,int y)
{
	return 0<x&&x<=m&&y>0&&y<=n;
}

inline int cal(int x,int y,int dx,int dy)
{
	int ret=2;
	while(inboard(x,y))
	{
		if(mat[x][y]==0)	return 0;
		ret++;
		x+=dx,y+=dy;
	}
	return ret;
}

void solve(int num)
{
	int j,i,dx,dy,sx,sy,tmp;
	for(i=0; i<num; i++)
		for(j=i+1; j<num; j++)
		{
			dx=p[j].x-p[i].x;
			dy=p[j].y-p[i].y;
			if(inboard(p[i].x-dx,p[i].y-dy))
				continue;
			if(!inboard(p[i].x+(ret-1)*dx,p[i].y+(ret-1)*dy))	continue;
			tmp=cal(p[j].x+dx,p[j].y+dy,dx,dy);
			if(tmp>ret)	ret=tmp;
		}
}

int main()
{
	int pnum,i;
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		memset(mat,0,sizeof(mat));
		scanf("%d",&pnum);
		for(i=0; i<pnum; i++)
		{
			scanf("%d%d",&p[i].x,&p[i].y);
			mat[p[i].x][p[i].y]=1;
		}
		sort(p,p+pnum,cmp);
		ret=2;
		solve(pnum);
		if(ret>2)	printf("%d\n",ret);
		else	printf("0\n");
	}
	return 0;
}
