#include <cstdio>
#include <utility>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;
const int N = 100010;

vector<int> tr[N];
queue<pair<int,int> > q;
string s[N];
string ms;
int f[3*N];

void cr_fail() {
	f[0]=-1;
	for(int i=1; i<ms.length(); i++) {
		int p=f[i-1];
		while(p!=-1&&ms[p+1]!=ms[i])
			p=f[p];
		if(ms[p+1]==ms[i])
			f[i]=p+1;
		else
			f[i]=-1;
	}
}

int main() {
	int n;
	scanf("%d",&n);
	for(int i=1; i<n; i++) {
		int x;
		scanf("%d",&x);
		x--;
		tr[x].push_back(i);
		cin>>s[i];
	}
	cin>>ms;
	cr_fail();
	q.push(make_pair(0,0));
	int ret=0;
	for(; !q.empty();) {
		int now=q.front().first;
		int id=q.front().second;
		q.pop();
		for(int i=0; i<tr[now].size(); i++) {
			int to=tr[now][i];
			int ii=id;
			for(int j=0; j<s[to].length(); j++) {
				int pi=ii-1;
				for(; pi>=0&&s[to][j]!=ms[pi+1];)
					pi=f[pi];
				if(pi<0) {
					ii=0;
					if(s[to][j]==ms[ii])
						ii++;
				}
				else 
					ii=pi+1+1;
				if(ii>=ms.length()) {
					ii=f[ms.length()-1]+1;
					ret++;
				}
			}
			q.push(make_pair(to,ii));
		}
	}
	printf("%d\n",ret);
	return 0;
}
