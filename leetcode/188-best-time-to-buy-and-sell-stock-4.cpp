#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {

public:
    vector<int> pl;
    vector<vector<int> > dp[2];
    int total;

    int dfs(int buy, int c, int day) {
        if (dp[buy][c][day]>=0) {
            return dp[buy][c][day];
        }
        if (c == total) {
            return dp[buy][c][day] = 0;
        }
        if (day == pl.size()) {
            return dp[buy][c][day] = 0;
        }
        int ans = 0;
        ans = max(ans,dfs(buy,c,day+1));
        if (buy) {
            ans = max(ans,dfs(0,c,day+1))+pl[day];
        } else {
            ans = max(ans,dfs(1,c+1,day+1))-pl[day];
        }
        return dp[buy][c][day] = ans;
    }

    int maxProfit(int k, vector<int>& prices) {
        k = min(k,((int)prices.size())>>1);
        total = k;
        pl = prices;
        dp[0].resize(k+1);
        dp[1].resize(k+1);
        for (int i=0; i<k+1; i++) {
            dp[0][i].resize(prices.size()+1,-1);
            dp[1][i].resize(prices.size()+1,-1);
        }
        return dfs(0,0,0);
    }
};

int main() {
    Solution s;
    return 0;
}
