#include <cstdio>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int B(int i) {
        return 1<<i;
    }

    int findMaximumXOR(vector<int>& nums) {
        int mask = 0;
        int ans = 0;
        set<int> st;
        for (int c=30; c>=0; c--) {
            mask |= B(c);
            st.clear();
            for (int i=0; i<nums.size(); i++) {
                st.insert(nums[i]&mask);
            }
            int mx = ans | B(c);
            for (set<int>::iterator it = st.begin(); it != st.end(); it++) {
                int now = *it;
                if (st.count(mx^now)>0) {
                    ans = mx;
                    break;
                }
            }
        }
        return ans;
    }
};

int main (){
    Solution s;
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(10);
    nums.push_back(5);
    nums.push_back(25);
    nums.push_back(2);
    nums.push_back(8);
    printf("%d\n",s.findMaximumXOR(nums));
    return 0;
}
