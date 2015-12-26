#include <cstdio>
#define N 1001

struct node{ int y,m,d,v; }no[N];
int mo[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

inline int is(int y){ return ((y%4==0)&&(y%100))||(y%400==0); }
inline int equal(node a,node b){ return a.y==b.y&&a.m==b.m&&a.d==b.d; }

int ok(node a,node b)
{
	int m;
	a.d++;
	if(is(a.y)&&a.m==2)
		m=mo[a.m]+1;
	else
		m=mo[a.m];
	if(a.d>m)
		a.d=1,a.m++;
	else
		return equal(a,b);
	if(a.m>12)
		a.m=1,a.y++;
	return equal(a,b);
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			break;
		for(int i=0; i<n; i++)
			scanf("%d%d%d%d",&no[i].d,&no[i].m,&no[i].y,&no[i].v);
		int l=0,ret=0;
		node now=no[0];
		for(int i=1; i<n; i++)
		{
			if(ok(now,no[i]))
				l++,ret+=no[i].v-now.v;
			now=no[i];
		}
		printf("%d %d\n",l,ret);
	}
	return 0;
}
