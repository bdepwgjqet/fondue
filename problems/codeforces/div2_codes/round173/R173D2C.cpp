#include <cstdio>
#include <cstring>
#define N 1100001

char s[N],t[N];

int main()
{
	scanf("%s%s",s,t);
	int so=0,to=0;
	for(int i=0; s[i]; i++)
		if(s[i]=='1')
			so++;
	for(int i=0; t[i]; i++)
		if(t[i]=='1')
			to++;
	if(strlen(s)==strlen(t))
	{
		if(so==to)
		{
			puts("YES");
		}
		else if(so>to)
		{
			if(to==0) puts("NO");
			else puts("YES");
		}
		else
		{
			if(so==0) puts("NO");
			else puts("YES");
		}
	}
	else
		puts("NO");
	return 0;
}
