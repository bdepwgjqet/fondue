#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 1000

char s[N];
int cnt[26];

using namespace std;

int letter(char x)
{
	return ('a'<=x&&x<='z')||('A'<=x&&x<='Z');
}

int get(char x)
{
	if(x>='a')
		return x-'a';
	return x-'A';
}

int cmp(int a,int b){ return a>b; }

int main()
{
	int n;
	scanf("%d",&n);
	getchar();
	for(int i=0; i<n; i++)
	{
		gets(s);
		memset(cnt,0,sizeof(cnt));
		for(int j=0; s[j]; j++)
		{
			if(letter(s[j]))
				cnt[get(s[j])]++;
		}
		sort(cnt,cnt+26,cmp);
		int ret=0;
		for(int i=0; i<26; i++)
			ret+=(26-i)*cnt[i];
		printf("Case #%d: %d\n",i+1,ret);
	}
	return 0;
}
