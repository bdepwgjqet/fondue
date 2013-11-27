#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

struct node {
	int f,t,l;
	node(int f,int t,int l):f(f),t(t),l(l){}
};

const int N = 100;

int sum[N];

vector<node> vec;
int tag[N][N],te[N*N],n,m;

int main() {
	int T;
	scanf("%d",&T);
	for(int ca=1; ca<=T; ca++) {
		printf("Case #%d:\n",ca);
		scanf("%d%d",&n,&m);
		vec.clear();
		sum[1]=0;
		memset(tag,0,sizeof(tag));
		memset(te,0,sizeof(te));
		for(int i=0; i<n-1; i++) {
			vec.push_back(node(i+1,i+2,i+1));
			te[i+1]=1;
			tag[i+1][i+2]=tag[i+2][i+1]=1;
			sum[i+2]=sum[i+1]+i+1;
		}
		for(int i=n;;i++) {
			if((sum[n]+i)%3==0) {
				tag[n][1]=tag[1][n]=1;
				vec.push_back(node(n,1,i));
				te[i]=1;
				break;
			}
		}
		int ok=1;
		for(int i=n; i<=m; i++) {
			if(te[i]==0) {
				int ok=1;
				for(int u=1; u<n&&ok; u++)
					for(int v=u+2; v<=n&&ok; v++) {
						if(tag[u][v])
							continue;
						if((sum[v]-sum[u])%3==i%3) {
							vec.push_back(node(u,v,i));
							tag[u][v]=tag[v][u]=1;
							ok=0;
						}
					}
			}
		}
		if(vec.size()!=m)
			puts("-1");
		else {
			for(int i=0; i<vec.size(); i++)
				printf("%d %d %d\n",vec[i].f,vec[i].t,vec[i].l);
		}
	}
	return 0;
}
