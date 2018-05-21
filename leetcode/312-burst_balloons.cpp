#include <vector>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> full_nums;
    const static int N = 510;
    int dp[N][N];

	int dfs(int l, int r) {
		if (dp[l][r] != -1) {
			return dp[l][r];
        }
		if (l + 1 == r) {
			return dp[l][r] = 0;
		}
		int res = 0;
		for (int i=l+1; i<r; i++) {
			int cur_val = full_nums[l]*full_nums[i]*full_nums[r];
			int left_seg = dfs(l, i);
			int right_seg = dfs(i, r);
			res = max(res, cur_val + left_seg + right_seg);
		}
		return dp[l][r] = res;
    }

    int maxCoins(vector<int>& nums) {
        full_nums.clear();
        full_nums.push_back(1);
        memset(dp, -1, sizeof(dp));
        for(int i=0; i<nums.size(); i++) {
            full_nums.push_back(nums[i]);
        }
        full_nums.push_back(1);
        return dfs(0, full_nums.size()-1);
    }	
};

int main() {
    Solution s;
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(5);
    nums.push_back(8);
    printf("%d\n", s.maxCoins(nums));
}

