#include <cstdio>

const int N = 110;

int k;
double ps,pr,pi,pu,pw,pd,pl;
double dp[N][N];

double dfs(int x,int y) {
	if(dp[x][y]>=0)
		return dp[x][y];
	if(x>=k) {
		return dp[x][y]=1;
	}
	if(y>=k) {
		return dp[x][y]=0;
	}
	double ret=0;
	double sun=pi+x*pu*pw-y*pd*pl;
	if(sun>1) sun=1;
	if(sun<0) sun=0;
	ret=ret+dfs(x+1,y)*(sun*ps+(1-sun)*pr);
	ret=ret+dfs(x,y+1)*(1-(sun*ps+(1-sun)*pr));
	return dp[x][y]=ret;
}


int main() {
	int T;
	scanf("%d",&T);
	for(int ca=1; ca<=T; ca++) {
		printf("Case #%d: ",ca);
		scanf("%d",&k);
		scanf("%lf%lf%lf%lf%lf%lf%lf",&ps,&pr,&pi,&pu,&pw,&pd,&pl);
		for(int i=0; i<=k; i++)
			for(int j=0; j<=k; j++)
				dp[i][j]=-1;
		printf("%.6lf\n",dfs(0,0));
	}
	return 0;
}
