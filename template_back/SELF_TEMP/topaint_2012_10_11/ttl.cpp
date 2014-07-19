#include <cstring>
#include <cstdio>
#define N 52
#define S 1000

struct node{ int next[N],fail,is; }no[S];
int top,q[S];

inline int get_ind(char x){ return x-'a'; }

void init()
{
	top=1;
	for(int i=0; i<S; i++)
	{
		no[i].is=0,no[i].fail=-1;
		for(int j=0; j<N; j++)
			no[i].next[j]=-1;
	}
}

void insert(char s[])
{
	int l=strlen(s),p=0;
	for(int i=0; i<l; i++)
	{
		int ii=get_ind(s[i]);
		if(no[p].is)
			break;
		if(no[p].next[ii]==-1)
			no[p].next[ii]=top++;
		p=no[p].next[ii];
	}
	no[p].is=1;
}

void build_ac(int n)
{
	int l,r;
	q[l=r=0]=0;
	for(; l<=r;)
	{
		int now=q[l++];
		for(int i=0; i<n; i++)
		{
			int ii=no[now].next[i];
			if(ii==-1)
			{
				if(now==0)
					no[now].next[i]=0;
				else
					no[now].next[i]=no[no[now].fail].next[i];
			}
			else
			{
				if(now==0)
					no[ii].fail=0;
				else
				{
					no[ii].fail=no[no[now].fail].next[i];
					if(no[no[ii].fail].is)
						no[ii].is=1;
				}
				q[++r]=ii;
			}
		}
	}
}
#include <cstdio>
#include <cstring>
#include <algorithm>
#define inf 0x3fffffff
#define N 1001
#define S 1000100

using namespace std;

struct edge{ int f,t,n; }e[S];

int slack[N],valx[N],valy[N],mat[N][N],m2y[N],vx[N],vy[N],list[N],top;

void insert(int f,int t)
{
	e[top].f=f,e[top].t=t;
	e[top].n=list[f],list[f]=top++;
}

int find_path(int now)
{
	int t,i,v;
	vx[now]=1;
	for(i=list[now]; i!=-1; i=e[i].n)
	{
		t=e[i].t;
		v=valx[now]+valy[t]-mat[now][t];
		if(!vy[t]&&v==0)
		{
			vy[t]=1;
			if(m2y[t]==-1||find_path(m2y[t]))
			{
				m2y[t]=now;
				return 1;
			}
		}
		else if(slack[t]>v)
			slack[t]=v;
	}
	return 0;
}

int km_match(int n)
{
	int i,j,k,ret=0,d;
	for(i=0; i<n; i++)
	{
		m2y[i]=-1;
		valx[i]=-inf,valy[i]=0;
		for(j=0; j<n; j++)
			valx[i]=max(valx[i],mat[i][j]);
	}
	for(i=0; i<n; i++)
	{
		memset(vx,0,sizeof(vx));
		memset(vy,0,sizeof(vy));
		for(k=0; k<n; k++)
			slack[k]=inf;
		for(; !find_path(i); )
		{
			d=inf;
			for(k=0; k<n; k++)
				if(!vy[k]&&slack[k]<d)
					d=slack[k];
			for(k=0; k<n; k++)
			{
				if(vx[k])
					valx[k]-=d,vx[k]=0;
				if(vy[k])
					valy[k]+=d,vy[k]=0;
			}
		}
	}
	for(i=0; i<n; i++)
		ret+=valx[i]+valy[i];
	return ret;
}
#include <cstdio>
#include <cmath>
#define N 20000
#define S 100000

typedef long long LL;

struct edge{ int f,t,n; }e[S];
struct node{ int h,i; }no[N];
int v[N],top,list[N],tp,dp[N][17],pos[N];

inline int B(int i){ return 1<<i; }
int big(int i,int j){ return no[i].h>no[j].h?i:j; }
int small(int i,int j){ return no[i].h<no[j].h?i:j; }

void insert(int f,int t)
{
	e[top].f=f,e[top].t=t;
	e[top].n=list[f],list[f]=top++;
}

void dfs(int now,int l)
{
	v[now]=1;
	pos[now]=tp;
	no[tp].i=now;
	no[tp++].h=l;
	for(int i=list[now]; i!=-1; i=e[i].n)
	{
		int to=e[i].t;
		if(!v[to])
		{
			dfs(to,l+1);
			no[tp].i=now;
			no[tp++].h=l;
		}
	}
}

