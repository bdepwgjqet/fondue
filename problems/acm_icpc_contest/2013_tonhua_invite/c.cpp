#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

const int N = 1300;

char ts[N][N],mat[N][N];
int pr[N][N],nr[N][N],tmpr[N];
int dp[N][N];

void manacher(string s) {
	tmpr[0]=0;
	int mxr=0,mxi=0;
	for(int i=1; i<s.length(); i++) {
		tmpr[i]=(mxr+mxi>i)?min(mxr+mxi-i,tmpr[2*mxi-i]):0;
		for(; i-tmpr[i]>=0&&i+tmpr[i]<s.length(); tmpr[i]++)
			if(s[i-tmpr[i]]!=s[i+tmpr[i]])
				break;
		tmpr[i]--;
		if(i+tmpr[i]>mxr+mxi) {
			mxr=tmpr[i];
			mxi=i;
		}
	}
}

int getv(int x,int i,int j) {
	if((i+j)&1) return 0;
	if(mat[i][j]=='#')
		return ((x+1)>>1)<<1;
	return 1+((x>>1)<<1);
}

void solve(int m,int n) {
	string s;
	for(int i=0; i<m; i++) {
		s=string("");
		for(int j=0; j<=i&&j<n; j++) {
			s.push_back(mat[i-j][j]);
		}
		manacher(s);
		for(int j=0; j<=i&&j<n; j++) {
			nr[i-j][j]=tmpr[j];
		}
		s=string("");
		for(int j=0; j<m-i&&j<n; j++) {
			s.push_back(mat[i+j][j]);
		}
		manacher(s);
		for(int j=0; j<m-i&&j<n; j++) {
			pr[i+j][j]=tmpr[j];
		}
	}
	for(int i=1; i<n; i++) {
		s=string("");
		for(int j=0; m-1-j>=0 && i+j<n; j++) {
			s.push_back(mat[m-1-j][i+j]);
		}
		manacher(s);
		for(int j=0; m-1-j>=0 && i+j<n; j++) {
			nr[m-1-j][i+j]=tmpr[j];
		}
		s=string("");
		for(int j=0; j<m&&i+j<n; j++) {
			s.push_back(mat[j][i+j]);
		}
		manacher(s);
		for(int j=0; j<m&&i+j<n; j++) {
			pr[j][i+j]=tmpr[j];
		}
	}
	memset(dp,0,sizeof(dp));
	int ret=0;
	for(int i=1; i<m; i++) {
		for(int j=1; j<n; j++) {
			dp[i][j]=(nr[i][j]>dp[i-1][j-1])?dp[i-1][j-1]+1:nr[i][j];
			ret=max(ret,getv(dp[i][j],i,j));
		}
	}
	memset(dp,0,sizeof(dp));
	for(int i=m-2; i>=0; i--) {
		for(int j=n-2; j>=0; j--) {
			dp[i][j]=(nr[i][j]>dp[i+1][j+1])?dp[i+1][j+1]+1:nr[i][j];
			ret=max(ret,getv(dp[i][j],i,j));
		}
	}
	memset(dp,0,sizeof(dp));
	for(int i=m-2; i>=0; i--)
		for(int j=1; j<n; j++) {
			dp[i][j]=(pr[i][j]>dp[i+1][j-1])?dp[i+1][j-1]+1:pr[i][j];
			ret=max(ret,getv(dp[i][j],i,j));
		}
	memset(dp,0,sizeof(dp));
	for(int i=1; i<m; i++)
		for(int j=n-2; j>=0; j--) {
			dp[i][j]=(pr[i][j]>dp[i-1][j+1])?dp[i-1][j+1]+1:pr[i][j];
			ret=max(ret,getv(dp[i][j],i,j));
		}
	printf("%d\n",ret*(ret+1)/2);
}

int main() {
	int T;
	scanf("%d",&T);
	for(int ca=1; ca<=T; ca++) {
		int m,n;
		scanf("%d%d",&m,&n);
		memset(mat,'#',sizeof(mat));
		for(int i=0; i<m; i++) {
			scanf("%s",ts[i]);
			for(int j=0; j<n; j++)
				mat[2*i+1][2*j+1]=ts[i][j];
		}
		solve(2*m+1,2*n+1);
	}
	return 0;
}
