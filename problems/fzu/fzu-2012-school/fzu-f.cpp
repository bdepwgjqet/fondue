/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  04/28/2012 01:44:58 PM
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
#define N 10100
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

string s;
int song[N],q[N],top;

int main()
{
	int t,ca,n,m,x,now;
	scanf("%d",&t);
	for(ca=1; ca<=t; ca++)
	{
		top=-1;
		now=1;
		memset(song,0,sizeof(song));
		scanf("%d%d",&n,&m);
		for(int i=0; i<m; i++)
		{
			cin>>s;
			if(s=="PRE")
			{
				if(top<=0)
				{
					now=1;
					q[top=0]=now;
				}
				else
					top--,now=q[top];
				printf("%d\n",now);
			}
			else if(s=="NEXT")
			{
				if(now==n)
					now=n;
				else
					now++;
				if(top<0||q[top]!=now)
					q[++top]=now,song[now]++;
				printf("%d\n",now);
			}
			else
			{
				scanf("%d",&x);
				if(top<0||q[top]!=x)
					q[++top]=x,song[x]++;
				now=x;
				printf("%d\n",x);
			}
		}
	}
	return 0;
}
