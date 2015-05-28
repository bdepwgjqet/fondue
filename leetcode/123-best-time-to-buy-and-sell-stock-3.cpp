#include <cstdio>
#include <vector>

using namespace std;

class Solution {
    vector<int> dp[2][3];
    vector<int> p;
    const static int inf = 0x7fffffff;

    int dfs(int buy,int c,int now) {
        if (dp[buy][c][now] != inf) {
            return dp[buy][c][now]; 
        }
        if (now == p.size()) {
            return dp[buy][c][now] = 0;
        }
        int ans = 0;
        if (buy == 0 && c < 2) {
            ans = max(ans, dfs(1,c+1,now+1)-p[now]);
        }
        if (buy == 1) {
            ans = max(ans,dfs(0,c,now+1)+p[now]);
        }
        ans = max(ans,dfs(buy,c,now+1));
        return dp[buy][c][now] = ans;
    }

public:
    int maxProfit(vector<int>& prices) {
        p = prices;
        for (int i=0; i<2; i++) {
            for (int j=0; j<3; j++) {
                dp[i][j].resize(prices.size()+1);
                for(int k=0; k<prices.size()+1; k++) {
                    dp[i][j][k] = inf;
                }
            }
        }
        return dfs(0,0,0);
    }
};

int main() {
    return 0;
}
