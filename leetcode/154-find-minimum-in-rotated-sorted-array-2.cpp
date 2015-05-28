#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {

public:
    int findMin(vector<int> &nums) {
        int l = 0,r = nums.size()-1;
        while(l < r && nums[l] >= nums[r]) {
            int m = (l+r) >> 1;
            if (nums[m] > nums[l]) {
                l = m + 1;
            } else if (nums[m] < nums[l]) {
                r = m;
            } else {
                if (l==m) {
                    return min(nums[l],nums[r]);
                }
                l = l+1;
            }
        }
        return nums[l];
    }
};

int main() {
    Solution s;
    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(3);
    printf("%d\n",s.findMin(v));
    return 0;
}
