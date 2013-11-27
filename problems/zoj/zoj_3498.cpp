#include <cstdio>

int dfs(int n)
{
	if(n==1)
		return 1;
	return dfs(n/2)+1;
}

int main()
{
	int ts;
	scanf("%d",&ts);
	while(ts--)
	{
		int n;
		scanf("%d",&n);
		printf("%d\n",dfs(n));
	}
	return 0;
}
