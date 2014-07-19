#include <cstdio>
#define N 1000100

int p[N],t[N],n,st[N];

int main()
{
	scanf("%d",&n);
	for(int i=0; i<n; i++)
		scanf("%d",&p[i]);
	int m;
	scanf("%d",&m);
	for(int i=0; i<m; i++)
	{
		int x;
		scanf("%d",&x);
		t[x-1]=1;
	}
	int top=-1;
	for(int i=n-1; i>=0; i--)
	{
		if(top<0||t[i]||p[i]!=st[top])
			st[++top]=p[i],p[i]=-p[i];
		else --top;
	}
	if(top==-1)
	{
		puts("YES");
		for(int i=0; i<n; i++)
			printf("%d ",p[i]);
		puts("");
	}
	else puts("NO");
	return 0;
}
