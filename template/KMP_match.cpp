//KMP_Match
#include <cstdio>
#include <cstring>

void kmp_fail(char s[],int fail[])
{
	int i,p,l=strlen(s);
	for(fail[0]=-1,i=1; i<l; i++)
	{
		p=fail[i-1];
		while(p>=0&&s[p+1]!=s[i])	p=fail[p];
		if(s[p+1]==s[i])	fail[i]=p+1;
		else	fail[i]=-1;
	}
}

int kmp_match(char s[],char t[],int fail_t[])
{
	int SL=strlen(s),TL=strlen(t),s_i,t_i;
	kmp_fail(t,fail_t);
	for(s_i=t_i=0; s_i<SL&&t_i<TL;)
	{
		if(s[s_i]==t[t_i])	s_i++,t_i++;
		else if(t_i==0)	s_i++;
		else	t_i=fail_t[t_i-1]+1;
	}
	return t_i<TL?-1:s_i-t_i;
}
