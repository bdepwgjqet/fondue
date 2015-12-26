#include <cstdio>
#include <cstring>
#define MAXN 210

int cir[MAXN],tag[MAXN],len[MAXN],dat[MAXN][MAXN];
char s[MAXN],ret[MAXN];

int calc(int id)
{
	int t=cir[id],ret=1;
	tag[id]=1;
	for(; !tag[t]; ret++)
		tag[t]=1,t=cir[t];
	return ret;
}

void update(int id,int l)
{
	int x=cir[id];
	for(len[id]=l; x!=id; )
		len[x]=l,x=cir[x];
}

void init(int id)
{
	int x=cir[id],cnt=1;
	dat[id][0]=id;
	for(; x!=id; )
		dat[id][cnt++]=x,x=cir[x];
}

int main()
{
	int n,k,i,l,ls;
	while(scanf("%d",&n)&&n)
	{
		memset(tag,0,sizeof(tag));
		memset(dat,0,sizeof(dat));
		for(i=1; i<=n; i++)
			scanf("%d",&cir[i]);
		for(i=1; i<=n; i++)
			if(!tag[i])
			{
				l=calc(i);
				update(i,l);
			}
		/*
		for(i=1; i<=n; i++)
			printf("%d ",len[i]);
		puts("");
		*/
		for(i=1; i<=n; i++)
			init(i);
		/*
		for(i=1; i<=n; i++,puts(""))
			for(int j=0; j<len[i]; j++)
				printf("%d ",dat[i][j]);
		*/
		while(scanf("%d",&k)&&k)
		{
			getchar();
			gets(s);
			ls=strlen(s);
			for(i=ls; i<n; i++)
				s[i]=' ';
			for(i=0; i<n; i++)
			{
				ret[dat[i+1][k%len[i+1]]-1]=s[i];
			}
			for(i=0; i<n; i++)
				printf("%c",ret[i]);
			puts("");
		}
		puts("");
	}
	return 0;
}
