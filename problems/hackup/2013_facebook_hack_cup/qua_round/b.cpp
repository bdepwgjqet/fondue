#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

struct node {
	string name;
	int h,p,on,ont,rt;
	node(){}
	node(string name,int p,int h):name(name),p(p),h(h) {
		on=ont=rt=0;
	}
};

int n,m,p;

vector<node> vec[2];
vector<node> tv;
vector<string> ans;

int cmp(node a,node b) {
	return a.p==b.p?a.h>b.h:a.p>b.p;
}

int cmp1(node a,node b) {
	if(a.on!=b.on)
		return a.on>b.on;
	return a.ont==b.ont?a.rt<b.rt:a.ont<b.ont;
}

void go(int id) {
	for(int i=0; i<p; i++) {
		vec[id][i].on=1;
		vec[id][i].ont=1;
	}
	for(int i=0; i<m; i++) {
		sort(vec[id].begin(),vec[id].end(),cmp1);
		/*
		for(int j=0; j<vec[id].size(); j++)
			printf("%d ",vec[id][j].on);
		puts("");

		for(int j=0; j<vec[id].size(); j++)
			cout<<vec[id][j].name<<" ";
		puts("");
		*/
		if(vec[id].size()>p) {
			vec[id][p-1].on=0;
			vec[id][p].on=1;
			vec[id][p].ont++;
		}
		else
			vec[id][p-1].ont++;
		for(int j=0; j<p-1; j++)
			vec[id][j].ont++;
	}
	sort(vec[id].begin(),vec[id].end(),cmp1);
}

int main() {
	int T;
	scanf("%d",&T);
	for(int ca=1; ca<=T; ca++) {
		printf("Case #%d: ",ca);
		scanf("%d%d%d",&n,&m,&p);
		tv.clear();
		for(int i=0; i<2; i++)
			vec[i].clear();
		for(int i=0; i<n; i++) {
			string s;
			int x,y;
			cin>>s>>x>>y;
			tv.push_back(node(s,x,y));
		}
		sort(tv.begin(),tv.end(),cmp);
		for(int i=0; i<n; i++)
			vec[i&1].push_back(tv[i]);
		for(int i=0; i<2; i++)
			for(int j=0; j<vec[i].size(); j++)
				vec[i][j].rt=j;
		for(int i=0; i<2; i++)
			go(i);
		ans.clear();
		for(int i=0; i<p; i++) {
			ans.push_back(vec[0][i].name);
			ans.push_back(vec[1][i].name);
		}
		sort(ans.begin(),ans.end());
		for(int i=0; i<ans.size(); i++) {
			if(i>0)
				printf(" ");
			cout<<ans[i];
		}
		puts("");
	}
	return 0;
}
