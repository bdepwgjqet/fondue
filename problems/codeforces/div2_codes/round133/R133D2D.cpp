/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  08/14/2012 11:26:20 PM
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

int cmp(int a,int b){ return a<b; }

vector<int> mat[1001];
set<int> st;
set<int>::iterator it;

int main()
{
	int n,mx;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0; i<n; i++)
		{
			int x;
			scanf("%d",&x);
			st.clear();
			mat[i].clear();
			for(int j=0; j<x; j++)
			{
				int x;
				scanf("%d",&x);
				st.insert(x);
			}
			int top=1;
			for(it=st.begin(); it!=st.end(); it++)
				mat[i].push_back(*it);
		}
		for(int i=0; i<mat[0].size(); i++)
			mat[n].push_back(mat[0][i]);
		for(int i=0; i<mat[1].size(); i++)
			mat[n+1].push_back(mat[1][i]);
		int ret=0;
		for(int i=1; i<=n; i++) 
		{
			int l=0,r=0,lc,rc;
			for(; l<mat[i-1].size()&&mat[i-1][l]<mat[i][0]; l++);
			for(; r<=mat[i+1].size()&&mat[i+1][r]<mat[i][0]; r++);
			for(int j=1; j<mat[i].size(); j++)
			{
				lc=0,rc=0;
				for(; l<mat[i-1].size()&&mat[i-1][l]<mat[i][j]; l++)
					lc++;
				for(; r<mat[i+1].size()&&mat[i+1][r]<mat[i][j]; r++)
					rc++;
				if(lc!=rc)
				{
					ret++;
				}
			}
		}
		printf("%d\n",ret);
	}
	return 0;
}
