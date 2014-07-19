#include <cstdio>
#include <cstring>
#define N 211
#define S 100001

struct edge{ int f,t,n; }e[S];
int list[N],top,y[N],match[N];
char s[N];

void insert(int f,int t)
{
	e[top].f=f,e[top].t=t,e[top].n=list[f];
	list[f]=top++;
}

int find(int now)
{
	for(int i=list[now]; i!=-1; i=e[i].n)
	{
		int to=e[i].t;
		if(!y[to])
		{
			y[to]=1;
			if(match[to]<0||find(match[to]))
			{
				match[to]=now;
				return 1;
			}
		}
	}
	return 0;
}

int hungary(int m,int n)
{
	int ret=0;
	memset(match,-1,sizeof(match));
	for(int i=0; i<m; i++)	
	{
		memset(y,0,sizeof(y));
		if(find(i))
			ret++;
	}
	return ret;
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		top=0;
		for(int i=0; i<n; i++)
			list[i]=-1;
		for(int i=0; i<n; i++)
		{
			scanf("%s",s);
			for(int j=0; j<n; j++)
				if(s[j]=='U')
					insert(i,j);
		}
		int ret=hungary(n,n);
		if(n==ret)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
