#include <cstdio>
#include <cstring>
#include <vector>
#define N 222

using namespace std;

int mat[N][N],vis[N][N];
vector<int> que;
vector<int> ans;

int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

int inboard(int x,int y,int m,int n)
{
	return 0<=x&&x<m&&0<=y&&y<n; 
}

int ok(int m,int n)
{
	int cnt=0,ttl=m*n,l,r;
	que.clear();
	ans.clear();
	memset(vis,0,sizeof(vis));
	for(; cnt<ttl;)
	{
		for(int i=0; i<m; i++)
			for(int j=0; j<n; j++)
			{
				if(vis[i][j]) continue;
				if(mat[i][j]==1)
					que.push_back(i*N+j);
				else if(mat[i][j]==0)
					return 0;
			}
		if(que.size()==0)
			return 0;
		for(int i=0; i<que.size(); i++)
		{
			int x=que[i]/N,y=que[i]%N;
			for(int i=0; i<4; i++)
			{
				int xx=x+dir[i][0],yy=y+dir[i][1];
				if(!inboard(xx,yy,m,n))
					continue;
				if(vis[xx][yy])
					continue;
				mat[xx][yy]--;
				if(mat[xx][yy]<=0)
					return 0;
			}
			ans.push_back(x*N+y);
			cnt++;
			vis[x][y]=1;
		}
		for(; que.size()>0;)
			que.pop_back();
	}
	return 1;
}

int main()
{
	int n,m;
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		for(int i=0; i<m; i++)
			for(int j=0; j<n; j++)
				scanf("%d",&mat[i][j]);
		if(ok(m,n))
		{
			for(int i=ans.size()-1; i>=0; i--)
			{
				printf("%d %d\n",ans[i]/N+1,ans[i]%N+1);
			}
		}
		else
			puts("No solution");
	}
	return 0;
}
