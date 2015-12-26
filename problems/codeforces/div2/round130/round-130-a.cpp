/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  07/23/2012 11:12:32 PM
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
#define N 100010
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

char s[N],ret[N];
int tag[N];

void solve(int l)
{
	int t,ll;
	memset(tag,0,sizeof(tag));
	for(int i=0; i<l; )
	{
		if(i+2<l)
		{
			if(s[i]=='W'&&s[i+1]=='U'&&s[i+2]=='B')
			{
				tag[i]=1,tag[i+1]=1,tag[i+2]=1;
				i+=3;
				continue;
			}
			i++;
			continue;
		}
		i++;
	}
	int k;
	for(k=l-1; k>=0; k--)
		if(tag[k]==0)
			break;
	ll=k+1;
	t=0;
	for(int i=0; i<ll; i++)
	{
		if(tag[i])
		{
			if(t==1)
				printf(" ");
			t=0;
			continue;
		}
		t=1;
		printf("%c",s[i]);
	}
}

int main()
{
	int l;
	while(scanf("%s",s)!=EOF)
	{
		l=strlen(s);
		solve(l);
		puts("");
	}
	return 0;
}
