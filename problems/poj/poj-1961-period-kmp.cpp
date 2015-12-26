#include <cstdio>
#define MAXN 1000100
char s[MAXN];
int fail[MAXN],ret[MAXN];

void get_fail(int n)
{
	int i,pre;
	fail[0]=-1; ret[0]=0;
	for(i=1; i<n; i++)
	{
		pre=fail[i-1];
		for(; pre>-1&&s[pre+1]!=s[i]; pre=fail[pre]);
		if(s[pre+1]==s[i])
		{
			fail[i]=pre+1;
			if((i+1)%(i-fail[i])==0)
				ret[i]=ret[fail[i]]+1;
			else
				ret[i]=0;
		}
		else
			fail[i]=-1,ret[i]=0;
	}
}

int main()
{
	int n,i,ca=1;
	while(scanf("%d",&n)&&n)
	{
		printf("Test case #%d\n",ca++);
		scanf("%s",s);
		get_fail(n);
		
		/*
		for(i=0; i<n; i++)
			printf("%d ",ret[i]);
		puts("");
		for(i=0; i<n; i++)
			printf("%d ",fail[i]);
		puts("");
		*/
		
		for(i=1; i<n; i++)
			if(ret[i]>=1)
				printf("%d %d\n",i+1,ret[i]+1);
		puts("");
	}
	return 0;
}