void RMQ(int n)
{
	int k=int(log(1.0*n)/log(2.0));
	for(int i=1; i<=n; i++)
		dp[i][0]=i;
	for(int j=1; j<=k; j++)
		for(int i=1; i<=n; i++)
		{
			if(i+B(j)-1>n)
				break;
			dp[i][j]=small(dp[i][j-1],dp[i+B(j-1)][j-1]);
		}
}

int query(int l,int r)
{
	int d,k;
	if(l>r) d=l,l=r,r=d;
	d=r-l+1;
	k=int(log(1.0*d)/log(2.0));
	return small(dp[l][k],dp[r-B(k)+1][k]);
}
#include <cstdio>
#include <vector>
#define N 50000
#define S 200000

using namespace std;

struct edge{ int f,t,l,n; }e[S];
struct node{ int t,r,i;
	node(int a,int b,int c){ t=a,r=b,i=c; }
};
vector<node> q[N];
int v[N],vis[N],len[N],ret[N],list[N],top;

void insert(int f,int t,int l)
{
	e[top].f=f,e[top].t=t,e[top].l=l;
	e[top].n=list[f],list[f]=top++;
}

struct ufind
{
	int p[N],t;
	void init(){ for(int i=0; i<N; p[i]=i++); }
	void run(int &x)
	{ 
		int y=x;
		for(; (t=p[x])!=x; x=p[x],p[t]=p[x]);
		for(; p[t=y]!=x; p[y]=x,y=p[t]);
	}
	int isfriend(int i,int j)
	{
		run(i); run(j);
		return i==j;
	}
	void setfriend(int i,int j)
	{
		run(i); run(j);
		p[i]=j;
	}
}uf;

void tarjan(int now,int l)
{
	len[now]=l;
	v[now]=1;
	for(int i=list[now]; i!=-1; i=e[i].n)
	{
		int to=e[i].t;
		if(v[to])
			continue;
		tarjan(to,l+e[i].l);
		uf.setfriend(to,now);
	}
	vis[now]=1;
	for(int i=0; i<q[now].size(); i++)
	{
		int to=q[now][i].t;
		if(!vis[to])
			continue;
		int p=to,ii=q[now][i].i;
		uf.run(p);
		ret[ii]=l+len[to]-2*len[p];
		q[now][i].r=l+len[to]-2*len[p];
	}
}
#include <cstdio>
#include <cstdlib>
#include <ctime>
#define N 1001
typedef long long LL;
using namespace std;

LL list[N];
int top;

LL mulmod(LL a,LL b,LL n)
{
	LL ret=0;
	a=a%n;
	for(; b; )
	{
		if(b&1)
		{
			ret=ret+a;
			if(ret>n) ret-=n;
		}
		a<<=1;
		if(a>n)
			a-=n;
		b>>=1;
	}
	return ret;
}

LL expmod(LL a,LL b,LL n)
{
	LL ret=1;
	for(; b;)
	{
		if(b&1)
			ret=mulmod(ret,a,n);
		a=mulmod(a,a,n);
		b>>=1;
	}
	return ret;
}

int miller_rabbin(LL n,int times=8)
{
	if(n==2) return 1;
	if((n&1)==0||n<2) return 0;
	LL m=n-1,x,y;
	int k=0;
	for(; (m&1)==0; m>>=1,k++);
	for(int i=0; i<times; i++)
	{
		x=rand()%(n-2)+2;
		y=x=expmod(x,m,n);
		if(x==1) continue;
		for(int j=0; j<k; j++)
		{
			y=mulmod(x,x,n);
			if(y==1&&x!=n-1&&x!=1) return 0;
			x=y;
		}
		if(y!=1) return 0;
	}
	return 1;
}

LL gcd(LL a,LL b){ return b?gcd(b,a%b):a; }

LL pollar_rho(LL n,int c)
{
	LL x,y,p;
	int i=1,k=2;
	y=x=rand()%(n-1)+1;
	for(;;)
	{
		i++;
		x=(mulmod(x,x,n)+c)%n;
		if(x==y) return n;
		p=gcd(x-y,n);
		if(1<p&&p<n) return p;
		if(i==k)
		{
			k<<=1;
			y=x;
		}
	}
}


