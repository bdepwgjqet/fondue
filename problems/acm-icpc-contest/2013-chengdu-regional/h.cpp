#include <cstdio>
#include <cstring>
#include <string>
#include <map>

using namespace std;

char arr[20][20]={"B","KB","MB","GB","TB","PB","EB","ZB","YB"};
map<string,int> mp;

int main() {
	int T;
	scanf("%d",&T);
	mp.clear();
	for(int i=0; i<9; i++) {
		mp[string(arr[i])]=i;
	}
	for(int ca=1; ca<=T; ca++) {
		printf("Case #%d: ",ca);
		int x;
		char s[100];
		scanf("%d[%s]",&x,s);
		s[strlen(s)-1]=0;
		double ret=1.0;
		int n=mp[string(s)];
		for(int i=0; i<n; i++) {
			ret*=1000;
			ret/=1024;
		}
		printf("%.2lf%%\n",(1-ret)*100);
	}
	return 0;
}
