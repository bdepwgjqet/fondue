#include <cstdio>
#include <algorithm>
#include <vector>
#define N 1011

using namespace std;

int arr[N];

int cmp1(int a,int b){ return a<b; }
int cmp2(int a,int b){ return a>b; }

vector<int> odd;
vector<int> eve;
vector<int> ans;

int main() {
	int T;
	scanf("%d",&T);
	for(int ca=1; ca<=T; ca++) {
		printf("Case #%d:",ca);
		odd.clear();
		eve.clear();
		ans.clear();
		int n;
		scanf("%d",&n);
		for(int i=0; i<n; i++) {
			scanf("%d",&arr[i]);
			if(abs(arr[i])&1)
				odd.push_back(arr[i]);
			else
				eve.push_back(arr[i]);
		}
		sort(odd.begin(),odd.end(),cmp1);
		sort(eve.begin(),eve.end(),cmp2);
		int lo=0,le=0;
		for(int i=0; i<n; i++) {
			if(abs(arr[i])&1)
				ans.push_back(odd[lo++]);
			else
				ans.push_back(eve[le++]);
		}
		for(int i=0; i<ans.size(); i++) {
			printf(" %d",ans[i]); 
		}
		puts("");
	}
	return 0;
}
