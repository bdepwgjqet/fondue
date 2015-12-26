/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  04/05/2012 06:55:19 PM
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
#define N 1010
#define M 1000010
#define S 1000100
#define MOD 1000000007

typedef long long LL;
using namespace std;

inline int L(int i){ return i<<1; }
inline int R(int i){ return (i<<1)|1; }
inline int B(int i){ return 1<<i; }
inline int low_bit(int x){ return x&(-x); }

char s[N];

int isupper(char x)
{
	return 'A'<=x&&x<='Z';
}

int is2change()
{
	int l=strlen(s);
	for(int i=1; i<l; i++)
		if(!isupper(s[i]))
			return 0;
	return 1;
}

char change(char x)
{
	if(isupper(x))
		return x-'A'+'a';
	return x-'a'+'A';
}

int main()
{
	scanf("%s",s);
	int l=strlen(s);
	if(is2change())
	{
		for(int i=0; i<l; i++)
			printf("%c",change(s[i]));
		puts("");
	}
	else
		puts(s);
	return 0;
}


