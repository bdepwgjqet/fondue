/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  03/27/2012 10:37:58 PM
 ***/

#include <cstring>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cmath>
#include <iostream>
#include <algorithm>
#define N 6100000
#define M 1000010
#define S 1000100
#define MOD 1000000007

typedef long long LL;
using namespace std;

char s[N],ret[N];
int top,l,pre;

inline int L(int i){ return i<<1; }
inline int R(int i){ return (i<<1)|1; }
inline int B(int i){ return 1<<i; }
inline int low_bit(int x){ return x&(-x); }

int amp()
{
	for(int i=0; i<l; i++)
	{
		if(s[i]==' ')
			continue;
		else if(s[i]=='#')
			return 1;
		else	return 0;
	}
	return 0;
}

void solve()
{
	for(int i=0; i<l; i++)
	{
		if(s[i]==' '||s[i]=='\t'||s[i]=='\v')
			continue;
		ret[top++]=s[i];
	}
}

void show()
{
	ret[top]='\0';
	printf("%s\n",ret);
}

int main()
{
	top=0,pre=0;
	while(gets(s)!=NULL)
	{
		l=strlen(s);
		if(amp())
		{
			if(pre)
				show();
			printf("%s\n",s);
			pre=0;
			top=0;
		}
		else
		{
			solve();
			pre=1;
		}
	}
	if(pre)
		show();
	return 0;
}


