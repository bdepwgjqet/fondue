#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    vector<int> bucket[2];
    const static int inf = 0x3fffffff;
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) {
            return 0;
        }
        int mx = nums[0],mi = nums[0];
        for (int i=0; i<nums.size(); i++) {
            mx = max(nums[i],mx);
            mi = min(nums[i],mi);
        }
        int bl = (mx-mi+nums.size()-2)/(nums.size()-1);
        int bc = (mx-mi)/bl+1;
        for (int i=0; i<2; i++) {
            bucket[i].resize(bc);
        }
        for (int i=0; i<bc; i++) {
            bucket[0][i] = inf;
            bucket[1][i] = -1;
        }
        for (int i=0; i<nums.size(); i++) {
            int now = (nums[i]-mi)/bl;
            bucket[0][now] = min(bucket[0][now],nums[i]);
            bucket[1][now] = max(bucket[1][now],nums[i]);
        }
        int ans = 0,pre = -1;
        for (int i=0; i<bc; i++) {
            //printf("%d %d->\n",bucket[0][i],bucket[1][i]);
            if (bucket[1][i] != -1) {
                if (pre != -1) {
                    ans = max(ans,bucket[0][i]-bucket[1][pre]);
                }
                pre = i;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    int a[] = {1,1,1,1,1,5,5,5,5,5};
    vector<int> v;
    for (int i=0; i<10; i++) {
        v.push_back(a[i]);
    }
    printf("%d\n",s.maximumGap(v));
    return 0;
}
