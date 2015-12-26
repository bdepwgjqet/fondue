#include <cstdio>
#include <cstring>
#define MAXN 110
char s[MAXN][MAXN];
char max[MAXN];

int main()
{
	memset(max,0,sizeof(max));
	int n,m,i,j,ret;
	scanf("%d%d",&n,&m);
	for(i=0; i<n; i++)
		scanf("%s",s[i]);
	for(j=0; j<m; j++)
		for(i=0; i<n; i++)
			if(s[i][j]>max[j])
				max[j]=s[i][j];
	for(ret=i=0; i<n; i++)
	{
		for(j=0; j<m; j++)
			if(s[i][j]==max[j])
			{
				ret++;
				break;
			}
	}
	printf("%d\n",ret);
	return 0;
}
