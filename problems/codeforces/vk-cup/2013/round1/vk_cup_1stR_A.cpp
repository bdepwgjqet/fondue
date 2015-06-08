/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  03/11/2012 10:56:06 PM
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
#define MAXN 100010
#define MAXM 1000010
#define MOD 1000000007

typedef long long LL;
using namespace std;

inline int L(int i){ return i<<1; }
inline int R(int i){ return (i<<1)|1; }
inline int max(int a,int b){ return a<b?b:a; }
inline int min(int a,int b){ return a<b?a:b; }
inline int abs(int x){ return x<0?-x:x; }

LL a[MAXN],b[MAXN];
int ret[MAXN],ans;

int cmp(LL a,LL b){ return a<b; }

int main()
{
	LL n,m,x,y; int i,j;
	while(cin>>n>>m>>x>>y)
	{
		for(i=0; i<n; i++)
			cin>>a[i];
		for(i=0; i<m; i++)
			cin>>b[i];
		sort(a,a+n,cmp);
		sort(b,b+m,cmp);
		memset(ret,0,sizeof(ret));
		for(ans=i=j=0; i<n&&j<m; i++)
		{
			for(; b[j]<a[i]-x&&j<m; j++);
			if(j>=m)	break;
			if(b[j]<=a[i]+y)
				ans++,ret[i]=j+1,j++;
		}
		cout<<ans<<endl;
		for(i=0; i<n; i++)
			if(ret[i]>0)
				cout<<i+1<<" "<<ret[i]<<endl;
	}
	return 0;
}

