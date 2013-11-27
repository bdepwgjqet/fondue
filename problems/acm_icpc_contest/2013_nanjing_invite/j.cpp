#include <cstdio>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;
typedef long long LL;

const int N = 100100;

int arr[N],A[N],B[N];
LL SA[N],SB[N];
map<int,int> mp;
map<string,int> smp;

int dig_count(int x) {
	if(x==0) return 1;
	int ret=0;
	for(; x; x/=10)
		ret++;
	return ret;
}

LL comb(int n) {
	if(n<0) return 0;
	return 1LL*n*(n-1)/2;
}

void gen_index(int A[],LL SA[],int cnt,int n) {
	SA[0]=0;
	int pos=1;
	LL pair=0;
	mp.clear();
	for(int i=1; i<=n; i++) {
		mp[arr[i]]++;
		pair=pair+comb(mp[arr[i]])-comb(mp[arr[i]]-1);
		for(; pair>=cnt && pos<=i;) {
			A[pos]=i;
			pair=pair-comb(mp[arr[pos]])+comb(mp[arr[pos]]-1);
			mp[arr[pos]]--;
			pos++;
		}
	}
	for(; pos<=n; pos++) {
		A[pos]=n+1;
	}
	for(int i=1; i<=n; i++) {
		SA[i]=SA[i-1]+A[i]-i;
	}
}

LL cal(int A[],LL SA[],int l,int r,int n) {
	int pos=upper_bound(A,A+n,r)-A-1;
	if(pos<l) return 0;
	return 1LL*(r-l+1+r-pos+1)*(pos-l+1)/2-SA[pos]+SA[l-1];
}

LL solve(int l,int r,int n) {
	return cal(A,SA,l,r,n)-cal(B,SB,l,r,n);
}

int main() {
	int m,n;
	while(scanf("%d%d",&n,&m)+1) {
		int now=1;
		smp.clear();
		for(int i=1; i<=n; i++) {
			int x;
			scanf("%d",&x);
			string tmps=string("");
			for(; x; x/=10) {
				tmps.push_back('0'+x%10);
			}
			sort(tmps.begin(),tmps.end());
			if(smp.count(tmps)>0)
				arr[i]=smp[tmps];
			else {
				smp[tmps]=now++;
				arr[i]=smp[tmps];
			}
		}
		gen_index(A,SA,1,n);
		gen_index(B,SB,2,n);
		LL k=0;
		for(int i=0; i<m; i++) {
			LL l,r;
			scanf("%I64d%I64d",&l,&r);
			l=l+k;
			r=r-k;
			k=solve(l,r,n);
			printf("%I64d\n",k);
		}
	}
	return 0;
}
