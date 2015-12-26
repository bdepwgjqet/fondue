#include <cstdio>
#include <cstring>
#define N 1011

struct edge{ int f,t,n; }e[N<<1];
char s[N][100],st[100];
int list[N],top,cnt[26],vis[N],ans,rid;

void insert(int f,int t)
{
	e[top].f=f,e[top].t=t;
	e[top].n=list[f],list[f]=top++;
}

int ok(int i,int j)
{
	int li=strlen(s[i]),lj=strlen(s[j]);
	if(li!=lj-1)
		return 0;
	int u,v;
	for(u=v=0; s[i][u]==s[j][v]&&u<li; u++,v++);
	v++;
	for(; s[i][u]==s[j][v]&&u<li; u++,v++);
	return u==li&&v==lj;
}

void dfs(int now,int l)
{
	vis[now]=1;
	if(l>ans)
		ans=l,rid=now;
	for(int i=list[now]; i!=-1; i=e[i].n)
	{
		int to=e[i].t;
		if(vis[to])
			continue;
		dfs(to,l+1);
	}
}

int main()
{
	int n,id;
	while(scanf("%d%s",&n,&st)!=EOF)
	{
		id=-1;
		for(int i=0; i<n; i++)
		{
			scanf("%s",s[i]);
			if(strcmp(s[i],st)==0)
				id=i;
		}
		if(id==-1)
		{
			printf("%s\n",s[0]);
			continue;
		}
		top=0;
		for(int i=0; i<n; i++)
			list[i]=-1;
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				if(ok(i,j))
					insert(i,j);
		memset(vis,0,sizeof(vis));
		ans=0;
		rid=id;
		dfs(id,0);
		printf("%s\n",s[rid]);
	}
	return 0;
}
