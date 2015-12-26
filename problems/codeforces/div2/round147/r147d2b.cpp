/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  10/25/2012 11:25:11 PM
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
#define N 111
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

int mat[N][N],id[10101],c[N];
vector<pii> ans;

int main()
{
	int n;
	while(scanf("%d",&n)+1)
	{
		ans.clear();
		for(int i=1; i<=n; i++)
			scanf("%d",&c[i]);
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=c[i]; j++)
			{
				scanf("%d",&mat[i][j]);
				id[mat[i][j]]=i*N+j;
			}
		}
		int now=1;
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=c[i]; j++)
			{
				if(mat[i][j]!=now)
				{
					int x=id[now],y=x%N;
					x=x/N;
					swap(mat[x][y],mat[i][j]);
					id[mat[x][y]]=x*N+y;
					id[mat[i][j]]=i*N+j;
					ans.push_back(make_pair(i*N+j,x*N+y));
					now++;
				}
				else now++;
			}
		}
		printf("%d\n",ans.size());
		for(int i=0; i<ans.size(); i++)
		{
			int x=ans[i].first,y=ans[i].second;
			printf("%d %d %d %d\n",x/N,x%N,y/N,y%N);
		}
	}
	return 0;
}
