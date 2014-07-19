#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>

typedef long long LL;
using namespace std;

const int N = 511;

int v[N][N],s[N][N],d[N],nx[N],sum[N][N],mxl[N][N],mxlc[N][N],mxr[N][N],mxrc[N][N];

int main() {
	int m,n,r;
	while(scanf("%d%d%d",&m,&n,&r)+1) {
		for(int i=1; i<=m; i++) {
			s[i][0]=0;
			for(int j=1; j<=n; j++) {
				scanf("%d",&v[i][j]);
				s[i][j]=s[i][j-1]+v[i][j];
			}
		}
		for(int i=0; i<=r; i++) {
			int j=0;
			for(; j<=r; j++)
				if(i*i+j*j>r*r)
					break;
			d[i]=j-1;
		}
		for(int i=0; i<2*r+1; i++) {
			int now=0;
			for(int j=0; j<=r&&j<=i; j++) {
				if(i-j>r) continue;
				now=max(now,d[j]+d[i-j]+1);
			}
			nx[i]=now;
		}
		for(int i=r+1; i<=m-r; i++) {
			mxl[i][r]=0;
			mxlc[i][r]=0;
			mxr[i][n-r+1]=0;
			mxrc[i][n-r+1]=0;
			for(int j=r+1; j<=n-r; j++) {
				sum[i][j]=0;
				for(int k=-r; k<=r; k++) {
					sum[i][j]+=s[i+k][j+d[abs(k)]]-s[i+k][j-d[abs(k)]-1];
				}
				if(sum[i][j]>mxl[i][j-1]) {
					mxl[i][j]=sum[i][j];
					mxlc[i][j]=1;
				} else if(sum[i][j]==mxl[i][j-1]) {
					mxl[i][j]=mxl[i][j-1];
					mxlc[i][j]=mxlc[i][j-1]+1;
				} else {
					mxl[i][j]=mxl[i][j-1];
					mxlc[i][j]=mxlc[i][j-1];
				}
			}
			for(int j=n-r; j>=r+1; j--) {
				if(sum[i][j]>mxr[i][j+1]) {
					mxr[i][j]=sum[i][j];
					mxrc[i][j]=1;
				} else if(sum[i][j]==mxr[i][j+1]) {
					mxr[i][j]=mxr[i][j+1];
					mxrc[i][j]=mxrc[i][j+1]+1;
				} else {
					mxr[i][j]=mxr[i][j+1];
					mxrc[i][j]=mxrc[i][j+1];
				}
			}
		}
		LL ret=0,rc=0;
		for(int i=r+1; i<=m-r; i++) {
			for(int j=r+1; j<=n-r; j++) {
				for(int k=r+1; k<=m-r; k++) {
					int now;
					if(abs(k-i)>2*r) {
						now=sum[i][j]+mxr[k][r+1];
						if(ret<now) {
							ret=now;
							rc=mxrc[k][r+1];
						} else if(ret==now) {
							rc+=mxrc[k][r+1];
						}
					} else {
						int y=j+nx[abs(k-i)];
						if(y<=n-r) {
							now=sum[i][j]+mxr[k][y];
							if(ret<now) {
								ret=now;
								rc=mxrc[k][y];
							} else if(ret==now) {
								rc+=mxrc[k][y];
							}
						}
						y=j-nx[abs(k-i)];
						if(y>=r+1) {
							now=sum[i][j]+mxl[k][y];
							if(ret<now) {
								ret=now;
								rc=mxlc[k][y];
							} else if(ret==now) {
								rc+=mxlc[k][y];
							}
						}
					}
				}
			}
		}
		cout<<ret<<" "<<rc/2<<endl;
	}
	return 0;
}
