#include <cstdio>
#include <vector>

using namespace std;

class Solution {

    vector<int> dp[2];
    vector<int> p;
    const int static inf = 0x3fffffff;

public:
    int dfs(int now,int buy) {
        if (dp[buy][now] != inf) {
            return dp[buy][now];
        }
        if (now == p.size()) {
            return dp[buy][now] = 0;
        }
        int ret = 0;
        if (buy == 0) {
            ret = max(ret,dfs(now+1,1)-p[now]);
        }
        if (buy == 1) {
            ret = max(ret,dfs(now+1,0)+p[now]);
        }
        ret = max(ret,dfs(now+1,buy));
        return dp[buy][now]=ret;
    }

    int maxProfit(vector<int>& prices) {
        p = prices;
        for (int j=0; j<2; j++) {
            dp[j].resize(prices.size()+1);
            for (int i=0; i<=prices.size(); i++) {
                dp[j][i]=inf;
            }
        }
        return dfs(0,0);
    }
};

int main() {
    Solution s;
    vector<int> tp;
    tp.push_back(1);
    tp.push_back(2);
    printf("%d\n",s.maxProfit(tp));
    return 0;
}
