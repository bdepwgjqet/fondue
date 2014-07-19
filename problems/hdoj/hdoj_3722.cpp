#include <cstdio>
#include <cstring>
#include <algorithm>
#define inf 0x7ffffff
#define N 1111
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

char s[N][N];
int l[N];

int main()
{
	int n,u,v,ret;
	while(scanf("%d",&n)!=EOF)
	{
		memset(mat,0,sizeof(mat));
		top=0;
		for(int i=0; i<n; i++)
			list[i]=-1;
		for(int i=0; i<n; i++)
		{
			scanf("%s",s[i]);
			l[i]=strlen(s[i]);
		}
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
			{
				insert(i,j);
				if(i==j)	continue;
				int tmp=0;
				for(u=l[i]-1,v=0; u>=0&&v<l[j]; u--,v++)
				{
					if(s[i][u]!=s[j][v])
						break;
					tmp++;
				}
				mat[i][j]=tmp;
			}
		ret=km_match(n);
		printf("%d\n",ret);
	}
	return 0;
}
