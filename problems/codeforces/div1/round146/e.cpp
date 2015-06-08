#include <cstdio>
#include <map>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#include <ext/hash_map>
using namespace __gnu_cxx;

typedef long long LL;

const int N = 2222;
const int MOD = (1<<30) - 1;

class node {
public:
	int a,b,c;

	node(){}

	node(int aa,int bb,int cc):a(aa),b(bb),c(cc) {
		if(a>b)
			swap(a,b);
		if(a>c)
			swap(a,c);
		if(b>c)
			swap(b,c);
	}

	bool operator<(const node &x) const {
		return a<x.a || (a==x.a && (b<x.b || (b==x.b && c<x.c)));
	}

	bool operator==(const node &x) const {
		return a==x.a&&b==x.b&&c==x.c;
	}

	int operator()(const node &x) const {
		return (x.a*2222+x.b)*2222+x.c;
	}
};

hash_map<node,LL,node> hmp[N];
vector<int> pl;
int p[N];

void init() {
	pl.clear();
	for(int i=0; i<N; i++) 
		p[i]=i;
	for(int i=2; i<N; i++) {
		if(p[i]==i)
			pl.push_back(i);
		for(int j=0; j<pl.size()&&i*pl[j]<N; j++) {
			p[i*pl[j]]=pl[j];
			if(i%pl[j]==0)
				break;
		}
	}
}

LL dfs(int id,const node &x) {
	if(hmp[id].count(x)>0)
		return hmp[id][x];
	if(id==pl.size())
		return 1;
	LL ret=0;
	int a,b,c,i,j,k;
	for(a=x.a,i=0; a; a/=pl[id],i++)
		for(b=x.b,j=0; b; b/=pl[id],j++)
			for(c=x.c,k=0; c; c/=pl[id],k++)
				ret=(ret+1LL*dfs(id+1,node(a,b,c))*(i+j+k+1))&MOD;
	hmp[id][x]=ret;
	return ret; 
}

int main() {
	int a,b,c;
	init();
	reverse(pl.begin(),pl.end());
	scanf("%d%d%d",&a,&b,&c);
	for(int i=0; i<N; i++)
		hmp[i].clear();
	cout<<dfs(0,node(a,b,c))<<endl;
	return 0;
}
