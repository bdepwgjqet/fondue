#include <cstdio>
#include <algorithm>
#define N 1001
using namespace std;

int r[N],c[N],mat[N][N];

int main()
{
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1; i<=n; i++)
		r[i]=i;
	for(int i=1; i<=m; i++)
		c[i]=i;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			scanf("%d",&mat[i][j]);
	char s[10];
	for(int i=1; i<=k; i++)
	{
		int x,y;
		scanf("%s%d%d",s,&x,&y);
		if(s[0]=='c')
		{
			swap(c[x],c[y]);
		}
		else if(s[0]=='r')
		{
			swap(r[x],r[y]);
		}
		else
		{
			printf("%d ",mat[r[x]][c[y]]);
		}
	}
	puts("");
	return 0;
}
