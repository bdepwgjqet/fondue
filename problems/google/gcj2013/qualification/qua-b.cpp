#include <cstdio>
#include <algorithm>
#define N 111

using namespace std;

int mat[N][N],tag[N][N];
struct node{ int x,y,h; }no[10011];
int m,n,top;

int cmp(node a,node b){ return a.h<b.h; }

int x_can(int x,int h)
{
	for(int i=1; i<=n; i++)
	{
		if(tag[x][i])
			continue;
		if(mat[x][i]>h)
			return 0;
	}
	for(int i=1; i<=n; i++)
		tag[x][i]=1;
	return 1;
}

int y_can(int y,int h)
{
	for(int i=1; i<=m; i++)
	{
		if(tag[i][y])
			continue;
		if(mat[i][y]>h)
			return 0;
	}
	for(int i=1; i<=m; i++)
		tag[i][y]=1;
	return 1;
}

int can(int x,int y)
{
	if(x_can(x,mat[x][y]))
		return 1;
	if(y_can(y,mat[x][y]))
		return 1;
	return 0;
}

int ok()
{
	for(int i=0; i<top; i++)
	{
		int x=no[i].x,y=no[i].y;
		if(tag[x][y])
			continue;
		if(!can(x,y))
			return 0;
	}
	return 1;
}

int main()
{
	int t;
	scanf("%d",&t);
	for(int ca=1; ca<=t; ca++)
	{
		printf("Case #%d: ",ca);
		scanf("%d%d",&m,&n);
		top=0;
		for(int i=1; i<=m; i++)
			for(int j=1; j<=n; j++)
			{
				scanf("%d",&mat[i][j]);
				no[top].x=i,no[top].y=j;
				no[top++].h=mat[i][j];
				tag[i][j]=0;
			}
		sort(no,no+top,cmp);
		if(ok())
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
