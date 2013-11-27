#include <cstdio>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#define N 500

using namespace std;

int n,m,top;
map<string,int> mp;
map<string,int> ani;
map<int,string> ati;
set<int> st[N];
set<int> ans;
set<int>::iterator it;
vector<string> vec;

set<int> gao(set<int> a,set<int> b)
{
	set<int> ret;
	for(it=b.begin(); it!=b.end(); it++)
		if(a.count(*it))
			ret.insert(*it);
	return ret;
}

int main()
{
	while(scanf("%d",&n)+1)
	{
		string s,ts;
		top=0;
		for(int i=0; i<n; i++)
			st[i].clear();
		mp.clear();
		ani.clear();
		ati.clear();
		ans.clear();
		for(int i=0; i<n; i++)
		{
			cin>>s;
			getchar();
			ani[s]=i;
			getline(cin,s);
			istringstream is(s);
			while(is>>ts)
			{
				if(mp.count(ts)<=0) 
				{
					ati[top]=ts;
					mp[ts]=top++;
				}
				st[i].insert(mp[ts]);
			}
		}
		scanf("%d",&m);
		getchar();
		for(int i=0; i<m; i++)
		{
			getline(cin,s);
			istringstream is(s);
			is>>ts;
			int id=ani[ts];
			ans=st[id];
			while(is>>ts)
			{
				id=ani[ts];
				ans=gao(ans,st[id]);
			}
			if(ans.size()>0)
			{
				vec.clear();
				for(it=ans.begin(); it!=ans.end(); it++)
				{
					vec.push_back(ati[*it]);
				}
				sort(vec.begin(),vec.end());
				cout<<vec[0];
				for(int i=1; i<vec.size(); i++)
					cout<<" "<<vec[i];
				puts("");
			}
			else
				puts("NO");
		}
	}
	return 0;
}
