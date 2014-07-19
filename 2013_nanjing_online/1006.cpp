#include <cstdio>
#include <cstring>
#include <algorithm>
#define inf 1000000

using namespace std;

int tag[2][12];
int score[2];
int hash[2][12];
int dp[2][1<<12];
int n;

int B(int i) { 
	return 1<<i; 
}

int add_age(int kind,int id,int st) {
	for(int i=0; i<2; i++) {
		for(int j=0; j<12; j++) {
			if(st&B(12*i+j)) {
				tag[i][j]=1;
			}
			else {
				tag[i][j]=0;
			}
		}
	}
	int ret=0;
	if(kind==0) {
		if(id-3>=0) {
			if(tag[0][id-3]&&tag[1][id-4+id/3]&&tag[1][id-4+id/3+1]) {
				ret++;
			}
		}
		if(id+3<=11) {
			if(tag[0][id+3]&&tag[1][id+id/3]&&tag[1][id+id/3+1]) {
				ret++;
			}
		}
	}
	else {
		if(id-1>=(id/4)*4) {
			if(tag[1][id-1]&&tag[0][id-1-id/4]&&tag[0][id-1-id/4+3]) {
				ret++;
			}
		}
		if(id+1<=(id/4)*4+3) {
			if(tag[1][id+1]&&tag[0][id-id/4]&&tag[0][id-id/4+3]) {
				ret++;
			}
		}
	}
	return ret;
}

int dfs(int c,int st,int i_st) {
	if(dp[c][st]<inf) {
		return dp[c][st];
	}
	if(st==B(24-n)-1) {
		return dp[c][st]=0;
	}
	int ret=inf;
	for(int k=0; k<2; k++) {
		for(int i=0; i<12; i++) {
			if((i_st&B(k*12+i))==0) {
				int v=add_age(k,i,i_st|B(k*12+i));
				if(c==1) {
					v=-v;
				}
				int x=dfs((c+1)%2,st|B(hash[k][i]),i_st|B(k*12+i))+v;
				if(ret==inf) {
					ret=x;
				}
				else {
					if(c==0) {
						ret=max(ret,x);
					}
					else {
						ret=min(ret,x);
					}
				}
			}
		}
	}
	return dp[c][st]=ret;
}


int main() {
	int T;
	scanf("%d",&T);
	for(int ca=1; ca<=T; ca++) {
		int i_st=0;
		printf("Case #%d: ",ca);
		memset(score,0,sizeof(score));
		scanf("%d",&n);
		for(int i=0; i<n; i++) {
			int x,y;
			scanf("%d%d",&x,&y);
			x--,y--;
			if(abs(y-x)==1) {
				score[i%2]+=add_age(0,min(x,y)-min(x,y)/4,i_st);
				i_st|=B(min(x,y)-min(x,y)/4);
			}
			else {
				score[i%2]+=add_age(1,min(x,y),i_st);
				i_st|=B(12+min(x,y));
			}
		}
		int c=0;
		memset(hash,-1,sizeof(hash));
		for(int i=0; i<2; i++)
			for(int j=0; j<12; j++) {
				if((i_st&B(i*12+j))==0) {
					hash[i][j]=c++;
				}
			}
		for(int i=0; i<2; i++) {
			for(int j=0; j<B(12); j++) {
				dp[i][j]=inf;
			}
		}
		int del=dfs(n%2,0,i_st)+score[0]-score[1];
		if(del>0) {
			puts("Tom200");
		}
		else {
			puts("Jerry404");
		}
	}
}
