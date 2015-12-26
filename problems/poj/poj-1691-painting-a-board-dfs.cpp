#include <cstdio>
#include <cstring>
#define MAXN 22
#define MAXS 4444
#define X 32768

struct rectangle
{
	int x1,y1,x2,y2,c;
}rec[MAXN]; 

struct edge{ int f,t,n; }e[MAXS];

int top,list[MAXN],col[MAXN][MAXN],dp[MAXN][X],ret,n;

void insert(int f,int t)
{
	e[top].f=f,e[top].t=t;
	e[top].n=list[f],list[f]=top++;
}

int up_board(int i,int j)
{
	if(rec[j].x2!=rec[i].x1)
		return 0;
	if(rec[j].y1>=rec[i].y1&&rec[j].y1<rec[i].y2)
		return 1;
	if(rec[j].y2<=rec[i].y2&&rec[j].y2>rec[i].y1)
		return 1;
	return 0;
}

inline int B(int i){ return 1<<i; }

void dfs(int cnt,int s)
{
	int i,j,t,c,k,jj,no[15],tp,nc; 
//	printf("%d %d=>",cnt,s);
	if(dp[cnt][s]>0)	return ;
	dp[cnt][s]=1;
	if(cnt>=ret)		return ;
	if(s==(B(n)-1))
	{
		ret=cnt;
		return ;
	}
	
	for(i=0; i<n; i++)
	{
		for(j=list[i]; j!=-1; j=e[j].n)
		{
			t=e[j].t;
			if((s&B(t))==0)
				break;
		}
		if(j==-1&&(s&B(i))==0)
		{
			s^=B(i);
			c=rec[i].c;
			for(tp=0,k=1; k<=col[c][0]; k++)
			{
				nc=col[c][k];
				if(nc==i)	continue;
				for(jj=list[nc]; jj!=-1; jj=e[jj].n)
				{
				//	printf("%d>>>>",e[jj].t);
					if((s&B(e[jj].t))==0)
						break;
				}
				if((jj==-1)&&(s&B(nc))==0)
				{
					s^=B(nc),no[tp++]=nc;
				}
			}
			dfs(cnt+1,s);
			for(jj=0; jj<tp; jj++)
				s^=B(no[jj]);
			s^=B(i);
		}
	}
	
}

int main()
{
	int t,ctop,i,j;
	scanf("%d",&t);
	for(; t--;)
	{
		scanf("%d",&n);
		memset(col,0,sizeof(col));
		memset(dp,-1,sizeof(dp));
		for(top=i=0; i<n; i++)	list[i]=-1;
		for(i=0; i<n; i++)
		{
			scanf("%d%d%d%d%d",&rec[i].x1,&rec[i].y1,&rec[i].x2,&rec[i].y2,&rec[i].c);
			ctop=++col[rec[i].c][0];
			col[rec[i].c][ctop]=i;
		}
		for(i=0; i<n; i++)
		{
			if(i==j)	continue;
			for(j=0; j<n; j++)
				if(up_board(i,j))
				{
					insert(i,j);
				}
		}
		/*
		for(i=1; i<=2; i++,puts(""))
			for(j=1; j<=col[i][0]; j++)
				printf("%d ",col[i][j]);
				*/
		ret=MAXN;
		dfs(0,0);
		printf("%d\n",ret);
	}
	return 0;
}
