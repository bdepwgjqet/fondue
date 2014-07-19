#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 50;

char s[N][N];

int cnt[N][N][N][N],ri[N][N],dn[N][N];
int dp[N][N][N][N],sum[N][N][N][N],ttl[N][N][N][N];

int main() {
	int n,m,q;
	while(scanf("%d%d%d",&n,&m,&q)+1) {
		for(int i=1; i<=n; i++) {
			scanf("%s",s[i]+1);
		}
		memset(cnt,0,sizeof(cnt));
		memset(dp,0,sizeof(dp));
		memset(ri,0,sizeof(ri));
		memset(sum,0,sizeof(sum));
		memset(ttl,0,sizeof(ttl));
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m; j++) {
				if(j==1) ri[i][j]=0;
				else {
					if(s[i][j-1]=='0') ri[i][j]=ri[i][j-1]+1;
					else ri[i][j]=0;
				}
			}
		}
		for(int i=1; i<=m; i++)
			for(int j=n; j>=1; j--) {
				if(s[j][i]=='1') {
					dn[j][i]=j;
					continue;
				}
				if(j==n) dn[j][i]=n;
				else {
					dn[j][i]=(s[j+1][i]=='1')?j:dn[j+1][i];
				}
			}
		for(int i=1; i<=m; i++) {
			for(int k=1; k<=i; k++) {
				for(int j=1; j<=n; j++) {
					if(s[j][i]=='1') continue;
					int now=min(ri[j][i],i-k);
					for(int u=j; u<=dn[j][i]; u++) {
						now=min(now,min(ri[u][i],i-k));
						cnt[j][k][i][u]=now;
						if(u>j) sum[j][k][i][u]+=sum[j][k][i][u-1]+cnt[j][k][i][u]+1;
						else sum[j][k][i][u]=cnt[j][k][i][u]+1;
					}
				}
			}
		}
		for(int i=1; i<=m; i++) {
			for(int k=1; k<=i; k++) {
				for(int j=1; j<=n; j++) {
					if(s[j][i]=='1') continue;
					for(int u=j; u<=dn[j][i]; u++) {
						for(int v=j; v<=u; v++) {
							ttl[j][k][i][u]+=sum[v][k][i][u];
						}
					}
				}
			}
		}
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m; j++) {
				for(int u=i; u<=n; u++) {
					for(int v=i; v<=u; ) {

						int x=min(dn[v][j],u);
						int y=(s[v][j]=='1')?0:x-v+1;
						dp[i][j][u][j]+=y*(y-1)/2+y;
						v=x+1;
					}
					for(int v=j+1; v<=m; v++) {
						dp[i][j][u][v]=dp[i][j][u][v-1];
						for(int k=i; k<=u;) {
							int x=min(dn[k][v],u);
							if(k==x&&s[k][v]=='1') {
								k=x+1;
								continue;
							}
							dp[i][j][u][v]+=ttl[k][j][v][x];
							k=x+1;
						}
					}
				}
			}
		}
		for(int i=0; i<q; i++) {
			int x,y,u,v;
			scanf("%d%d%d%d",&x,&y,&u,&v);
			printf("%d\n",dp[x][y][u][v]);
		}
	}
	return 0;
}
