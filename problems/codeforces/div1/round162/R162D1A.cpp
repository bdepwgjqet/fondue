#include <cstdio>
#include <cstring>
#define N 1000011

struct node{ int l,r,i,c; }no[N];

char s[N];

int main()
{
	scanf("%s",s);
	int l=strlen(s),top;
	for(int i=0; i<N; i++)
		no[i].l=no[i].r=-1,no[i].i=i;
	node *le,*ri;
	le=&no[0],ri=&no[1];
	le->l=-1,ri->r=-1;
	le->r=1,ri->l=0;
	top=2;
	for(int i=0; i<l; i++)
	{
		no[top].c=i;
		no[top].l=le->i;
		no[top].r=ri->i;
		le->r=no[top].i;
		ri->l=no[top].i;
		if(s[i]=='l')
		{
			ri=&no[top];
		}
		else
		{
			le=&no[top];
		}
		top++;
	}
	node now;
	now=no[0];
	for(;; now=no[now.r])
	{
		if(now.r==-1)
			break;
		if(now.l!=-1)
			printf("%d\n",now.c+1);
	}
}
