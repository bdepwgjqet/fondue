/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  03/16/2012 11:20:10 PM
 ***/

#include <cstring>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>
#define MAXN 1010000
#define MAXM 1000010
#define MOD 1000000007

typedef long long LL;
using namespace std;

inline int L(int i){ return i<<1; }
inline int R(int i){ return (i<<1)|1; }
inline int max(int a,int b){ return a<b?b:a; }
inline int min(int a,int b){ return a<b?a:b; }
inline int abs(int x){ return x<0?-x:x; }

char s[MAXN];
int dat[MAXN],next[MAXN];

int main()
{
	int len,k,i,x,l,r;
	LL ret,a,b,ttt,t;
	while(scanf("%d%s",&k,s)!=EOF)
	{
		ret=0;
		len=strlen(s);
		dat[0]=0;
		for(ttt=t=i=0; i<len; i++)
		{
			if(s[i]=='1')
			{
				dat[i+1]=dat[i]+1;
				//cout<<t<<"=>"<<endl;
				ttt+=t*(t+1)/2;
				//cout<<ttt<<"=>"<<endl;
				t=0;
			}
			else
			{
				t++;
				dat[i+1]=dat[i];
			}
		}
		ttt+=t*(t+1)/2;
				//cout<<ttt<<"=>"<<endl;
		x=len+1;
		for(i=len-1; i>=0; i--)
		{
			if(s[i]=='1')
				next[i+1]=x,x=i+1;
			else
				next[i+1]=x;
		}
		next[len+1]=len+1;
		for(r=1; r<=len; r++)
			if(dat[r]>=k)
				break;
		for(l=1; l<=len; l++)
			if(s[l-1]=='1')
				break;
		if(r>len)
			ret=0;
		else if(k==0)
			ret=ttt;
		else
		{
			x=0;
			for(; r<=len; )
			{
				a=next[r]-r;
				b=l-x;
				x=l;
				r=next[r];
				l=next[l];
				//cout<<a<<" "<<b<<" "<<endl;
				ret+=a*b;
			}
		}
		cout<<ret<<endl;
	}
	return 0;
}
