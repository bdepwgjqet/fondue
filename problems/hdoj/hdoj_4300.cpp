#include <cstdio>
#include <cstring>
#define N 110001

int fail[N];
char mi[N],s[N],in[N];

void get_fail(int n)
{
	int p;
	fail[0]=-1;
	for(int i=1; i<n; i++)
	{
		p=fail[i-1];
		for(; p>=0; p=fail[p])
			if(s[p+1]==mi[s[i]-'a'])
				break;
		if(s[p+1]==mi[s[i]-'a'])
			fail[i]=p+1;
		else
			fail[i]=-1;
	}
}

int main()
{
	int t,l;
	scanf("%d",&t);
	for(; t--;)
	{
		scanf("%s%s",mi,s);
		l=strlen(s);
		int ll=strlen(mi);
		for(int i=0; i<ll; i++)
			in[mi[i]-'a']=i+'a';
		get_fail(l);
		int mid=l/2,id;
		for(id=fail[l-1]; id>=0; id=fail[id])
			if(id<mid)
				break;
		for(int i=0; i<l-id-1; i++)
			printf("%c",s[i]);
		for(int i=0; i<l-id-1; i++)
			printf("%c",in[s[i]-'a']);
		puts("");
	}
	return 0;
}