void find_fac(LL n,int c)
{
	if(n==1)
		return;
	if(miller_rabbin(n))
	{
		list[top++]=n;
		return;
	}
	LL x=n;
	int nc=c;
	for(; x>=n; )
		x=pollar_rho(n,nc--);
	find_fac(n/x,c);
	find_fac(x,c);
}
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
#include <cstdio>
#define N 1001
#define S 100001

struct edge{ int f,t,n; }e[S];
int list[N],top,y[N],match[N][N],cnt[N],lim[N];

void insert(int f,int t)
{
	e[top].f=f,e[top].t=t;
	e[top].n=list[f],list[f]=top++;
}

int find(int now)
{
	for(int i=list[now]; i!=-1; i=e[i].n)
	{
		int to=e[i].to;
		if(!y[to])
		{
			v[to]=1;
			if(cnt[to]<lim[to])
			{
				match[to][cnt[to]++]=now;
				return 1;
			}
			for(int j=0; j<cnt[to]; j++)
				if(find(match[to][j]))
				{
					match[to][j]=now;
					return 1;
				}
		}
	}
	return 0;
}

int multi_hungary(int m,int n)
{
	int ret=0;
	memset(cnt,0,sizeof(cnt));
	for(int i=0; i<m; i++)
	{
		memset(y,0,sizeof(y));
		if(find(i))
			ret++;
	}
	return ret;
}
#include <cstdio>
#include <algorithm>
#define N 100011
using namespace std;

int perm[N],dat[N],cnt[20][N],tree[20][N];
int cmp(int a,int b){ return a<b; }

void build(int c,int l,int r)
{
	int mid=(l+r)>>1,lc=mid-l+1,lp=l,rp=mid+1;
	if(l==r) return;
	for(int i=l; i<=mid; i++)
		if(perm[i]<perm[mid])
			lc--;
	for(int i=l; i<=r; i++)
	{
		if(i==l)
			cnt[c][i]=0;
		else
			cnt[c][i]=cnt[c][i-1];
		if(tree[c][i]==perm[mid])
		{
			if(lc>0)
			{
				lc--;
				cnt[c][i]++;
				tree[c+1][lp++]=tree[c][i];
			}
			else
				tree[c+1][rp++]=tree[c][i];
		}
		else if(tree[c][i]<perm[mid])
		{
			cnt[c][i]++;
			tree[c+1][lp++]=tree[c][i];
		}
		else
			tree[c+1][rp++]=tree[c][i];
	}
	build(c+1,l,mid);
	build(c+1,mid+1,r);
}

int query(int c,int l,int r,int ql,int qr,int k)
{
	if(l==r) return perm[l];
	int c1,c2=cnt[c][qr],mid=(l+r)>>1,d1=ql-l,d2=qr-ql+1;
	if(ql==l) c1=0;
	else c1=cnt[c][ql-1];
	c2-=c1;
	if(k<=c2)
		return query(c+1,l,mid,l+c1,l+c1+c2-1,k);
	else
		return query(c+1,mid+1,r,mid+1+d1-c1,mid+d1+d2-c1-c2,k-c2);
}
#include <cstdio>
#include <cmath>
#include <algorithm>
#define N 50000

using namespace std;

int dat[N],dp[N][18],mi[N][18];

inline int B(int i){ return 1<<i; }
inline int big(int a,int b){ return a>b?a:b; }		//to be change
inline int small(int a,int b){ return a<b?a:b; }

void RMQ(int n)
{
	int k=int(log(1.0*n)/log(2.0));
	for(int i=1; i<=n; i++)
		dp[i][0]=mi[i][0]=dat[i];
	for(int j=1; j<=k; j++)
		for(int i=1; i<=n; i++)
		{
			if(i+B(j)-1>n)
				break;
			dp[i][j]=big(dp[i][j-1],dp[i+B(j-1)][j-1]);
			mi[i][j]=small(mi[i][j-1],mi[i+B(j-1)][j-1]);
		}
}

int query(int l,int r,int tag)
{
	int k=int(log(1.0*(r-l+1))/log(2.0));
	if(tag==1)
		return big(dp[l][k],dp[r-B(k)+1][k]);
	else
		return small(mi[l][k],mi[r-B(k)+1][k]);
}
#include <cstdio>
#include <cmath>
#include <cstring>
#define N 100001

char s[N];
int sa[N],sb[N],cnt[N],rank[N],dat[N],dp[N][20],height[N];
int equal(int i,int j,int l,int *y){ return y[i]==y[j]&&y[i+l]==y[j+l]; }

