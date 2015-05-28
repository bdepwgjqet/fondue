#include <cstdio>
#include <vector>

using namespace std;

class Solution {

vector<int> co;

public:
    int candy(vector<int>& ratings) {
	co.clear();
	for(int i=0; i<ratings.size(); i++) {
	    co.push_back(1);
	}
	for(int i=1; i<ratings.size(); i++) {
	    if(ratings[i] > ratings[i-1]) {
		co[i]=co[i-1]+1;
	    }
	}
	for(int i=ratings.size()-1; i>0; i--) {
	    if(ratings[i]<ratings[i-1] && co[i-1] <= co[i]) {
		co[i-1] = co[i]+1;
	    }
	}
	int ans = 0;
	for(int i=0; i<co.size(); i++) {
	    ans += co[i];
	}
	return ans;
    }
};

int main() {
    return 0;
}
