#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <utility>
#include <vector>

using namespace std;
typedef long long LL;

const int N = 200011;

struct point {
	int x,y;

	point(){}
	point (int x,int y):x(x),y(y){}

	bool operator < (const point &a) const {
		return a.x==x?y<a.y:x<a.x;
	}

	bool operator == (const point &a) const {
		return x==a.x && y==a.y;
	}
}st;

set<point> st;
vector<point> vec[2][N];
LL ret;

int dd[4][2]={{1,-1},{-1,1},{1,1},{-1,-1}};

void go(int x,int y,int d) {
	int tg;
	if(d&2) tg=1;
	else tg=0;
}

int main() {
	int n,m,p;
	while(scanf("%d%d%d",&n,&m,&p)+1) {
		for(int i=0; i<2; i++)
			for(int j=0; j<m+n+3; j++)
				vec[i][j].clear();
		for(int i=0; i<p; i++) {
			int x,y;
			scanf("%d%d",&x,&y);
			st.insert(point(x,y));
		}
		for(int i=0; i<=m+1; i++) {
			st.insert(point(i,0));
			st.insert(point(i,n+1));
		}
		for(int i=0; i<=n+1; i++) {
			st.insert(point(0,i));
			st.insert(point(m+1,i));
		}
		for(set<point>::iterator it=st.begin(); it!=st.end(); it++) {
			int x=it->x,y=it->y;
			vec[x+y].push_back(point(x,y));
			vec[m+1-x+y].push_back(point(x,y));
		}
		for(int i=0; i<2; i++) {
			for(int j=0; j<m+n+3; j++) {
				sort(vec[i][j].begin(),vec[i][j].end());
			}
		}
		char dirs[10];
		scanf("%d%d%s",&st.x,&st.y,dirs);
		int dir;
		if(strcmp(dirs,"NE")==0)
			dir=1;
		else if(strcmp(dirs,"NW")==0)
			dir=3;
		else if(strcmp(dirs,"SE")==0)
			dir=2;
		else if(strcmp(dirs,"SW")==0)
			dir=0;
		ret=0;
		go(st.x,st.y,dir);
		go(st.x,st.y,dir^1);
		cout<<ret/2<<endl;
	}
	return 0;
}
