#include <cstdio>
#include <cstring>
typedef long long LL;
#define M 1000000007
#define MAXN 110
char s[MAXN][MAXN],tag[200];

int main()
{
	int i,n,m,j;  LL ret=1,cnt;
	scanf("%d%d",&n,&m);
	for(i=0; i<n; i++)
		scanf("%s",s[i]);
	for(j=0; j<m; j++)
	{
		memset(tag,0,sizeof(tag));
		for(i=0; i<n; i++)
			tag[s[i][j]]=1;
		for(cnt=i=0; i<200; i++)
			if(tag[i])
				cnt++;
		ret=ret*cnt%M;
	}
	printf("%I64d\n",ret);
	return 0;
}
