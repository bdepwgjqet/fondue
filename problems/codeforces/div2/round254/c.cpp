#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1001;

int v[N];

int main() {
	int n,m;
	while(scanf("%d%d",&n,&m)+1) {
		double ret=0;
		for(int i=0; i<n; i++)
			scanf("%d",&v[i]);
		for(int i=0; i<m; i++) {
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			ret=max(ret,1.0*(v[x-1]+v[y-1])/z);
		}
		printf("%.13lf\n",ret);
	}
	return 0;
}
