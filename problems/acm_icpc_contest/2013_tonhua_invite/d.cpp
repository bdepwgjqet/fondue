#include <cstdio>
#include <vector>
#include <utility>

using namespace std;
const int N = 11110;

vector<pair<int,int> > vec;
vector<int> ans;

struct ufind {

	int p[N];

	void init() {}

	void init(int n) {
		for(int i=0; i<n; i++)
			p[i]=i;
	}

	int run(int x) {
		int y=x,t;
		for(; p[x]!=x; x=p[x]);
		for(; p[t=y]!=y; y=p[y],p[t]=x);
		return x;
	}

	int isf(int x,int y) {
		return run(x)==run(y);
	}

	void mf(int x,int y) {
		p[run(x)]=run(y);
	}
}uf;

int main() {
	int n,m;
	while(scanf("%d%d",&n,&m)+1) {
		uf.init(n);
		vec.clear();
		ans.clear();
		for(int i=0; i<m; i++) {
			int x,y;
			scanf("%d%d",&x,&y);
			vec.push_back(make_pair(x,y));
		}
		ans.push_back(n);
		int now=n;
		for(int i=m-1; i>0; i--) {
			int x=vec[i].first;
			int y=vec[i].second;
			if(uf.isf(x,y))
				ans.push_back(now);
			else {
				now--;
				ans.push_back(now);
				uf.mf(x,y);
			}
		}
		for(int i=m-1; i>=0; i--)
			printf("%d\n",ans[i]);
	}
	return 0;
}
