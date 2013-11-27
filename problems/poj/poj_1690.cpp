#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#define N 1001
using namespace std;

char s[N];

string dfs(int l,int r)
{
	if(l>r)
		return "";
	string ret;
	if(l==r)
	{
		ret+=s[l];
		return ret;
	}
	int i,t=0,ll,rr,fh=0;
	for(i=l; i<=r; i++)
	{
		if(s[i]!='(')
			ret+=s[i];
		else
			break;
	}
	if(i>r) return ret;
	ll=i;
	for(; i<=r; i++)
	{
		if(s[i]=='(')
			t--;
		else if(s[i]==')')
			t++;
		else if(s[i]=='+'||s[i]=='-')
			fh++;
		if(t==0)
			break;
	}
	rr=i;
	if(ll==l||s[ll-1]=='+'||fh==0)
		return ret+dfs(ll+1,rr-1)+dfs(rr+1,r);
	else
		return ret+"("+dfs(ll+1,rr-1)+")"+dfs(rr+1,r);
}

int main()
{
	int t;
	scanf("%d",&t);
	getchar();
	for(; t--;)
	{
		gets(s);
		int l=strlen(s),nl=0;
		for(int i=0; i<l; i++)
		{
			if(s[i]==' ')
				continue;
			else
				s[nl++]=s[i];
		}
		l=nl;
		s[l]='\0';
		cout<<dfs(0,l-1)<<endl;
	}
	return 0;
}
