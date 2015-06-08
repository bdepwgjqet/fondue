#include <cstdio>
#define N 100001

int dat[N];

int main()
{
	int n,k,id;
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		for(int i=1; i<=n; i++)
			scanf("%d",&dat[i]);
		for(id=n; id>=2; id--) 
			if(dat[id-1]!=dat[id])
				break;
		if(k>=id)
			printf("%d\n",id-1);
		else
			puts("-1");
	}
	return 0;
}
