#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int> &nums) {
        int sum = 0;
        for (int i=0; i<nums.size(); i++) {
            sum += nums[i];
        }
        if (sum & 1) {
            return 0;
        }
        int maxn = 20010;
        int dp[20010];
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for (int i=0; i<nums.size(); i++) {
            for (int j=maxn-1; j>=nums[i]; j--) {
                if (dp[j-nums[i]]) {
                    dp[j] = 1;
                }
            }
        }
        if (dp[sum>>1]) {
            return true;
        }
        return false;
    }
};

int main () {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(5);
    Solution s;
    if (s.canPartition(nums)) {
        puts("True");
    } else {
        puts("False");
    }
    return 0;
}
