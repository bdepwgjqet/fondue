#include <cstdio>
#define N 1001

char s[N];

int main()
{
	int n;
	int x=0;
	scanf("%d",&n);
	for(int i=0; i<n; i++)
	{
		scanf("%s",s);
		if(s[0]=='X')
		{
			if(s[1]=='-')
				x--;
			else
				x++;
		}
		else
		{
			if(s[0]=='-')
				x--;
			else
				x++;
		}
	}
	printf("%d\n",x);
	return 0;
}
