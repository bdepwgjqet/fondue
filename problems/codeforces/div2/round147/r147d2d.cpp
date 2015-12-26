/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  10/26/2012 01:11:50 AM
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
#define N 101000
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
#define pii pair<int,int>

typedef long long LL;
using namespace std;

vector<int> tr[N];
vector<pii> trs;
vector<pii> ans;
int id;

void dfs(int now,int p,int pre)
{
	for(int i=0; i<tr[now].size(); i++)
	{
		int to=tr[now][i];
		if(to==p) continue;
		trs.push_back(make_pair(now,to));
		if(pre>=0)
			ans.push_back(make_pair(id,pre));
		pre=id;
		id++;
		dfs(to,now,id-1);
	}
}

int main()
{
	int n;
	while(scanf("%d",&n)+1)
	{
		trs.clear();
		ans.clear();
		for(int i=0; i<n; i++)
			tr[i].clear();
		for(int i=0; i<n-1; i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			x--,y--;
			tr[x].push_back(y);
			tr[y].push_back(x);
		}
		id=0;
		dfs(0,-1,-1);
		printf("%d\n",trs.size());
		for(int i=0; i<trs.size(); i++)
			printf("%d %d %d\n",2,trs[i].first+1,trs[i].second+1);
		for(int i=0; i<ans.size(); i++)
			printf("%d %d\n",ans[i].first+1,ans[i].second+1);
	}
	return 0;
}
