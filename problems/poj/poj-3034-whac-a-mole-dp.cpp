#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define MAXN 60
using std::sort;

struct vec{ int x,y,l; }v[150];
int dp[11][MAXN][MAXN],mat[11][MAXN][MAXN],top,T,n,d;

inline int max(int a,int b){ return a>b?a:b; }
inline int abs(int a){ return a>0?a:-a; }
int gcd(int a,int b){ return b==0?a:gcd(b,a%b); }
int cmp(vec a,vec b){ return a.l<b.l; }

inline int inboard(int x,int y)
{
	return x>=0&&(x<=n+2*d)&&y>=0&&(y<=n+2*d);
}

void init()
{
	int i,j; top=0;
	for(i=-5; i<=5; i++)
		for(j=-5; j<=5; j++)
			if(i*i+j*j<=25)
			{
				v[top].x=i,v[top].y=j;
				v[top++].l=ceil(sqrt(double(i*i+j*j)));
			}
	sort(v,v+top,cmp);
}


int calc(int sx,int sy,int ex,int ey,int t)
{
	int dx=ex-sx,dy=ey-sy,g,ret=0,i,j;
	g=gcd(abs(dx),abs(dy));
	if(g==0)	return mat[t][sx][sy];
	dx/=g,dy/=g;
	for(i=sx,j=sy; ; i+=dx,j+=dy)
	{
		ret+=mat[t][i][j];
		if(i==ex&&j==ey)	break;
	}
	return ret;
}

int solve()
{
	int i,j,k,u,tmp,x,y,ret=0,t;
	for(k=1; k<=T; k++)
		for(i=0; i<n+2*d; i++)
			for(j=0; j<n+2*d; j++)
			{
				for(u=0; u<top&&v[u].l<=d; u++)
				{
					x=i+v[u].x,y=j+v[u].y;
					if(!inboard(x,y))	continue;
					tmp=calc(i,j,x,y,k);

					dp[k][x][y]=max(dp[k][x][y],dp[k-1][i][j]+tmp);
				}
			}
	for(i=0; i<n+2*d; i++)
		for(j=0; j<n+2*d; j++)
			ret=max(ret,dp[T][i][j]);
	return ret;
}

int main() 
{
	int m,x,y,t,i,j;
	init();
	while(scanf("%d%d%d",&n,&d,&m)!=EOF)
	{
		if(n==0)	break;
		memset(dp,0,sizeof(dp));
		memset(mat,0,sizeof(mat));
		T=0;
		for(i=0; i<m; i++)
		{
			scanf("%d%d%d",&x,&y,&t);
			mat[t][x+d][y+d]=1;
			T=max(T,t);
		}
		printf("%d\n",solve());
	}
	return 0;
}
