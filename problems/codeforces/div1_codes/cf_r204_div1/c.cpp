#include <cstdio>
#include <iostream>
#include <algorithm>

#define N 33
#define inf 0x3fffffff

using namespace std;
typedef long long LL;

int dpc[N][N],dpo[N][N];
int cl[N],op[N],dif[N];

LL gao(int cnt,int m,int n) {
	LL ret=0;
	for(int i=0; i<n; i++) {
		int x=min(m,cnt);
		ret=ret+dif[i]*x;
		cnt-=x;
	}
	for(int i=0; i<n; i++) {
		ret=ret+cl[i]*m;
	}
	return ret;
}

int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0; i<n; i++) {
		scanf("%d",&op[i]);
	}
	for(int i=0; i<n; i++) {
		scanf("%d",&cl[i]);
	}
	for(int i=0; i<n; i++) {
		dif[i]=op[i]-cl[i];
	}
	sort(dif,dif+n);
	for(int i=0; i<=n+1; i++) {
		for(int j=0; j<=n+1; j++) {
			dpc[i][j]=dpo[i][j]=inf;
		}
	}
	dpo[0][0]=0;
	for(int i=1; i<=n; i++) {
		for(int j=0; j<n+1; j++) {
			if(j>0)
				dpo[i][j]=min(dpo[i][j],dpo[i-1][j-1]+op[i-1]);
			dpo[i][j]=min(dpo[i][j],dpo[i-1][j+1]+cl[i-1]);
		}
	}
	dpc[0][0]=0;
	for(int i=1; i<=n; i++) {
		for(int j=0; j<n+1; j++) {
			if(j>0) {
				dpc[i][j]=min(dpc[i][j],dpc[i-1][j-1]+cl[n-i]);
			}
			dpc[i][j]=min(dpc[i][j],dpc[i-1][j+1]+op[n-i]);
		}
	}
	LL ret=(1LL<<61);
	for(int i=0; i<n+1; i++) {
		for(int j=0; j<n+1; j++) {
			if(dpo[n][i]<inf && dpc[n][j]<inf) {
				LL tmp=dpo[n][i]+dpc[n][j];
				int cnt=m*n/2-(n-i)/2-(n-j)/2-i;
				if(cnt>=0 && cnt<=(m-2)*n)
					ret=min(ret,tmp+gao(cnt,m-2,n));
			}
		}
	}
	cout<<ret<<endl;
}
