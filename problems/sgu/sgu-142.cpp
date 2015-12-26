#include <cstdio>
#include <cstring>
#define X 19
#define N 1<<19

char s[N];
int tag;
bool vis[N];

inline int B(int i){ return 1<<i; }

void show(int x,int l)
{
	if(l==0) return;
	show(x>>1,l-1);
	printf("%c",'a'+(x&1));
}

int main()
{
	int n;
	scanf("%d%s",&n,s);
	memset(vis,0,sizeof(vis));
	for(int i=0; i<n; i++)
		s[i]-='a';
	tag=0;
	for(int l=1; l<=X&&tag==0; l++)
	{
		int x=0,y=B(l)-1;
		for(int i=0; i<l-1; i++)
			x<<=1,x|=s[i];
		for(int i=0; i<B(l); i++)
			vis[i]=0;
		for(int i=l-1; i<n; i++)
			vis[x=(((x<<1)&y)|s[i])]=1;
		for(int i=0; i<B(l); i++)
		{
			if(vis[i]==0)
			{
				tag=1;
				printf("%d\n",l);
				show(i,l);
				puts("");
				break;
			}
		}
	}
	return 0;
}
