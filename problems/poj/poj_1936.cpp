#include <cstdio>
#include <cstring>
#define N 100010

char s[N],t[N];

int ok()
{
	int l1=strlen(s),l2=strlen(t),j=0;
	for(int i=0; i<l1&&j<l2; i++,j++)
	{
		for(; j<l2&&t[j]!=s[i]; j++);
		if(j>=l2)
			return 0;
	}
	return 1;
}

int main()
{
	while(scanf("%s%s",s,t)!=EOF)
	{
		if(ok())
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}
