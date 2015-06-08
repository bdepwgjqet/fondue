#include <cstdio>
#include <iostream>
#include <map>
#define N 101000

using namespace std;
typedef long long LL;

int arr[N];
map<int,int> mp;
map<int,int>::iterator it;

int f(int x) {
	if(x==0) return 0;
	if(x&1) return f(x>>1)+1;
	return f(x>>1);
}

int main() {
	int n;
	scanf("%d",&n);
	for(int i=0; i<n; i++) {
		scanf("%d",&arr[i]);
		arr[i]=f(arr[i]);
	}
	for(int i=0; i<n; i++)
		mp[arr[i]]++;
	LL ret=0;
	for(it=mp.begin(); it!=mp.end(); it++) {
		int x=it->second;
		ret=ret+1LL*x*(x-1)/2;
	}
	cout<<ret<<endl;
	return 0;
}
