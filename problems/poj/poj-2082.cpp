#include <cstdio>
#include <algorithm>
#define N 50001
using namespace std;

struct node{ int h,w,i,l,r; }no[N];
int len[N],top,st[N];

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if(n<0)
			break;
		for(int i=1; i<=n; i++)
			scanf("%d%d",&no[i].w,&no[i].h);
		len[0]=0;
		for(int i=1; i<=n; i++)
			len[i]=len[i-1]+no[i].w;
		top=-1;
		for(int i=1; i<=n; i++)
		{
			for(; top>=0&&no[st[top]].h>no[i].h; )
			{
				no[st[top]].r=i-1;
				top--;
			}
			if(top>=0)
				no[i].l=st[top];
			else
				no[i].l=0;
			st[++top]=i;
		}
		for(; top>=0;)
			no[st[top]].r=n,top--;
		int ret=0;
		for(int i=1; i<=n; i++)
		{
			ret=max(ret,(len[no[i].r]-len[no[i].l])*no[i].h);
		}
		printf("%d\n",ret);
	}
	return 0;
}