inline int B(int i){ return 1<<i; }

void radix_sort(int n,int m,int l,int *x,int *y)
{
	int k,i;
	for(k=0,i=n-l; i<n; i++) y[k++]=i;
	for(i=0; i<n; i++) 
		if(sa[i]>=l) y[k++]=sa[i]-l;
	memset(cnt,0,sizeof(cnt));
	for(i=0; i<n; i++) cnt[x[i]]++;
	for(i=1; i<m; i++) cnt[i]+=cnt[i-1];
	for(i=n-1; i>=0; i--) sa[--cnt[x[y[i]]]]=y[i];
}

void da(int n,int m)
{
	int *t,*x=rank,*y=sb,l,k,i;
	for(i=0; i<n; i++) x[i]=s[i],sa[i]=i;
	radix_sort(n,m,0,x,y);
	for(k=l=1; k<n; l<<=1)
	{
		radix_sort(n,m,l,x,y);
		t=x,x=y,y=t;
		x[sa[0]]=0,k=1;
		for(i=1; i<n; i++)
			x[sa[i]]=equal(sa[i],sa[i-1],l,y)?k-1:k++;
		m=k;
	}
	for(i=0; i<n; i++) rank[sa[i]]=i;
}

void calc_height(int n)
{
	int k=0;
	for(int i=0; i<n-1; i++)
	{
		k=(k>0)?k-1:0;
		for(int j=sa[rank[i]-1]; s[i+k]==s[j+k]; k++);
		height[rank[i]]=k;
	}
	height[0]=0;
}

void RMQ(int n)
{
	int k=int(log(1.0*n)/log(2.0)),a,b;
	for(int i=1; i<=n; i++)
		dat[i]=height[i-1],dp[i][0]=i;
	for(int j=1; j<=k; j++)
		for(int i=1; i+B(j)-1<=n; i++)
		{
			a=dp[i][j-1];
			b=dp[i+B(j-1)][j-1];
			if(dat[a]<dat[b]) dp[i][j]=a;
			else dp[i][j]=b;
		}
}

int RMQ_query(int a,int b)
{
	int k=int(log(1.0*(b-a+1))/log(2.0));
	a=dp[a][k],b=dp[b-B(k)+1][k];
	return dat[a]>dat[b]?b:a;
}

int lcp(int a,int b)
{
	int t;
	a=rank[a],b=rank[b];
	if(a>b) t=a,a=b,b=t;
	return height[RMQ_query(a+1,b)];
}
//ZhuLiu MST
#include <cstdio>
#include <cstring>
#define inf 1e8
#define S 1000001
#define N 1001

typedef int elem_t;

struct edge{ int f,t; elem_t l; }e[S];
int top,list[N],id[N],v[N],pre[N];
elem_t len[N];

elem_t ZL_MST(int r,int n)
{
	int nextn,f,t;
	elem_t ret=0;
	while(1)
	{
		memset(pre,-1,sizeof(pre));
		memset(v,-1,sizeof(v));
		memset(id,-1,sizeof(id));
		for(int i=0; i<n; i++)
			len[i]=inf;
		for(int i=0; i<top; i++)
		{
			f=e[i].f,t=e[i].t;
			if(f==t) continue;
			if(len[t]>e[i].l)
				len[t]=e[i].l,pre[t]=f;
		}
		for(int i=0; i<n; i++)
			if(pre[i]==-1&&i!=r)
				return -1;	//impossible to spanning a tree
		nextn=0;
		len[r]=0;
		for(int i=0; i<n; i++)
		{
			ret+=len[i];
			int now=i;
			for(; v[now]!=i&&id[now]==-1&&now!=r; )
			{
				v[now]=i;
				now=pre[now];
			}
			if(now!=r&&id[now]==-1)
			{
				for(int f=pre[now]; f!=now; f=pre[f])
					id[f]=nextn;
				id[now]=nextn++;
			}
		}
		if(nextn==0) break;	//no rings
		for(int i=0; i<n; i++)
			if(id[i]<0)
				id[i]=nextn++;
		for(int i=0; i<top; i++)
		{
			f=e[i].f,t=e[i].t;
			e[i].f=id[f];
			e[i].t=id[t];
			if(f==t) continue;
			e[i].l-=len[t];
		}
		n=nextn;
		r=id[r];
	}
	return ret;
}
