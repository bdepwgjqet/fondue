/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  08/19/2012 08:53:45 PM
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

char s[N][N];
int sc[N];
string ret,tmp;
map<string,int> mp;
map<string,int> mpp;
map<string,int>::iterator it;

int main()
{
	int n,r,ii;
	while(scanf("%d",&n)!=EOF)
	{
		r=0;
		mp.clear();
		mpp.clear();
		int x;
		for(int i=0; i<n; i++)
		{
			scanf("%s%d",s[i],&sc[i]);
			tmp=string(s[i]);
			if(mp.count(tmp)>0)
				mp[tmp]+=sc[i];
			else
				mp[tmp]=sc[i];
		}
		for(it=mp.begin(); it!=mp.end(); it++)
		{
			if(it->second>r)
				r=it->second;
		}
		for(int i=0; i<n; i++)
		{
			tmp=string(s[i]);
			if(mpp.count(tmp)>0)
				mpp[tmp]+=sc[i];
			else
				mpp[tmp]=sc[i];
			if(mp[tmp]==r&&mpp[tmp]>=r)
			{
				ret=tmp;
				break;
			}
		}
		cout<<ret<<endl;
	}
	return 0;
}
