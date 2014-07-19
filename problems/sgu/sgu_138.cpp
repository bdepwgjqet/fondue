#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#define N 10101

using namespace std;

struct node{ int c,i; }no[N];
int ans[N][2];
int top,tp;

int cmp(node a,node b){ return a.c>b.c; }

int main()
{
	int n,s=0;
	tp=0;
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
	{
		int x;
		scanf("%d",&x);
		if(x==0)
			continue;
		no[tp].c=x,no[tp++].i=i;
		s+=x;
	}
	s>>=1;

	sort(no,no+tp,cmp);
	memset(ans,-1,sizeof(ans));

	for(int i=1; i<=s; i++)
	{
		if(no[top].c==1)
		{
			ans[i][1]=no[top++].i;
		}
		ans[i][0]=no[top].i;
		no[top].c--;
	}
	for(int i=1; i<=s; i++)
	{
		if(ans[i][1]>0)
			continue;
		if(no[top].c==0) top++;
		ans[i][1]=no[top].i;
		no[top].c--;
	}
	printf("%d\n",s);
	for(int i=1; i<=s; i++)
	{
		printf("%d %d\n",ans[i][0],ans[i][1]);
	}
	return 0;
}
