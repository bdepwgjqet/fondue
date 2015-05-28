#include <cstdio>
#include <vector>

using namespace std;

class Solution {

    int dfs(int pos, int val, int pv, vector<int> &ans) {
        if (pos == -1) {
            ans.push_back(val);
            return 0;
        }
        int now = pv & (1<<pos);
        pv = dfs(pos-1,val|now,pv,ans);
        now = now^(1<<pos);
        pv = dfs(pos-1,val|now,pv,ans);
        return pv|now;
    }
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        ans.clear();
        dfs(n-1,0,0,ans);
        return ans;
    }
};

int main() {
    Solution s;
    s.grayCode(4);
    return 0;
}
