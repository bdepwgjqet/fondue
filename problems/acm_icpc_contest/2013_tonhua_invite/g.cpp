#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int dp[7][1025];
int mat[7][7];
int n,m;

inline int B(int i) { 
	return 1<<i; 
}

int gnst(int st,int x) {
	if(x==0)
		return st;
	if(x==1) {
		if(st==1)
			return 2;
		if(st==2)
			return 0;
		if(st==3)
			return 2;
		return st;
	}
	if(st==0)
		return 1;
	if(st==1)
		return 3;
	return -1;
}

int gf(int x,int i) {
	int ret=0;
	if(x&B(2*m-1-2*i))
		ret+=2;
	if(x&B(2*m-1-2*i-1))
		ret+=1;
	return ret;
}

void tf(int &st, int x, int i) {
	if(x&2) {
		st|=B(2*m-1-2*i);
	}
	if(x&1) {
		st|=B(2*m-1-2*i-1);
	}
}

int dfs(int id,int st) {
	if(dp[id][st]>=0)
		return dp[id][st];
	if(id==n)
		return dp[id][st]=0;
	int ret=0;
	for(int i=0; i<B(m); i++) {
		int tag=1;
		for(int j=0; j<m&&tag; j++)
			if((i&B(j))&&mat[id][j])
				tag=0;
		if(tag==0)
			continue;
		int now=0;
		for(int j=0; j<m&&tag; j++) {
			if(mat[id][j])
				now=gnst(now,1);
			else if(i&B(j))
				now=gnst(now,2);
			else
				now=gnst(now,0);
			if(now<0)
				tag=0;
		}
		if(tag==0)
			continue;
		int nst=0,c=0;
		for(int j=0; j<m&&tag; j++) {
			if(i&B(j)) {
				int tmp=gnst(gf(st,j),2);
				if(tmp<0) tag=0;
				tf(nst,tmp,j);
				c++;
			}
			else if(mat[id][j]) {
				tf(nst,gnst(gf(st,j),1),j);
			}
			else {
				tf(nst,gnst(gf(st,j),0),j);
			}
		}
		if(tag==0) 
			continue;
		ret=max(ret,dfs(id+1,nst)+c);
	}
	return dp[id][st]=ret;
}

int main() {
	int q;
	while(scanf("%d%d%d",&n,&m,&q)+1) {
		memset(mat,0,sizeof(mat));
		memset(dp,-1,sizeof(dp));
		for(int i=0; i<q; i++) {
			int x,y;
			scanf("%d%d",&x,&y);
			mat[x][y]=1;
		}
		printf("%d\n",dfs(0,0));
	}
	return 0;
}
