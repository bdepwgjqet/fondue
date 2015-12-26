#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#define N 100
#define inf 0x3fffffff

const int X=1<<7;
using namespace std;

inline int B(int i){ return 1<<i; }

int ok[X],m,n,dp[2][X][X],nid,ST,st[N];
char s[N];

int isok(int x)
{
	for(int i=0; i+1<n; i++)
		if((B(i)&x)==0&&(B(i+1)&x)==0)
			return 0;
	return 1;
}

void gao(int l,int x,int y,int z,int c,int iy)
{
	if(l==n)
	{
		dp[nid][y][z]=min(dp[nid][y][z],dp[nid^1][x][iy]+c);
		return;
	}
	int xx=x&B(l),yy=y&B(l),zz=z&B(l);
	if(yy)
		gao(l+1,x,y,z,c,iy);
	else
	{
		if(xx&&(l==0||(B(l-1)&y)))
		{
			gao(l+1,x,y,z,c,iy);
		}
		if(zz==0)
			gao(l+1,x,y+B(l),z+B(l),c+1,iy);
		if(l<n-1&&(B(l+1)&y)==0)
			gao(l+2,x,y+B(l)+B(l+1),z,c+1,iy);
	}
}

int main()
{
	scanf("%d%d",&m,&n);
	for(int i=0; i<m; i++)
	{
		scanf("%s",s);
		st[i]=0;
		for(int j=0; s[j]; j++)
			if(s[j]=='*')
				st[i]|=B(j);
	}
	ST=B(n)-1;
	st[m]=ST;
	for(int i=0; i<=ST; i++)
		ok[i]=isok(i);

	for(int i=0; i<2; i++)
		for(int u=0; u<=ST; u++)
			for(int v=0; v<=ST; v++)
				dp[i][u][v]=inf;
	dp[0][ST][st[0]]=0;
	nid=1;

	for(int i=0; i<m; i++,nid^=1)
	{
		for(int u=0; u<=ST; u++)
			for(int v=0; v<=ST; v++)
				dp[nid][u][v]=inf;
		for(int u=0; u<=ST; u++)
			if(ok[u])
				for(int v=0; v<=ST; v++)
					if((v&st[i])==st[i])
						gao(0,u,v,st[i+1],0,v);
	}
	int ret=inf;
	for(int i=0; i<=ST; i++)
		if(ok[i])
			ret=min(ret,dp[nid^1][i][ST]);
	printf("%d\n",ret);
	return 0;
}
