#include <cstdio>
#include <cstring>
#define N 512

int can[9][N],way[N],three[12],vis[3][3],dp[7001],tt,hash[6600][N];
char s[9][9];

void init()
{
	three[0]=1;
	for(int i=1; i<12; i++)
		three[i]=three[i-1]*3;
}

inline int get(char x)
{
	if(x=='B') return 1;
	if(x=='G') return 2;
	return 0;
}

int dfs1(int x,int y)
{
	if(x==0&&y==0) return 1;
	if(x<0||y<0||x>2||y>2||vis[x][y]) return 0;
	vis[x][y]=1;
	return dfs1(x+1,y)||dfs1(x-1,y)||dfs1(x,y+1)||dfs1(x,y-1);
}

int ok(int ii,int now)
{
	int st=0,dig=now/three[8-ii];
	for(int i=0; i<9; i++)
		st<<=1,st+=(now%3>0),now/=3;
	if(can[ii][st]>=0)
		return can[ii][st];
	if(dig%3==0)
		return can[ii][st]=0;
	for(int i=0; i<9; i++)
		vis[i/3][i%3]=(st&(1<<i));
	vis[ii/3][ii%3]=0;
	if(dfs1(ii/3,ii%3))
		return can[ii][st]=1;
	return can[ii][st]=0;
}

void dfs(int now,int w)
{
	if(hash[now][w]==tt) return;
	hash[now][w]=tt;
	if(now==0)
	{
		way[w]=tt;
		return;
	}
	for(int i=0; i<9; i++)
	{
		if(ok(i,now))
		{
			int x=now/three[8-i],y;
			y=x%3;
			x/=3,x*=three[9-i];
			dfs(x+now%three[8-i],(w<<1)+(y>1));
		}
	}
}

int main()
{
	int st,ca=1;
	memset(can,-1,sizeof(can));
	memset(dp,-1,sizeof(dp));
	memset(way,0,sizeof(way));
	memset(hash,0,sizeof(hash));
	tt=0;
	init();
	while(scanf("%s",s[0])!=EOF)
	{
		printf("Case %d: ",ca++);
		for(int i=1; i<=2; i++)
			scanf("%s",s[i]);
		st=0;
		for(int i=0; i<3; i++)
			for(int j=0; j<3; j++)
			{
				st*=3;
				st+=get(s[i][j]);
			}
		int ret;
		if(dp[st]==-1)
		{
			ret=0;
			tt++;
			dfs(st,0);
			for(int i=0; i<N; i++)
				if(way[i]==tt)
					ret++;
			dp[st]=ret;
		}
		else
			ret=dp[st];
		printf("%d\n",ret);
	}
	return 0;
}
