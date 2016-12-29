#include <cstdio>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > dp;

    int dfs(vector<int> &prices, int d, int st) {
        if (dp[d][st] >= 0) {
            return dp[d][st];
        }
        if (d == prices.size()) {
            return dp[d][st] = 0;
        }
        if (st == 2) {
            dp[d][st] = dfs(prices, d+1, 0);
            return dp[d][st];
        }
        int ret = dfs(prices, d+1, st);
        if (st == 1) {
            ret = max(ret, dfs(prices, d+1, 2) + prices[d]);
        } else {
            ret = max(ret, dfs(prices, d+1, 1) - prices[d]);
        }
        return dp[d][st] = ret;
    }

    int maxProfit(vector<int> &prices) {
        dp.clear();
        for (int i=0; i<prices.size()+1; i++) {
            vector<int> cur;
            cur.push_back(-1);
            cur.push_back(-1);
            cur.push_back(-1);
            dp.push_back(cur);
        }
        return dfs(prices, 0, 0);
    }
};

int main() {
    vector<int> prices;
    prices.push_back(1);
    prices.push_back(2);
    prices.push_back(3);
    prices.push_back(0);
    prices.push_back(2);
    Solution s;
    printf("%d\n", s.maxProfit(prices));
    return 0;
}
