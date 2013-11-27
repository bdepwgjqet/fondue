#include <cstdio>
#include <utility>
#include <map>
#include <vector>

using namespace std;

const int N = 100010;

vector<int> pl;
map<int,int> lf;
map<int,int> rf;

int p[N];

void init() {
	for(int i=0; i<N; i++)
		p[i]=i;
	pl.clear();
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

void gf(int x,map<int,int> &mp) {
	mp.clear();
	for(int i=0; i<pl.size(); i++) {
		if(x%pl[i]==0) {
			int c=0;
			for(; x%pl[i]==0; x/=pl[i],c++);
			mp[pl[i]]=c;
		}
	}
	if(x>1)
		mp[x]=1;
}

int main() {
	init();
	int T;
	scanf("%d",&T);
	for(int ca=1; ca<=T; ca++) {
		int l,r;
		scanf("%d%d",&l,&r);
		if(r%l!=0) {
			puts("0");
			continue;
		}
		gf(l,lf);
		gf(r,rf);
		map<int,int>::iterator it;
		int ret=1;
		for(it=rf.begin(); it!=rf.end(); it++) {
			int x=it->first,y=it->second,z;
			if(lf.count(x)>0)
				z=lf[x];
			else
				z=0;
			if(z==y)
				continue;
			else
				ret=ret*(6+(y-z-1)*6);
		}
		printf("%d\n",ret);
	}
	return 0;
}
