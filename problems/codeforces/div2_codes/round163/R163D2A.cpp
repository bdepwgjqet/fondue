#include <cstdio>

int main()
{
	int n,ret=0;
	char s[1000],pre=-1;
	scanf("%d%s",&n,s);
	for(int i=0; s[i]; i++)
		if(s[i]==pre)
			ret++;
		else
			pre=s[i];
	printf("%d\n",ret);
	return 0;
}
