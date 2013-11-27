#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long LL;
const int N = 200010;

struct node {
	LL x,y;
	node(){}
	node(LL xx,LL yy):x(xx),y(yy){}
	node operator+(node a) {
		return node(x+a.x,y+a.y);
	}
	node operator-(node a) {
		return node(x-a.x,y-a.y);
	}
}no[N],sum[N];

int q[N],mx[N],mi[N];

LL xmult(node a,node b) {
	return a.x*b.y-b.x*a.y;
}

vector<int> ans;

int cmp(node a,node b) {
	return a.y*b.x<b.y*a.x;
}

int main() {
	int n;
	while(scanf("%d",&n)+1) {
		if(n==0) break;
		for(int i=0; i<n; i++) {
			scanf("%lld%lld",&no[i].y,&no[i].x);
			//cin>>no[i].y>>no[i].x;
		}
		sort(no,no+n,cmp);
		sum[n-1]=no[n-1];
		for(int i=n-2; i>=0; i--) {
			sum[i]=sum[i+1]+no[i];
		}
		int l=0,r=-1;
		for(int i=0; i<n-1; i++) {
			for(; l<=r && no[q[r]].x>=no[i].x; r--);
			for(; l<=r-1 && xmult(node(no[i]-no[q[r]]),node(no[q[r]]-no[q[r-1]]))<=0; r--);
			q[++r]=i;
			for(; l<=r-1 && xmult(sum[i+1],node(no[q[r]]-no[q[r-1]]))<=0; r--);
			mx[i]=q[r];
		}
		l=0,r=-1;
		ans.clear();
		for(int i=n-2; i>=0; i--) {
			for(; l<=r && no[q[r]].x<=no[i+1].x; r--);
			for(; l<=r-1 && xmult(node(no[i+1]-no[q[r]]),node(no[q[r]]-no[q[r-1]]))<=0; r--);
			q[++r]=i+1;
			for(; l<=r-1 && xmult(sum[i+1],node(no[q[l]]-no[q[l+1]]))>=0; l++);
			mi[i]=q[l];
			if(xmult(sum[i+1],no[mx[i]]-no[mi[i]])>0) {
				ans.push_back(i+1);
			}
		}
		printf("%d\n",ans.size());
		for(int i=ans.size()-1; i>=0; i--) {
			printf("%d\n",ans[i]);
		}
	}
	return 0;
}
