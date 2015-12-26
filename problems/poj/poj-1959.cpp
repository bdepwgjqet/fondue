#include <cstdio>
#include <cstring>
#define N 111

int mul[3]={1,2,3};
int vis[4001],top;
struct node{ int v,c; }no[N];

void init()
{
	memset(vis,0,sizeof(vis));
	int now;
	for(int i=0; i<3; i++)
		for(int j=1; j<=20; j++)
		{
			now=mul[i]*j;
			vis[now]++;
		}
	vis[25]++;
	vis[50]++;
	no[0].v=0,no[0].c=1;
	top=1;
	for(int i=1; i<=1001; i++)
		if(vis[i]>0)
			no[top].v=i,no[top++].c=vis[i];
	memset(vis,0,sizeof(vis));
	for(int i=0; i<top; i++)
		for(int j=i; j<top; j++)
			for(int k=j; k<top; k++)
			{
				now=no[i].v+no[j].v+no[k].v;
				if(no[i].v==no[j].v&&no[j].v==no[k].v)
					vis[now]+=no[i].c*(no[i].c+1)*(no[i].c+2)/6;
				else if(no[i].v==no[j].v)
					vis[now]+=no[i].c*(no[i].c+1)/2*no[k].c;
				else if(no[j].v==no[k].v)
					vis[now]+=no[i].c*(no[j].c*(no[j].c+1)/2);
				else
					vis[now]+=no[i].c*no[j].c*no[k].c;
			}
}

int main()
{
	int n,t,ca=1;
	init();
	scanf("%d",&t);
	for(; ca<=t; ca++)
	{
		scanf("%d",&n);
		printf("Scenario #%d:\n",ca); 
		printf("%d\n",vis[n]);
		puts("");
	}
	return 0;
}
