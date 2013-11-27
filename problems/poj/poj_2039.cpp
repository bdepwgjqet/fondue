#include <cstdio>
#include <cstring>
#define N 201

char mat[N][N];
char s[N];
int cnt[N];

int main()
{
	int n,l;
	while(scanf("%d",&n))
	{
		if(n==0)
			break;
		scanf("%s",s);
		l=strlen(s);
		memset(mat,0,sizeof(mat));
		memset(cnt,0,sizeof(cnt));
		int i,j,add,id;
		for(i=0,j=1; i<l; i+=n)
		{
			if(j&1)
				add=1,id=1;
			else
				add=-1,id=n;
			for(int k=0; k<n; k++)
			{
				mat[j][id]=s[i+k];
				cnt[id]++;
				id+=add;
			}
			j++;
		}
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=cnt[i]; j++)
				printf("%c",mat[j][i]);
		}
		puts("");
	}
	return 0;
}
