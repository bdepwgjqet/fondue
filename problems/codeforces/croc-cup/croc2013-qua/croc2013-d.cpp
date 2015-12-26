#include <cstdio>

int B(int i){ return 1<<i; }
int tag[10010];
int ret[22][10010];

int main()
{
	int n,k,top=0;
	scanf("%d%d",&n,&k);
	for(int i=0; i<22; i++)
		for(int j=0; j<10010; j++)
			ret[i][j]=n;
	for(int i=0; n-B(i)>=0; i++)
		tag[n-B(i)]=1;
	for(int i=0; B(i)<n; i++)
	{
		for(int j=0; j<=B(i); j++)
			ret[top][j]=n;
		for(int j=B(i)+1; j<n; j++)
		{
			if(tag[n-j])
				ret[top][n-j]=n-j;
			else if((j-1)&B(i))
				ret[top][n-j]=n-B(i);
			else
				ret[top][n-j]=n;
		}
		top++;
	}
	if(top>k) for(;;);
	for(int i=0; i<k; i++,puts(""))
		for(int j=1; j<=n; j++)
			printf("%d ",ret[i][j]);
	return 0;
}
