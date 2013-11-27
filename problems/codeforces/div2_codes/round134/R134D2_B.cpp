/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  08/19/2012 03:00:49 PM
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

class cmp
{
	public:
	bool operator () (const int &a,const int &b)
	{
		return a<b;
	}
};
class cmp1
{
	public:
	bool operator () (const int &a,const int &b)
	{
		return a>b;
	}
};
priority_queue<int,vector<int>,cmp> q;
priority_queue<int,vector<int>,cmp1> q1;

int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		int x;
		for(int i=0; i<m; i++)
		{
			scanf("%d",&x);
			q.push(x);
			q1.push(x);
		}
		int ret=0,r=0;
		for(int i=0; i<n; i++)
		{
			x=q.top();
			ret+=x;
			q.pop();
			if(x-1>0)
				q.push(x-1);
			x=q1.top();
			r+=x;
			q1.pop();
			if(x-1>0)
				q1.push(x-1);
		}
		printf("%d %d\n",ret,r);
	}
	return 0;
}
