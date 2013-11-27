#include <cstdio>
#include <cstring>
#include <vector>
#define inf 0x3fffffff
#define S 100001
#define N 111
#define pii pair<int,int>

using namespace std;

int lsum,val[N],mat[N][N],q[S],lay[N],low[N][N];
int n,m;
vector<pii> vec;

void build()
{
	vec.clear();
	scanf("%d%d",&n,&m);
	lsum=0;
	memset(low,0,sizeof(low));
	memset(val,0,sizeof(val));
	memset(mat,0,sizeof(mat));
	for(int i=0; i<m; i++)
	{
		int x,y,z,tg;
		scanf("%d%d%d%d",&x,&y,&z,&tg);
		x--,y--;
		vec.push_back(make_pair(x,y));
		if(tg==0)
			mat[x][y]+=z;
		else
		{
			low[x][y]+=z;
			val[x]+=-z;
			val[y]+=z;
		}
	}
	for(int i=0; i<n; i++)
	{
		if(val[i]>0)
		{
			lsum+=val[i];
			mat[n][i]=val[i];
		}
		else if(val[i]<0)
			mat[i][n+1]=-val[i];
	}
}

int bfs(int f,int t,int n)
{
	int l,r;
	q[l=r=0]=f;
	memset(lay,-1,sizeof(lay));
	lay[f]=0;
	for(; l<=r;)
	{
		int now=q[l++];
		for(int i=0; i<n; i++)
			if(mat[now][i]>0&&lay[i]<0)
				q[++r]=i,lay[i]=lay[now]+1;
	}
	return lay[t]!=-1;
}

int dfs(int now,int t,int ttl,int n)
{
	int ret=0;
	if(now==t) return ttl;
	for(int i=0; i<n&&ret<ttl; i++)
	{
		if(mat[now][i]>0&&lay[i]==lay[now]+1)
		{
			int x=dfs(i,t,min(ttl-ret,mat[now][i]),n);
			mat[now][i]-=x;
			mat[i][now]+=x;
			ret+=x;
		}
	}
	if(ret==0) lay[now]=-1;
	return ret;
}

int max_flow(int f,int t,int n)
{
	int ret=0;
	while(bfs(f,t,n))
		ret+=dfs(f,t,inf,n);
	return ret;
}

void show()
{
	for(int i=0; i<vec.size(); i++)
	{
		if(i>0)
			printf(" ");
		printf("%d",mat[vec[i].second][vec[i].first]+low[vec[i].first][vec[i].second]);
	}
	if(vec.size()>0)
		puts("");
}

void solve()
{
	int mx=max_flow(n,n+1,n+2);
	if(mx!=lsum)
	{
		mat[n-1][0]=inf;
		mx+=max_flow(n,n+1,n+2);
		if(mx!=lsum)
			puts("Impossible");
		else
		{
			int ret=mat[0][n-1];
			mat[0][n-1]=mat[n-1][0]=0;
			mx=max_flow(n-1,0,n);
			if(ret-mx<0)
				for(;;);
			printf("%d\n",ret-mx);
			show();
		}
	}
	else
	{
		puts("0");
		show();
	}
}

int main()
{
	build();
	solve();
	return 0;
}
