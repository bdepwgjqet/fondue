/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  08/19/2012 06:53:46 PM
 ***/

#include <cstring>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <sstream>
#include <cmath>
#include <functional>
#include <iostream>
#include <algorithm>
#define N 1010
#define M 1000010
#define S 1000100
#define eps 1e-8
#define inf 0x3fffffff
#define MOD 1000000007
#define PB push_back
#define MP make_pair
#define SZ(a) ((int)((a).size()))
#define ALL(a) (a).begin(),(a).end()
#define CLR(a,x) memset(a,x,sizeof(a))

typedef long long LL;
using namespace std;

char s[N];

void get_alf(int x)
{
	if(x==0)
		return;
	if(x>26)
		get_alf((x-1)/26);
	printf("%c",'A'+(x-1)%26);
}

void show(int l)
{
	int c=-1,x;
	for(int i=0; i<l; i++)
		if(s[i]=='C')
		{
			c=i;
			break;
		}
	if(s[0]=='R'&&s[1]<='9'&&c>0)
	{
		x=0;
		for(int i=c+1; i<l; i++)
			x*=10,x+=s[i]-'0';
		get_alf(x);
		x=0;
		for(int i=1; i<c; i++)
			x*=10,x+=s[i]-'0';
		printf("%d\n",x);
	}
	else
	{
		printf("R");
		for(int i=0; i<l; i++)
			if(s[i]<='9')
			{
				c=i;
				break;
			}
		x=0;
		for(int i=c; i<l; i++)
			x*=10,x+=s[i]-'0';
		printf("%dC",x);
		x=0;
		for(int i=0; i<c; i++)
			x*=26,x+=s[i]-'A'+1;
		printf("%d\n",x);
	}
}

int main()
{
	int n,l;
	scanf("%d",&n);
	for(int i=0; i<n; i++)
	{
		scanf("%s",s);
		l=strlen(s);
		show(l);
	}
	return 0;
}
