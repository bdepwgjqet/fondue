#include <cstdio>
#include <map>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> mp;
        int ans = 0;
        for (int i=0; i<nums.size(); i++) {
            if(mp.count(nums[i]) > 0) {
                continue;
            }
            mp[nums[i]] = nums[i];
            int l = nums[i];
            int r = nums[i];
            if (mp.count(nums[i]-1) > 0) {
                l = mp[nums[i]-1];
            }
            if (mp.count(nums[i]+1) > 0) {
                r = mp[nums[i]+1];
            }
            mp[l] = r;
            mp[r] = l;
            ans = max(ans,r-l+1);
        }
        return ans;
    }
};

int main() {
    return 0;
}
