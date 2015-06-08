/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  09/19/2012 11:49:30 PM
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
struct node{ int x,y; }no[N];

int six[8];

int ok(int n,int now)
{
	int x,y;
	memset(six,0,sizeof(six));
	x=no[0].x,y=no[0].y;
	if(x==y) return 0;
	six[x]=six[y]=1;
	if(six[7-x]||six[7-y])
		return 0;
	six[7-x]=1,six[7-y]=1;
	if(six[now])
		return 0;
	six[now]=1;
	int id=-1;
	for(int i=1; i<=6; i++)
		if(six[i]==0)
		{
			id=i;
			break;
		}

	for(int i=1; i<n; i++)
	{
		memset(six,0,sizeof(six));
		int x,y;
		x=no[i].x,y=no[i].y;
		if(x==y) return 0;
		six[x]=1,six[y]=1;
		if(six[7-x]||six[7-y])
			return 0;
		six[7-x]=1,six[7-y]=1;
		if(six[id])
			return 0;
	}
	return 1;
}

int main()
{
	int n,now;
	while(scanf("%d",&n)!=EOF)
	{
		scanf("%d",&now);
		for(int i=0; i<n; i++)
			scanf("%d%d",&no[i].x,&no[i].y);
		if(ok(n,now))
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
