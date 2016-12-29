#include <cstdio>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:

    set<int> st;

    bool isexist(set<int>::iterator it, int bar) {
        long long now = *it;
        long long ans = bar + 1LL;
        if (it != st.begin()) {
            it--;
            ans = min(ans, now - (*it));
            it++;
        }
        it++;
        if (it != st.end()) {
            ans = min(ans, (*it) - now);
        }
        return ans <= bar;
    }

    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {
        if (t < 0 || k<=0) {
            return false;
        }
        st.clear();
        for (int i=0; i<k+1 && i<nums.size(); i++) {
            if (st.count(nums[i])) {
                return true;
            }
            st.insert(nums[i]);
            set<int>::iterator it = st.find(nums[i]);
            if (isexist(it, t)) {
                return true;
            }
        }
        for (int i=k+1; i<nums.size(); i++) {
            set<int>::iterator it = st.find(nums[i-k-1]);
            st.erase(it);

            if (st.count(nums[i])) {
                return true;
            }

            st.insert(nums[i]);
            it = st.find(nums[i]);
            if (isexist(it, t)) {
                return true;
            }
        }
        return false;
    } 
};

int main() {
    Solution s;
    vector<int> vec;
    vec.push_back(-1);
    vec.push_back(2147483647);
    bool ans = s.containsNearbyAlmostDuplicate(vec,1,2147483647);
    if (ans) {
        puts("true");
    } else {
        puts("false");
    }
    return 0;
}
