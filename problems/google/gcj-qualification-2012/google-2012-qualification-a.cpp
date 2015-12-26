/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  04/14/2012 09:20:55 AM
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

inline int L(int i){ return i<<1; }
inline int R(int i){ return (i<<1)|1; }
inline int B(int i){ return 1<<i; }
inline int low_bit(int x){ return x&(-x); }

char ret[30]="yhesocvxduiglbkrztnwjpfmaq",s[300];

int main()
{
	int t,ca,l;
	/*
	for(int i=0; i<25; i++)
		tag[ret[i]-'a']=1;
	for(int i=0; i<26; i++)
		printf("%d ",tag[i]);
	puts("");
	*/
	scanf("%d",&t);
	getchar();
	for(ca=1; ca<=t; ca++)
	{
		printf("Case #%d: ",ca);
		gets(s);
		l=strlen(s);
		for(int i=0; i<l; i++)
		{
			if(s[i]==' ')
				printf(" ");
			else
				printf("%c",ret[s[i]-'a']);
		}
		puts("");
	}
	return 0;
}
