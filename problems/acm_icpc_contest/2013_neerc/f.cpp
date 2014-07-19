#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;
vector<int> ret;

int main() {
	int n,k,p;
	while(scanf("%d%d%d",&n,&k,&p)+1) {
		ret.clear();
		LL sum=0;
		for(int i=0; i<n-k; i++) {
			ret.push_back(1);
			sum++;
		}
		int pre=1;
		int pc=0;
		for(int i=n-k; i<n; i++) {
			if(100*pc>=p*i) {
				ret.push_back(pre);
				sum+=pre;
			}
			else {
				pre++;
				ret.push_back(pre);
				sum+=pre;
				pc=i;
			}
		}
		cout<<sum<<endl;
		printf("%d",ret[0]);
		for(int i=1; i<ret.size(); i++)
			printf(" %d",ret[i]);
		puts("");
	}
	return 0;
}
