#include <vector>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define M 1011
#define N 111
typedef long long LL;
using namespace std;

int n,m,mod,vis[N];
struct edge{ int f,t,l; }e[M];

int cmp(edge a,edge b){ return a.l<b.l; }
int in[N][N];
LL mat[N][N];
vector<int> vec[N];

struct ufind
{
	int p[101];
	void init(int n)
	{
		for(int i=0; i<n; i++) p[i]=i;
	}
	int fa(int x)
	{
		int y=x,t;
		for(; x!=p[x]; x=p[x]);
		for(; p[t=y]!=x; y=p[y],p[t]=x);
		return x;
	}
	int setf(int a,int b)
	{
		a=fa(a),b=fa(b);
		p[a]=b;
		return a!=b;
	}
}uf,nowu;

LL calmat(LL mat[][N],int n)
{
    for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			mat[i][j]%=mod;
    LL ret=1;
    for(int i=1; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
            while(mat[j][i]!=0)
            {
                LL t=mat[i][i]/mat[j][i];
                for(int k=i; k<n; k++)
                    mat[i][k]=(mat[i][k]-mat[j][k]*t)%mod;
                for(int k=i; k<n; k++)
                    swap(mat[i][k],mat[j][k]);
                ret=-ret;
            }
        if(mat[i][i]==0)
			return 0;
        ret=ret*mat[i][i]%mod;
    }
    return (ret+mod)%mod;
}

int main()
{
	while(scanf("%d%d%d",&n,&m,&mod)!=EOF)
	{
		if(n==0&&m==0&&mod==0)
			break;
		for(int i=0; i<m; i++)
		{
			scanf("%d%d%d",&e[i].f,&e[i].t,&e[i].l);
			e[i].f--,e[i].t--;
		}
		sort(e,e+m,cmp);
		uf.init(n);
		nowu.init(n);
		memset(vis,0,sizeof(vis));
		memset(in,0,sizeof(in));
		int j,nowl;
		LL ret=1;
		for(int i=0; i<m; i=j)
		{
			nowu=uf;
			nowl=e[i].l;
			for(j=i; j<m; j++)
				if(e[j].l!=nowl)
					break;
			memset(vis,0,sizeof(vis));
			for(int k=i; k<j; k++)
			{
				int x=e[k].f,y=e[k].t,px=uf.fa(x),py=uf.fa(y);
				if(px==py)
					continue;
				vis[px]=vis[py]=1;
				nowu.setf(px,py);
				in[px][py]++;
				in[py][px]++;
			}
			for(int j=0; j<n; j++)
				vec[j].clear();
			for(int j=0; j<n; j++)
				if(vis[j])
				{
					int u=nowu.fa(j);
					vec[u].push_back(j);
					vis[j]=0;
				}
			for(int j=0; j<n; j++)
				if(vec[j].size()>0)
				{
					for(int u=0; u<n; u++)
						for(int v=0; v<n; v++)
							mat[u][v]=mat[v][u]=0;

					int sz=vec[j].size();
					for(int u=0; u<sz; u++)
						for(int v=u+1; v<sz; v++)
						{
							int pu=vec[j][u],pv=vec[j][v];
							mat[v][u]-=in[pu][pv];
							mat[u][v]=mat[v][u];
							mat[u][u]+=in[pu][pv];
							mat[v][v]+=in[pu][pv];
						}
					LL nowc=calmat(mat,sz);
					ret=ret*nowc%mod;
				}
			uf=nowu;
		}
		memset(vis,0,sizeof(vis));
		for(int i=0; i<n; i++)
			vis[uf.fa(i)]=1;
		int num=0;
		for(int i=0; i<n; i++)
			if(vis[i])
				num++;
		ret=(ret%mod+mod)%mod;
		int ans=int(ret);
		if(num!=1)
			puts("0");
		else
			printf("%d\n",ans);
	}
	return 0;
}
