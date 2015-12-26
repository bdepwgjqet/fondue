#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
typedef long long LL;

const int N = 100111;

LL pos[N],S,T,dp[51][N][2],retk,retm;
int rk[2][N],n,m,tmp[N],nrk[N],sum[N];

inline LL B(int i) {
	return 1LL<<i;
}

void solve(LL up) {
	for(int i=0; i<=m; i++)
		for(int j=0; j<=n; j++)
			dp[i][j][0]=dp[i][j][1]=0;
	dp[0][0][0]=1;
	for(int i=0; i<n; i++)
		rk[0][i]=i;
	for(int i=1; i<=m; i++) {
		int now=i&1,pre=now^1,top=0;
		sum[0]=0;
		for(int j=0; j<n; j++) {
			if(pos[rk[pre][j]]&B(i-1)) {
				rk[now][top++]=rk[pre][j];
				sum[j+1]=sum[j]+1;
			}
			else {
				sum[j+1]=sum[j];
			}
		}
		for(int j=0; j<n; j++)
			if((pos[rk[pre][j]]&B(i-1))==0)
				rk[now][top++]=rk[pre][j];
		for(int j=0; j<=n; j++) {
			//0
			int nowst=((j-sum[j])+(sum[n]-sum[j]))&1,nx=sum[j];
			int sst=(S&B(i-1))>0?1:0;
			if(nowst==sst) {
				if((up&B(i-1))==0) {
					dp[i][nx][1]+=dp[i-1][j][1];
					dp[i][nx][0]+=dp[i-1][j][0];
				}
				else {
					dp[i][nx][0]+=dp[i-1][j][0]+dp[i-1][j][1];
				}
			}
			//1
			nowst=(sum[j]+(n-j-(sum[n]-sum[j])))&1;
			nx=j+(sum[n]-sum[j]);
			if(nowst==sst) {
				if((up&B(i-1))==0) {
					dp[i][nx][1]+=dp[i-1][j][0]+dp[i-1][j][1];
				}
				else {
					dp[i][nx][0]+=dp[i-1][j][0];
					dp[i][nx][1]+=dp[i-1][j][1];
				}
			}
		}
	}
	retk=retm=0;
	for(int i=0; i<=n; i++) {
		retm+=dp[m][i][0];
		retk+=dp[m][i][1];
	}
	retk+=retm;
	return ;
}

int main() {
	while(scanf("%d%d%I64d%I64d",&n,&m,&S,&T)+1) {
//	while(scanf("%d%d%lld%lld",&n,&m,&S,&T)+1) {
		LL nows=0;
		for(int i=0; i<n; i++) {
			scanf("%I64d",&pos[i]);
			//scanf("%lld",&pos[i]);
			nows^=pos[i];
		}
		LL k=T/B(m);
		LL up=T%B(m);
		solve(up);
		LL ret=k*retk+retm;
		if(nows==S)
			ret--;
//		printf("%lld\n",ret);
		printf("%I64d\n",ret);
	}
	return 0;
}
