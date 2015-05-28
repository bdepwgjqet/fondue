#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 0) {
            return 0;
        }
        int pm = prices[0];
        int ans = 0;
        for (int i=1; i<prices.size(); i++) {
            ans = max(ans,prices[i]-pm);
            pm = min(pm,prices[i]);
        }
        return ans;
    }
};

int main() {
    Solution s;
    return 0;
}
