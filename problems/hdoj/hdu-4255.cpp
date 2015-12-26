#include <cstdio>
#include <cstring>
#define N 400
#define S 160001
#define M 160011
#define X 200
#define Y 200

struct node{ int x,y,cnt; }no[S],q[S];
int dir[4][2]={{-1,0},{0,-1},{1,0},{0,1}},p[M],plist[M],mat[N][N],vis[N][N],top;

inline int inboard(int x,int y){ return 0<=x&&x<N&&0<=y&&y<N; }

void fill(int x,int y,int st,int r)
{
	for(int i=0; i<4; i++)
	{
		for(int j=0; j<r; j++)
		{
			if(!(i==0&&j==0))
				x+=dir[i][0],y+=dir[i][1];
			mat[x][y]=st;
			no[st].x=x,no[st].y=y;
			st++;
		}
	}
}

void init()
{
	int x,y,i,j;
	memset(mat,-1,sizeof(mat));
	no[1].x=X;
	no[1].y=Y;
	mat[X][Y]=1;
	x=X,y=Y+1,j=2;
	for(int i=2; x<260; i+=j*4,j+=2)
	{
		fill(x,y,i,j);
		x++,y++;
	}
	top=0;
	p[0]=-1,p[1]=-1;
	for(int i=2; i<M; i++)
		p[i]=i;
	for(int i=2; i<M; i++)
	{
		if(p[i]==i)
			plist[top++]=i;
		for(int j=0; j<top&&plist[j]*i<M; j++)
		{
			p[plist[j]*i]=plist[j];
			if(i%plist[j]==0)
				break;
		}
	}
}

int solve(node st,node ed)
{
	int l,r;
	st.cnt=0;
	for(int i=140; i<260; i++)
		for(int j=140; j<260; j++)
			vis[i][j]=0;
	q[l=r=0]=st;
	vis[st.x][st.y]=1;
	for(; l<=r; )
	{
		node now=q[l++],next;
		if(now.x==ed.x&&now.y==ed.y)
			return now.cnt;
		for(int i=0; i<4; i++)
		{
			int x=now.x+dir[i][0],y=now.y+dir[i][1];
			if(!inboard(x,y))
				continue;
			if(vis[x][y])
				continue;
			if(mat[x][y]<=0)
				continue;
			next.x=x,next.y=y;
			next.cnt=now.cnt+1;
			if(next.x==ed.x&&next.y==ed.y)
				return next.cnt;
			if(p[mat[x][y]]==mat[x][y])
				continue;
			q[++r]=next;
			vis[next.x][next.y]=1;
		}
	}
	return -1;
}

int main()
{
	init();
	int a,b,ca=1,ret;
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		printf("Case %d: ",ca++);
//		printf("%d %d %d %d\n",no[a].x,no[a].y,no[b].x,no[b].y);
		ret=solve(no[a],no[b]);
		if(ret>=0)
			printf("%d\n",ret);
		else
			puts("impossible");
	}
	return 0;
}
